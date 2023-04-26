#pragma once
#include "DeliveryStrategy.h"

class DeliveryContext
{
	DeliveryStrategy* strategy;
public:
	DeliveryContext() {
		this->strategy = nullptr;
	}

	void setStrategy(DeliveryStrategy* strategy) {
		if(this->strategy != nullptr)
			delete this->strategy;
		this->strategy = strategy;
	}

	double calculatePrice(double longitude, double latitude) {
		return this->strategy->calculatePrice(longitude, latitude);
	}
};

