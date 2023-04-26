#include <iostream>
#include "DeliveryContext.h"
#include "DeliveryDeliveryStrategy.h"
#include "DeliveryStrategy.h"
#include "OtherDeliveryProviderServiceStrategy.h"
#include "PickupDeliveryStrategy.h"
#include "PriceList.h"

using namespace std;

int main()
{
    double longitude = 10, latitude = 10;

    auto context = DeliveryContext();

    auto pickupStrategy = new PickupDeliveryStrategy();
    context.setStrategy(pickupStrategy);
    cout << "Pickup price is: \t" << context.calculatePrice(longitude, latitude) << '\n';

    auto deliveryStrategy = new DeliveryDeliveryStrategy();
    context.setStrategy(deliveryStrategy);
    cout << "Delivery price is: \t" << context.calculatePrice(longitude, latitude) << '\n';

    auto otherStrategy = new OtherDeliveryProviderServiceStrategy();
    context.setStrategy(otherStrategy);
    cout << "Other delivery price is: \t" << context.calculatePrice(longitude, latitude) << '\n';
}

