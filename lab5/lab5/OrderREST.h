#pragma once
#include "RestAPI.h"
class OrderREST :
    public RestAPI
{
    string formResponse(bool valSuccess, bool execSuccess, string& request) {
        // form json
        string code = "200";
        string status = "Success";
        string jsonResponse = "{}";
        return code + "," + status + "," + jsonResponse;
    }
};

