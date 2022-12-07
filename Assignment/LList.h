#ifndef LLIST_H
#define LLIST_H
#include <cstdlib>
#include "Datum.h"

#include <iostream>

using namespace std;

/**
 * @author Caleb Henry and Katelyn Wyandt
 * 
 * @breif header file for LList class
 * 
 */
class LList {
        friend ostream & operator<< (ostream &lhs, const LList &rhs);
        friend istream & operator>> (istream &lhs, LList &rhs);
    public:
        //default constructor
        LList();
        //alternate contrustor
        LList(int[], int size);
        //copy constructor //is the & in the right location?
        LList(const LList&);
        ~LList();
        
        //intert method
        void insert (int index, int value);
        //remove method
        int remove(int index);
        //contains method
        bool contains(int value);
        //indexOf method
        int indexOf(int value);
        //empty method
        bool isEmpty();
        //size method 
        int size() const;
        //clear method
        void clear();

        //operators
        //overload operator+ that will append two lists - cascade capable
        const LList operator+(const LList &rhs)const;
        //overload operator= that will assign content of lhs with rhs - cascade capable
        const LList operator=(const LList &rhs);
        //overload operator[] method that can be used on lhs or rhs of operator assignment
        int operator[](int index) const;
        int & operator[](int index);       
        bool operator==(const LList &rhs) const;

        //getters and setters
        void setData(int data, int index);
        int getData(int index) const;
        Datum getHead() const;
        Datum getTail() const;

    private:
        //size variable
        int length;
        //error variable
        int dummy = -1;

        //data
        Datum *head;
        Datum *tail;

        void setSize(int size);
};

#endif // LLIST_H
