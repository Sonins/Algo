#include <array>
#include <cstring>
#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#if __WIN32 || __WIN64
#define PATHSEP "\\"
#else
#define PATHSEP ''
#endif

/**
 * Print what problem in boj.kr should be solved next.
 * file where problem to be solved is stored : problemList
*/

using namespace std;

/**
 * getStdoutComand(const char*) :
 * get string result from linux shell command (cmd)
 * using popen to get char * type result.
 * return string type into which char * type is converted
*/

string getStdoutCommand(const char* cmd) {
    string data;
    FILE* fp;
    array<char, 256> buffer;
    unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw runtime_error("popen_failed");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
        data += buffer.data();
    return data;
}

/** 
 * getCurrentWorkingDir :
 * Return path of directory that contain this code file.
 * Reason for this is because I put problemList in same directory as this code file.
 */

string getCurrentDir(const char* filepath) {
    string dirpath = filepath;
    #ifdef __WIN32 || __WIN64
    char sep = '\\';
    #else
    char sep = '/';
    #endif
    size_t i = dirpath.rfind(sep, dirpath.length());
    if (i != string::npos)
        return dirpath.substr(0, i);
    return "";
}

// Return string that contain data of file whose path is filepath.
string getFileData(string filepath) {
    unique_ptr<FILE, decltype(&fclose)> fp(fopen("C:\\Users\\gmlrh\\Desktop\\Son\\Algo\\BOJ\\problemList", "r"), fclose);
    array<char, 256> buffer;
    if (!fp) {
        throw runtime_error("fopen(problemList)_failed");
    }
    string fdata;
    
    while (fgets(buffer.data(), buffer.size(), fp.get()) != nullptr)
        fdata += buffer.data();
    return fdata;
}

int main(int argc, const char* argv[]) {
    // Getting current Directory
    string CurrentPath = getCurrentDir(argv[0]);

    // Parsing file(problemList) data into string filedata.
    string listPath = CurrentPath + PATHSEP + "problemList";
    string filedata = getFileData(listPath);

    // Tokenizing file data by '\n' to processing data line by line.
    string token;
    map<int, bool> is_solved;
    vector<int> problemlist;
    vector<pair<string, int> > category;
    bool is_first_problem = false;
    istringstream iss(filedata);

    while (getline(iss, token, '\n')) {
        if (token[0] == '\"' || token[0] == '\n')
            // Ignore title and blank line.
            continue;
        if (token[0] == '#') {
            category.push_back(make_pair(token, 0));
            is_first_problem = true;
            continue;
        }
        istringstream subiss(token);
        while (getline(subiss, token, ',')) {
            if (is_first_problem) {
                category[category.size() - 1].second = stoi(token.c_str());
                is_first_problem = false;
            }
            problemlist.push_back(stoi(token.c_str()));
            is_solved.insert(make_pair(stoi(token.c_str()), false));
        }
    }

    /**
     * Mark solved problem using directory explore command
     * (window : dir, linux : ls)
     * The reason ls can be used in this job is
     * I store folder name by problem number that I solved.
    */

    #ifdef __linux__
    string option = "-I \"next*\" -I \"*.out\" -I \"*.cpp\" -I \"problemList\" -I \"*.sh\"";
    string cmd = "ls " + CurrentPath + " " + option;
    #elif __WIN32 || __WIN64
    string option;
    string cmd = "dir /B /AD " + CurrentPath;
    #endif
    string ls_result = getStdoutCommand(cmd.c_str());
    string problem;
    size_t pos;
    char _delimiter = '\n';
    while ((pos = ls_result.find(_delimiter)) != string::npos) {
        problem = ls_result.substr(0, pos);
        is_solved.find(stoi(problem.c_str()))->second = true;
        ls_result.erase(0, pos + sizeof(_delimiter));
    }

    // print
    string cate;
    string browser;
    size_t index = 0;
    for (int i = 0; i < problemlist.size(); i++) {
        if (problemlist[i] == category[index].second) {
            cate = category[index++].first;
        }
        if (!(is_solved.find(problemlist[i])->second)) {
            cout << cate << endl;
            cout << problemlist[i] << endl;
            cmd = "mkdir " + CurrentPath + PATHSEP + to_string(problemlist[i]);
            system(cmd.c_str());
            #ifdef __linux__
            cmd = "touch " + CurrentPath + to_string(problemlist[i]) + "/code.cpp";
            #elif __WIN32 || __WIN64
            cmd = "type NUL > " + CurrentPath + PATHSEP + to_string(problemlist[i]) + "\\code.cpp";
            #endif
            system(cmd.c_str());
            if (argv[1] != NULL) {
                option = argv[1];
                if (option == "-v" || option == "--vscode") {
                    cmd = "code " + to_string(problemlist[i]) + "/code.cpp";
                    system(cmd.c_str());
                }
            }
            // opening url to next problem using web browser.
            #ifdef __linux__
            cmd = "xdg-open http://boj.kr/" + to_string(problemlist[i]) + " &";
            #elif __WIN32 || __WIN64
            cmd = "explorer \"http://boj.kr/" + to_string(problemlist[i]) + "\"";
            #endif
            system(cmd.c_str());
            break;
        }
    }

    return 0;
}
