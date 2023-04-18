#pragma once
#include "TripCollection.h"
#include <vector>

class Navigator
{
public:
	TripCollection* collection;

	Navigator(TripCollection* collection) {
		this->collection = collection;
	}

	vector<int> getRecommendations() {
		auto rating = vector<int>(this->collection->trips.size(), 0);
		for (int i = 0; i < rating.size(); i++) {
			rating[i] = (i + 13) % 5;
		}
		return rating;
	}
};

