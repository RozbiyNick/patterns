#pragma once
#include "Company.h"
#include "Department.h"
#include <iostream>

using namespace std;


class Visitor
{
public:
	void doForCompany(Company* company);
	void doForDepartment(Department* department);
};

