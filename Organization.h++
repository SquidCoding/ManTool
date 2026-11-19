//Copyright Ethan Nichols, 2026
#ifndef ORGANIZATION_H_
#define ORGANIZATION_H_

#include<string>
using std::string;
#include<vector>
using std::vector;
#include"Employee.h++"
#include"Department.h++"

namespace ManTool {
class Organization {
    public:
        explicit Organization(string orgName, int est, string orgDescr);

        string GetOrgName() { return OrgName_; }
        int GetEST() { return EST_; }
        string GetOrgDescr() { return OrgDescr_; }

        void SetOrgName(string orgName);
        void SetEST(int est);
        void SetOrgDescr(string orgDescr);

        void PrintOrgTree(bool DeptLvl = false);
        void ExportMembersToTSV(bool DeptLvl = false);
        
        void SearchThrough(int id);
        void SearchThrough(string fName, string lName);
        void SearchThrough(string jobTitle);
        void SearchThrough(int payType);

        void AddDept(ManTool::Department& d);
        void AddMem(ManTool::Employee& e);

        Organization ImportOrg(string filePath);
    private:
        string OrgName_;
        int EST_;
        string OrgDescr_;
        vector<Employee> MemList_;
        vector<Department> DeptList_;
};

} // end namespace ManTool

#endif // end ORGANIZATION_H_