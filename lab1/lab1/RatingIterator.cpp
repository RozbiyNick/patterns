#include "RatingIterator.h"
#include <algorithm> 
#include <vector>

using namespace std;

RatingIterator::RatingIterator(TripCollection* collection, vector<int>& rating): collection(collection)
{
    this->collection = collection;
    this->rating = rating;
    this->sortedIndices = vector<int>(rating.size(), 0);
    for (int i = 0; i < rating.size(); i++) {
        this->sortedIndices[i] = i;
    }
    sort(this->sortedIndices.begin(), this->sortedIndices.end(), [rating](int i1, int i2) {return rating[i1] < rating[i2]; });
    this->currentPosition = -1;
}

Trip RatingIterator::getNext()
{
    if (this->hasMore()) {
        this->currentPosition++;
        return this->collection->trips[this->sortedIndices[this->currentPosition]];
    }
}

bool RatingIterator::hasMore()
{
    if (this->currentPosition < this->rating.size() - 1)
        return true;
    else
        return false;
}
