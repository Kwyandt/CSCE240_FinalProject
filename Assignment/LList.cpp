#include <iostream>
#include "LList.h"
#include "Datum.h"

using namespace std;

LList::LList(){
    head = tail = NULL;
}
LList::LList(int arr[], int size){
    for(int i=0; i<size; i++){
        insert(i, arr[i]);
    }
}
LList::LList(const LList& list){
    for(int i=0; i<list.size(); i++){
        insert(i, list.getData(i));
    }
}
        
void LList::insert (int index, int value){
    if(index <= 0){
        /* Datum *temp = head;
        Datum *newData;
        *newData = Datum(value);
        head = newData;
        head->setNext(*temp); */
        Datum *temp = head;
        *head = Datum(value);
        head->setNext(*temp->getNext());
    }
    else if(index >= length){
        Datum data(value);
        tail->setNext(data);
    }
    else{
        Datum *temp = head;
        Datum *next;
        for(int i = 0; i < index; i++){
            temp = temp->getNext();
        }
        next = temp->getNext();
        Datum data(value);
        temp->setNext(data);
        temp->getNext()->setNext(*next);
        length++;
    }
}
int LList::remove(int index){
    Datum *temp = head;
    for(int i = 0; i < index-1; i++){
        temp = temp->getNext();
    }
    temp->setNext(*temp->getNext()->getNext());
    length--;
}
bool LList::contains(int value){
    Datum *temp = head;
    for(int i = 0; i < size(); i++){
        if(temp->getData()==value){
            return true;
        }
        temp = temp->getNext();
    }
    return false;
}
int LList::indexOf(int value){
    Datum *temp = head;
    int index = 0;
    for(int i = 0; i < size(); i++){
        if(temp->getData()==value){
            return index;
        }
        temp = temp->getNext();
        index++;
    }
    return -1;
}
bool LList:: isEmpty(){
    if(head==NULL){
        return true;
    }
    return false;
}
int LList::size() const{
    return length;
}
void LList::clear(){
    head = tail = NULL;
}

const LList LList::operator+(const LList &rhs)const{
    LList newList(*this);
    Datum data =rhs.getHead();
    newList.getTail().setNext(data);
    newList.setSize(size()+rhs.size());
    return newList;
}
const LList LList::operator=(const LList &rhs){
    *head = rhs.getHead();
    *tail = rhs.getTail();
    setSize(rhs.size());
    return *this;
}
/*
Should overload the operator[] (int index) method that can be used in the lhs or rhs of an assignment operator. <br />
This method will either return the value of the array at the given index or set the value at a given index.<br />
*/
//rhs
int LList::operator[](int index) const{
    if(index < size()) {
        Datum *temp = head;
        for(int i = 0; i<size(); i++){
            if(i == index)
                return temp->getData();
            temp = temp->getNext();
        }
    }
    else if(index <0)
        return head->getData();
    return tail -> getData();
}
//lhs
int& LList::operator[](int index){
    if(index < size()) {
        Datum *temp = head;
        for(int i = 0; i<size(); i++){
            if(i == index){
                int ret = temp->getData();
                return ret;
            }
            temp = temp->getNext();
        }
    }
    if(index <0){
        int ret = head->getData();
        return ret;
    }
    int ret = tail->getData();
    return ret;
}
bool LList::operator==(const LList &rhs) const{
    if(rhs.size() != size())
        return false;
    Datum *temp = head;
    for(int i = 0; i<size(); i++){
        if(rhs.getData(i) != temp->getData())
            return false;
        temp = temp->getNext();
    }
    return true;
}
        
void LList::setData(int data, int index){
    Datum *temp = head;
    for(int i = 0; i<size(); i++){
        if(i == index){
            temp->setData(data);
        }
        temp = temp->getNext();
    }
}
int LList::getData(int index) const{
    Datum *temp = head;
    for(int i = 0; i<size(); i++){
        if(i == index)
            return temp->getData();
        temp = temp->getNext();
    }
    return -1;
    
}

void LList::setSize(int _size){
    length = _size;
}

Datum LList::getHead() const {
    return *head;
}

Datum LList::getTail() const {
    return *tail;
}

/* ostream & operator<< (ostream &lhs, const LList &rhs) {
    if(rhs.size() == 0)
        lhs << '-';
    for(int i=0; i<rhs.size(); i++){
        lhs << rhs.getData(i) << ' ';
    }
    return lhs;
} */

/* istream & operator>>(istream &lhs, LList &rhs) {
    /* rhs.insert(rhs.size(),lhs);
    return lhs;
    for(int i = 0; i< rhs.size(); i++)
        lhs >> rhs.getData(i);
    return lhs;
}*/