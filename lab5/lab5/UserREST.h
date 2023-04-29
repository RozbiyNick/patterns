#pragma once
#include "RestAPI.h"
class UserREST :
    public RestAPI
{
    bool validateRequest(string& request) {
        // if request contains email
        return false;
    }
};

