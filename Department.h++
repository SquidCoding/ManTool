//Copyright Ethan Nichols, 2026
#ifndef DEPARTMENT_H_
#define DEPARTMENT_H_

#include<string>
using std::string;

namespace ManTool {
class Department {
    public:
        explicit Department(string deptName, string deptRole);

        string GetDeptName() { return DeptName_; }
        string GetDeptRole() { return DeptRole_; }

        void SetDeptInfo(string deptName, string deptRole);
    private:
        string DeptName_;
        string DeptRole_;
};

} //end namespace ManTool

#endif //end DEPARTMENT_H_