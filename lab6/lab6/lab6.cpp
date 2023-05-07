#include <iostream>
#include "Employee.h"
#include "ReportVisitor.h"
#include <vector>

using namespace std;

int main()
{
    Employee emp1("Senior", 3000), emp2("Junior", 1000), emp3("Senior", 3500), emp4("Junior", 1500);
    vector<Employee> dep1Employees{ emp1, emp2 }, dep2Employees{ emp3, emp4 };
    Department dep1(dep1Employees), dep2(dep2Employees);
    vector<Department> companyDepartments{ dep1, dep2 };
    Company company(companyDepartments);
    
    ReportVisitor* reportVisitor;
    
    dep1.accept(reportVisitor);
    company.accept(reportVisitor);
}
