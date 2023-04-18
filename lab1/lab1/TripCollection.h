#pragma once
#include "Trip.h"
#include <vector>
#include <string>
#include "Navigator.h"
#include "User.h"
#include "Guide.h"
#include "NavigatorIterator.h"
#include "GuideIterator.h"
#include "UserIterator.h"

class TripCollection
{
public:
	vector<Trip> trips;
	Trip& operator[] (int);

	TripCollection() { this->trips = vector<Trip>(); };
	TripCollection(vector<string>& tripNames);

	NavigatorIterator getNavigatorIterator(Navigator& navigator);
	GuideIterator getGuideIterator(Guide& navigator);
	UserIterator getUserIterator(User& navigator);
};

