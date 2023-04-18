#pragma once
#include "Iterator.h"
#include "Trip.h"
#include "TripCollection.h"

class RatingIterator: public Iterator<Trip>
{
protected:
	TripCollection* collection;
	int currentPosition;
	vector<int> rating;
	vector<int> sortedIndices;
public:
	RatingIterator() {};
	RatingIterator(TripCollection* collection, vector<int>& rating);
	Trip getNext() override;
	bool hasMore() override;
};

