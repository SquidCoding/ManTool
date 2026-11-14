// Copyright Ethan Nichols, 2026
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<string>
using std::string;


namespace ManTool {
class Employee {
    public:
        explicit Employee(string org, string dep = "N/A", string fName = "John",
                          string lName_ = "Doe", string jTitle = "N/A", int pType = 1, double pAmmt = 0.00,
                          int id, int supId);
  
    
        string GetEmployeeName(int option);
        string GetLocation(int option);
        string GetJobInfo(int option);

        void SetEmployeeName(string fName, string lName);
        void SetLocation(string OrgName, string DepName);
        void SetJobInfo(string title, int paytype, double payAmmt);

        void PrintProfile(Employee& e, bool toFile);
    private:
        string OrgName_;
        string DepName_; 
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