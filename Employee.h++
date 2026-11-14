// Copyright Ethan Nichols, 2026
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include<string>
using std::string;
#include"Organization.h++"

namespace ManTool {
class Employee {
    public:
        explicit Employee(ManTool::Organization& currOrgObj, string dept = "N/A", string fName = "John",
                          string lName = "Doe", string jTitle = "N/A", int pType = 1, double pAmmt = 0.00,
                          int id = 0, int supId = -1);
  
    
        string GetEmployeeInfo(int option = 1);
        string GetLocation() { return OrgName_ + " | " + DeptName_; };
        string GetJobInfo(int option = 1);

        void SetEmployeeInfo(string fName, string lName, int id);
        void SetLocation(string OrgName, string DeptName);
        void SetJobInfo(string title, int paytype, double payAmmt, int supId);

        void PrintFullProfile(Employee& e, bool toFile = false);
    private:
        string OrgName_;
        string DeptName_; 
        string fName_;
        string lName_;
        string Title_;
        int PayType_;
        double PayAmmt_;
        int ID_;
        int SuperiorID_;
};

} // end of namespace ManTool

#endif // end EMPLOYEE_H_