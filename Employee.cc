// Copyright Ethan Nichols, 2026
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<string>
using std::string;
using std::to_string;
#include"Employee.h++"
#include"Organization.h++"

namespace ManTool {
Employee::Employee(ManTool::Organization& currOrgObj, string dept, string fName, string lName, string jTitle, int pType, double pAmmt, int id, int supId) {
    Employee::SetEmployeeInfo(fName, lName, id);
    Employee::SetLocation(currOrgObj.GetOrgName(), dept);
    Employee::SetJobInfo(jTitle, pType, pAmmt, supId);
}

string Employee::GetEmployeeInfo(int option) {
    switch(option) {
        case 0:
            return to_string(ID_) + "_" + fName_ + "_" +lName_;
            break;
        case 1:
            return lName_ + ", " + fName_ + " | " + to_string(ID_);
            break;
        case 2:
            return lName_ + ", " + fName_;
            break;
        case 3:
            return fName_ + " " + lName_;
            break;
    }
}

string Employee::GetJobInfo(int option) {
    switch(option) {
        case 1:
            return Title_ + " | Pay Structure: " + (PayType_ == 0 ? "Salary" : "Hourly") + " | " + (PayType_ == 0 ? "Annual Pay: " : "Hourly Rate: ") + std::to_string(PayAmmt_);
            break;
        case 2:
            return Title_ + " | Pay Structure: " + (PayType_ == 0 ? "Salary" : "Hourly");
            break;
        case 3:
            return Title_;
            break;
    }
}

void Employee::SetEmployeeInfo(string fName, string lName, int id) {
    fName_ = fName;
    lName_ = lName;
    ID_ = id;
}

void Employee::SetLocation(string org, string dept) {
    OrgName_ = org;
    DeptName_ = dept;
}

void Employee::SetJobInfo(string jTitle, int pType, double pAmmt, int supID) {
    Title_ = jTitle;
    PayType_ = pType;
    PayAmmt_ = pAmmt;
    SuperiorID_ = supID;
}

} // end namespace ManTool