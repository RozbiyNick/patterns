// lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Trip.h"
#include "TripCollection.h"


int main()
{
    vector<string> cities = { "Kharkiv", "Kherson", "Kyiv", "Odessa", "Lviv" };
    auto trips = TripCollection(cities);
    auto navigator = Navigator(&trips);
    auto user = User(&trips);
    auto guide = Guide(&trips);

    auto nIterator = trips.getNavigatorIterator(navigator);
    cout << "Navigator recommendations: \n";
    while (nIterator.hasMore())
    {
        cout << nIterator.getNext().title << '\n';
    }
}


