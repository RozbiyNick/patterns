#pragma once
#include "RatingIterator.h"
#include "Guide.h"
#include "TripCollection.h"

class GuideIterator : public RatingIterator
{
public:
	GuideIterator(TripCollection* coll, Guide& guide) {
		auto rating = guide.getRecommendations();
		RatingIterator(coll, rating);
	}
};

