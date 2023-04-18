#pragma once
template<class T> class Iterator abstract
{
public:
	virtual T getNext() = 0;
	virtual bool hasMore() = 0;
};

