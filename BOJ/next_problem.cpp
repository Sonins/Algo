#include <iostream>
#include <string>
#include <stdexcept>
#include <array>
#include <memory>

using namespace std;

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
    string cmd;
    cmd = "pwd";
    string CurrentPath = getStdoutCommand(cmd.c_str());
    cmd = "ls " + CurrentPath; 

    string ls_result = getStdoutCommand(cmd.c_str());
    char _delimiter = '\n';
    string problem;
    size_t pos;
    FILE* fp = fopen("problemList", "r");
    string buffer;
    vector<string> unsolved_problem;
    while (fscanf(fp, "%s,", &buffer) != false) {
	if (s[0] == "#" || s[0] == "\"") 
	    continue;
	unsolved_problem.push_back(buffer);
    }
    while ((pos = ls_result.find(_delimiter)) != string::npos) {
        problem = ls_result.substr(0, pos);
        ls_result.erase(0, pos + sizeof(_delimiter));
	
    }

    fclose(fp);

    return 0;
}
