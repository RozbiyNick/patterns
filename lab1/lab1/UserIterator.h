#pragma once
#include "RatingIterator.h"
#include "User.h"
#include "TripCollection.h"

class UserIterator : public RatingIterator
{
public:
	UserIterator(TripCollection* coll, User& user) {
		auto rating = user.getPreferences();
		RatingIterator(coll, rating);
	}
};

