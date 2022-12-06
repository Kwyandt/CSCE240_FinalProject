#include <iostream>
#include "Datum.h"

using namespace std;

//default
Datum::Datum() : data(0.0), next(NULL) {

}
//alternate constructor
Datum:: Datum(int value) : data(value), next(NULL) {

} 
//copy constructo
Datum::Datum(const Datum &rhs) : data(rhs.data), next(rhs.next) {

}
//deconstructor - is this right? no clue  :)
Datum::~Datum() {
    delete [] next;
}

int Datum::getData() const {
    return data;
}
void Datum::setData(int value) {
    data = value;
}

void Datum::setNext(Datum &rhs) {
    next = &rhs;
}

Datum * Datum::getNext() {
    return next;
}
