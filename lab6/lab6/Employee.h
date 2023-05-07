#pragma once
#include <vector>
#include <string>

using namespace std;
class Employee
{
	string position;
	float salary;
public:
	Employee(string position, float salary) {
		this->position = position;
		this->salary = salary;
	}

	string getPosition() {
		return this->position;
	}

	float getSalary() {
		return this->salary;
	}
};

