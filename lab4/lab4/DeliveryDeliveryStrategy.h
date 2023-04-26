#pragma once
#include "DeliveryStrategy.h"
#include "PriceList.h"

class DeliveryDeliveryStrategy :
    public DeliveryStrategy
{
public:
    DeliveryDeliveryStrategy() {

    }

    double calculatePrice(double longitude, double latitude) override {
        return PriceList::deliveryPrice;
    }
};

