#pragma once
#include <vector>
#include <string>
#include "Department.h"
#include "Visitor.h"

using namespace std;
class Company
{
	vector<Department> departments;
public:
	Company(vector<Department>& departments) {
		this->departments = departments;
	}

	vector<Department>& getDepartments() {
		return this->departments;
	}

	void accept(Visitor* visitor) {
		visitor->doForCompany(this);
	}
};

