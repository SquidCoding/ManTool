//Copyright Ethan Nichols, 2026
#ifndef MANTOOLFUNCS_H_
#define MANTOOLFUNCS_H_

#include<filesystem>
namespace fs = std::filesystem;
#include"Organization.h++"
using ManTool::Organization;
#include"Employee.h++"
using ManTool::Employee;

fs::path GetEXELoc();
void PrintFullProfile(Employee& e, bool toFile);

#endif // end MANTOOLFUNCS_H_