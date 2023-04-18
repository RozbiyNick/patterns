#pragma once
#include "TripCollection.h"
#include <vector>
class Guide
{
public:
	TripCollection* collection;
	
	Guide(TripCollection* collection) {
		this->collection = collection;
	}

	vector<int> getRecommendations() {
		auto rating = vector<int>(this->collection->trips.size(), 0);
		for (int i = 0; i < rating.size(); i++) {
			rating[i] = i % 5;
		}
		return rating;
	}
};

