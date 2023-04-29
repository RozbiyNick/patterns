#pragma once
#include "RestAPI.h"
class ItemREST :
    public RestAPI
{
protected:
    void handleValidationError() {
        //send message to admin
    }
};

