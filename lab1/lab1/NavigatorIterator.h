#pragma once
#include "RatingIterator.h"
#include "Navigator.h"
#include "TripCollection.h"

class NavigatorIterator : public RatingIterator
{
public:
	NavigatorIterator(TripCollection* coll, Navigator& navigator) {
		auto rating = navigator.getRecommendations();
		RatingIterator(coll, rating);
	}
};

