#include <iostream>
#include "Datum.h"

using namespace std;

/**
 * @author Caleb Henry and Katelyn Wyandt
 * 
 * @brief functions for Datum class
 * 
 **/

/**
 * @brief default constructor for datum class
 * 
 * default values of 0.0 and NULL
 */
Datum::Datum() : data(0.0), next(NULL) {

}

/**
 * @brief alternate constructor for datum class
 * 
 * @param value integer value for datum
 * integer value of parameter and default null value
 */
Datum:: Datum(int value) : data(value), next(NULL) {

} 

/**
 * @brief copy constructor for datum class
 * 
 * @param rhs datum value for datum
 */
Datum::Datum(const Datum &rhs) : data(rhs.data), next(rhs.next) {

}

/**
 * @brief Destroy the Datum:: Datum object
 * 
 */
Datum::~Datum() {
    
}

/**
 * @brief getter for data variable
 * 
 * @return data variable
 */
int Datum::getData() {
    return data;
}

/**
 * @brief reference method getter for data variable
 * 
 * @param value dummy value to call method
 * @return int& data variable
 */
int& Datum::getData(int value) {
    return data;
}

/**
 * @brief setter method for datum
 * 
 * @param value data value being set for datum
 */
void Datum::setData(int value) {
    data = value;
}

/**
 * @brief setter for the next value
 * 
 * @param rhs datum being set as next datum
 */
void Datum::setNext(Datum &rhs) {
    next = &rhs;
}

/**
 * @brief getter for next value
 * 
 * @return returns next datum value
 */
Datum * Datum::getNext() {
    return next;
}
