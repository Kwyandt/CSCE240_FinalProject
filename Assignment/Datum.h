#ifndef DATUM_H
#define DATUM_H
#include <cstdlib>


/**
 * @author Caleb Henry and Katelyn Wyandt
 * 
 * @breif header file for datum class
 * 
 */

class Datum
{
    public:
        //default
        Datum();
        //alternate constructor
        Datum(int value); 
        //copy constructo
        Datum(const Datum&);
        //deconstructor
        ~Datum();

        int getData();
        int& getData(int);
        void setData(int);

        void setNext(Datum &);
        Datum * getNext();

    private:
        int data;
        Datum *next;
};

#endif // DATUM_H
