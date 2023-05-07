#pragma once
#include "Visitor.h"
class ReportVisitor :
    public Visitor
{
public:
    ReportVisitor(){}

    void doForCompany(Company* company) {
        cout << "Department's report\n";
        for (auto& department : company->getDepartments()) {
            cout << "Company's report\n";
            for (auto& employee : department.getEmployees()) {
                cout << employee.getPosition() << " : " << employee.getSalary() << '\n';
            }
        }
    }

    void doForDepartment(Department* department) {
        cout << "Department's report\n";
        for (auto& employee : department->getEmployees()) {
            cout << employee.getPosition() << " : " << employee.getSalary() << '\n';
        }
    }
};

