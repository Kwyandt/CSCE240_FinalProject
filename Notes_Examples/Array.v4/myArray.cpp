#include "myArray.h"
#include <iostream>

using namespace std;

myArray::myArray() {
    setSize(10);
    data = new int[size];
    for (int i = 0; i < size; i++) {
        setData(i, 0);
    }
}

myArray::myArray(int _size, int value) {
    setSize(_size);
    data = new int[size];
    for (int i = 0; i < size; i++) {
        setData(i, value);
    }
}

myArray::myArray(const myArray &anArray) {
    setSize(anArray.getSize());
    data = new int[size];
    for (int i = 0; i < size; i++) {
        setData(i, anArray.getData(i));
    }
}

myArray::~myArray() {
    delete[] data;
    //dtor
}

void myArray::append(const myArray &rhs) {
    if (rhs.getSize() > 0) {
        int *temp = new int[getSize() + rhs.getSize()];
        for (int i = 0; i < getSize(); i++) {
            temp[i] = getData(i);
        }
        for (int i = 0; i < rhs.getSize(); i++) {
            temp[i + getSize()] = rhs.getData(i);
        }
        setSize(getSize() + rhs.getSize());
        delete[] data;
        data = temp;
    }
}

bool myArray::equalsequals(const myArray &rhs) const {
    bool result(true);
    if (getSize() == rhs.getSize()) {
        for (int i = 0; i < getSize(); i++) {
            if (getData(i) != rhs.getData(i)) {
                result = false;
            }
        }
    } else { result = false; }
    return result;
}


void myArray::print() const {
    for (int i = 0; i < getSize(); i++)
        cout << data[i] << " ";
    cout << endl;
}

int myArray::getSize() const {
    return size;
}

int myArray::getData(int index) const {
    if (index < getSize()) {
        return (data[index]);
    } else {
        cout << "Array out of bound error";
        exit(1);
    }
}

void myArray::setData(int index, int value) {
    if (index < getSize()) {
        data[index] = value;
    } else {
        cout << "Array out of bound error";
    }
}

void myArray::setSize(int _size) {
    size = _size;
}

const myArray myArray::operator+(const myArray &rhs) const {
    myArray temp(getSize() + rhs.getSize());
    for (int i = 0; i < getSize(); i++) {
        temp.setData(i, getData(i));
    }
    for (int i = 0; i < rhs.getSize(); i++) {
        temp.setData(i + getSize(), rhs.getData(i));
    }
    return temp;
}

const myArray myArray::operator=(const myArray &rhs) {
    delete[] data;
    setSize(rhs.getSize());
    data = new int[size];
    for (int i = 0; i < size; i++) {
        setData(i, rhs.getData(i));
    }
    return *this;
}

const myArray myArray::operator-() const {
    myArray temp(*this);
    for (int i = 0; i < getSize(); i++) {
        temp[i] = -temp[i];
    }
    return temp;
}

bool myArray::operator==(const myArray &rhs) const {
    bool result(true);
    if (getSize() == rhs.getSize()) {
        for (int i = 0; i < getSize(); i++) {
            if (getData(i) != rhs.getData(i)) {
                result = false;
            }
        }
    } else { result = false; }
    return result;
}

int myArray::operator[](int index) const {
    if (index < getSize()) {
        return (data[index]);
    } else {
        cout << "Array out of bound error";
        exit(1);
    }
}

int & myArray::operator[](int index) {
        if (index < getSize()) {
            return data[index];
        } else {
            cout << "Array out of bound error";
        }
}

ostream& operator<<(ostream &os, const myArray &dt) {
    os << dt.size << " ";
    return os;
}

istream& operator>>(istream &is, const myArray &dt) {
    is >> dt.getData(0)>> dt.getSize();
    return is;
}