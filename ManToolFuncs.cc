//Copyright Ethan Nichols
#define _POSIX_C_SOURCE 200809L
#include<limits.h>

#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<fstream>
using std::ofstream;
using std::ifstream;
#include<filesystem>
namespace fs = std::filesystem;
using fs::path;
using fs::create_directory;
using fs::exists;
#include<system_error>
using std::error_code;
#include<exception>
using std::exception;
#include<stdexcept>
using std::runtime_error;
#include<string>
using std::string;
using std::to_string;
#include"Employee.h++"
#include"Organization.h++"

#ifdef _WIN64
    #include<Windows.h>
    #include<Shlwapi.h>
    #pragma comment(lib, "shlwapi.lib")
#else
    #include<unistd.h>
#endif

path GetEXELoc() {
    #ifdef _WIN64
        char buffer[MAX_PATH];
        DWORD length = GetModuleFileNameA(NULL, buffer, sizeof(buffer) - 1);
        if (length == 0) {
            return "";
        }
        PathRemoveFileSpecA(buffer);
    #else
        char buffer[PATH_MAX];
        ssize_t length = readlink("proc/self/exe", buffer, sizeof(buffer) - 1);
        if (length == -1) {
            return "";
        }
        buffer[length] = '\0';
    #endif

    return path(buffer).parent_path();
}

void  PrintFullProfile(ManTool::Employee& e, bool toFile) {
    if (toFile) {
        path ProfileFilePath = (GetEXELoc() /= "EmployeeProfiles");
        path EmployeeFilePath = ProfileFilePath /= (e.GetEmployeeInfo(0) + ".txt");
        error_code ec;
        bool dirCreated = create_directory(ProfileFilePath, ec);

        if(ec) {
            throw runtime_error("Failed To Create Directory");
        }

        ofstream EmployeeFile(EmployeeFilePath);

        if(EmployeeFile.is_open()) {
            EmployeeFile << e.GetLocation() << "\n"
                         << e.GetEmployeeInfo(1) << "\n"
                         << e.GetJobInfo(1) << endl;
        } else {
            throw runtime_error("Failed To Create Employee File");
        }
    } else {
        cout << e.GetLocation() << "\n";
        cout << e.GetEmployeeInfo(1) << "\n";
        cout << e.GetJobInfo(1);
        cout << endl;
    }
}