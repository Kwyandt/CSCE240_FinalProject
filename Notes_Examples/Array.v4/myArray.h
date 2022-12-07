#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>

using namespace std;

class myArray {
	friend  ostream & operator<< (ostream &lhs, const myArray &rhs);
	friend  istream & operator>> (istream &lhs, const myArray &rhs);
public:
    myArray();

//    myArray(int);

    myArray(int, int=0);

    myArray(const myArray &);

    ~myArray();

    void print() const;

    void append(const myArray &rhs);
    bool equalsequals(const myArray &rhs) const;


    int getSize() const;

    int getData(int index) const;

    void setData(int index, int value);

    const myArray operator+(const myArray &rhs) const;
    const myArray operator=(const myArray &rhs);
    bool operator==(const myArray &rhs) const;
    int operator[](int index) const;
    int & operator[](int index);
    const myArray operator-() const;

private:
    int size;
    int *data;

    void setSize(int);
};

#endif // MYARRAY_H
