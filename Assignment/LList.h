#ifndef LLIST_H
#define LLIST_H
#include <cstdlib>
#include "Datum.h"


//does this need to call datum object//im confused abt how they connect
class LList {
    /* //overload operator<< method that prints all elements of the LList in one row, delimeter is spac
        //not sure if const is right or if this returns a string, generally unsure
        const LList operator<<(const LList &rhs);
        //overlaod operator >> method that will obtain a vlaue of stream to be appended to end of LList object
        const LList operator>>(const LList &lhs); */
    //friend ostream & operator<< (ostream &lhs, const LList &rhs);
	//friend istream & operator>> (istream &lhs, LList &rhs); 
    public:
        //default constructor
        LList();
        //alternate contrustor
        LList(int[], int size);
        //copy constructor //is the & in the right location?
        LList(const LList&);
        
        //intert method - need to check for the appropriate index , if out of bounts then add to begining or end on appropriate sides
        void insert (int index, int value);
        //remove method - remove item at index and return value of removes item - if out of bounds then remove forst or last element
        int remove(int index);
        //contains method
        bool contains(int value);
        //indexOf method - return index of the first occurance of the value
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
        //i think you neeeded like one by refernce and one not for this - return the value of the array at given index or set value at given index - return first or last if out of bounds
        int & operator[](int index);
        //overloaoperator== that returns true of two linked lists are identical and dalce if differenct        
        bool operator==(const LList &rhs) const;
        //getters and setters
        //not sure if this sets dataum or what exactly
        void setData(int data, int index);
        int getData(int index) const;
        Datum getHead() const;
        Datum getTail() const;

    private:
        int length;
        //is this supposed to be datum or int? a tad bit confused
        Datum *head;
        Datum *tail;

        void setSize(int size);
};

#endif // LLIST_H
