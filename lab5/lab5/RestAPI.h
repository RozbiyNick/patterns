#pragma once
#include <string>
#include "RestEntity.h"

using namespace std;

class RestAPI
{
protected:
	RestEntity* find(string& request) {
		// find entity by request and return it
		return new RestEntity();
	};

	bool validateRequest(string& request) {
		//validate request
		return true;
	}

	string buildSaveRequest(string& updateRequest, RestEntity* entity) {
		// save entity
		return "save entity";
	}

	bool executeSaveRequest(string& request) {
		//execute request
		return true;
	}

	//hooks
	void beforeUpdate(RestEntity* entity);
	void afterUpdate(RestEntity* entity);
	void handleValidationError();
	void handleExecutionError();
	string formResponse(bool valSuccess, bool execSuccess, string& request) {
		if (valSuccess && execSuccess) {
			return "200, OK";
		}
		else {
			return "500, Internal Server Error";
		}
	};
public:

	RestAPI() {};

	// template method
	void const update(string request) {
		RestEntity* entity = find(request);
		beforeUpdate(entity);
		bool requestValidated = validateRequest(request), saveSuccessful=false;
		if (!requestValidated) {
			handleValidationError();
		}
		else {
			string saveRequest = buildSaveRequest(request, entity);
			saveSuccessful = executeSaveRequest(saveRequest);
			if (!saveSuccessful) {
				handleExecutionError();
			}
			else {
				afterUpdate(entity);
			}
		}
		string responseText = formResponse(requestValidated, saveSuccessful, request);
		// code to send response must be here
		// sendResponse(responseText, request)
	};
};

