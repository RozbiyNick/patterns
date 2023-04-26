#pragma once
class PriceList
{
public:
	static double pickupPrice;
	static double deliveryPrice;
};

double PriceList::pickupPrice = 0;
double PriceList::deliveryPrice = 10;

