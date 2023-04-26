#pragma once
#include "DeliveryStrategy.h"
class OtherDeliveryProviderServiceStrategy :
    public DeliveryStrategy
{
public:
    OtherDeliveryProviderServiceStrategy() {

    }

    double calculatePrice(double longitude, double latitude) override {
        // the call to the provider's API must be here
        return longitude + latitude;
    }
};

