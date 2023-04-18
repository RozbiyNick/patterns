#include "TripCollection.h"
#include "Trip.h"


Trip& TripCollection::operator[](int index)
{
    return this->trips[index];
}

TripCollection::TripCollection(vector<string>& tripNames)
{
    this->trips = vector<Trip>(tripNames.size());
    for (int i = 0; i < tripNames.size(); i++) {
        this->trips[i] = Trip(tripNames[i]);
    }
}

NavigatorIterator TripCollection::getNavigatorIterator(Navigator& navigator)
{
    return NavigatorIterator(this, navigator);
}

GuideIterator TripCollection::getGuideIterator(Guide& guide)
{
    return GuideIterator(this, guide);
}

UserIterator TripCollection::getUserIterator(User& user)
{
    return UserIterator(this, user);
}
