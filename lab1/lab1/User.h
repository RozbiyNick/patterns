#pragma once
#include "TripCollection.h"
#include <vector>
class User
{
public:
	TripCollection* collection;

	User(TripCollection* collection) {
		this->collection = collection;
	}

	vector<int> getPreferences() {
		auto rating = vector<int>(this->collection->trips.size(), 0);
		for (int i = 0; i < rating.size(); i++) {
			rating[i] = (i + 7) % 5;
		}
		return rating;
	}
};

