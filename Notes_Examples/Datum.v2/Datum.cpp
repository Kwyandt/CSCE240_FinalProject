#include <iostream>
#include "Datum.h"


using namespace std;

Datum::Datum()
{
    data = 0.0;
    next = NULL;
}

Datum::Datum(float value)
{
    data = value;
    next = NULL;
}

Datum::Datum(const Datum &rhs)
{
    data = rhs.data;
    next = rhs.next;
}

Datum::~Datum()
{
    //dtor
}

float Datum::getData() const
{
    return data;
}

void Datum::setData(float value)
{
    data = value;
}

void Datum::setNext(Datum &rhs)
{
    next = &rhs;
}

Datum * Datum::getNext() const
{
    return next;
}
