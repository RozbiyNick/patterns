#pragma once
#include <vector>
#include <string>
#include "Employee.h"
#include "Visitor.h"

using namespace std;
class Department
{
	vector<Employee> employees;
public:
	Department(vector<Employee>& employees) {
		this->employees = employees;
	}

	vector<Employee>& getEmployees() {
		return this->employees;
	}

	void accept(Visitor* visitor) {
		visitor->doForDepartment(this);
	}
};

