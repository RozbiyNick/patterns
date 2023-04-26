#pragma once
class DeliveryStrategy
{
public:
	virtual double calculatePrice(double lohgitude, double latitude) = 0;
};

