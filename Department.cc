//Copyright Ethan Nichols, 2026
#include<string>
using std::string;
#include<stdexcept>
using std::runtime_error;
#include"Department.h++"

namespace ManTool {
Department::Department(string deptName, string deptRole) {
    if (deptName == "" || deptRole == "") {
        throw runtime_error("Failed to create department: Empty dept. Name or Roll");
    }

    Department::SetDeptInfo(deptName, deptRole);
}

void Department::SetDeptInfo(string deptName, string deptRole) {
    DeptName_ = deptName;
    DeptRole_ = deptRole;
}

} //end namespace ManTool