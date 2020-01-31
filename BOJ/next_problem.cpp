#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <array>
#include <memory>
#include <map>
#include <vector>
#include <cstring>

/**
 * Print what problem in boj.kr should be solved next.
 * file where problem to be solved is stored : problemList
*/

#define ls_OPTION "-I \"*.out\" -I \"*.cpp\" -I \"problemList\" " 

using namespace std;


/**
 * getStdoutComand(const char*) :
 * get string result from linux shell command (cmd)
 * using popen to get char * type result.
 * return string type into which char * type is converted
*/

string getStdoutCommand(const char* cmd) {
    string data;
    FILE * fp;
    array<char, 256> buffer;
    unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw runtime_error("popen_failed");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
        data += buffer.data();
    return data;
}

int main(int argc, const char* argv[]) {
    
    // Getting current directory.
    string cmd;
    cmd = "pwd";
    string CurrentPath = getStdoutCommand(cmd.c_str());

    // Parsing file(problemList) data into string filedata.
    unique_ptr<FILE, decltype(&fclose)> fp(fopen("problemList", "r"), fclose);
    if (!fp) {
        throw runtime_error("fopen(problemList)_failed");
    }
    string filedata;
    array<char, 256> buffer;
    while (fgets(buffer.data(), buffer.size(), fp.get()) != nullptr)
        filedata += buffer.data();
    
    // Tokenizing file data by '\n' to processing data line by line.
    string token;
    map<int, bool> is_solved;
    vector<int> problemlist;
    vector< pair<string, int> > category;
    bool is_first_problem = false;
    istringstream iss(filedata);

    while(getline(iss, token, '\n')) {
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
     * Mark solved problem using 'ls' command.
     * The reason ls can be used in this job is
     * I store folder name by problem number that I solved.
    */
    
    string option = ls_OPTION;
    cmd = "ls " + option + CurrentPath;
    string ls_result = getStdoutCommand(cmd.c_str());
	string problem;
    size_t pos;
    char _delimiter = '\n';
    while ((pos = ls_result.find(_delimiter)) != string::npos) {
        problem = ls_result.substr(0, pos);
        is_solved.find(stoi(problem.c_str()))->second = true;
        ls_result.erase(0, pos + sizeof(_delimiter));
    }
    
    // The reason doing below is that there is some problem that I solved before making git reposit.
    for (int i = problemlist.size() - 1; i > 0; i--) {
        is_solved.find(problemlist[i - 1])->second |= is_solved.find(problemlist[i])->second;
    }
    
    // print
    string cate;
    size_t index = 0;
    for (int i = 0; i < problemlist.size(); i++) {
        if (problemlist[i] == category[index].second) {
            cate = category[index++].first;
        }
        if (!(is_solved.find(problemlist[i])->second)) {
            cout << cate << endl;
            cout << problemlist[i] << endl;
            cmd = "mkdir " + to_string(problemlist[i]);
            system(cmd.c_str());
            cmd = "touch " + to_string(problemlist[i]) + "/code.cpp";
            system(cmd.c_str());
            if (argv[1] != NULL) {
                option = argv[1];
                if (option == "-v" || option == "--vscode") {
                    cmd = "code " + to_string(problemlist[i]) + "/code.cpp";
                    system(cmd.c_str());
                }
            }
            break;
        }
    }
    

    return 0;
}
