#pragma once
#include <string>

using namespace std;

class RestEntity
{
public:
	RestEntity() {};
	RestEntity find(string& request);
};

