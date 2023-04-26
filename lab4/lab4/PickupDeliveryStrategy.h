#pragma once
#include "DeliveryStrategy.h"
#include "PriceList.h"


class PickupDeliveryStrategy :
    public DeliveryStrategy
{
public:
    PickupDeliveryStrategy() {

    }

    double calculatePrice(double longitude, double latitude) override {
        return PriceList::pickupPrice;
    }
};

