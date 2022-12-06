#include <iostream>
#include "LList.h"
#include "Datum.h"

using namespace std;

LList::LList(){

}
LList::LList(int[], int size){

}
LList::LList(const LList&){

}
        
void LList::insert (int index, int value){
    Datum *temp = head;
    for(int i = 0; i < index; i++){
        temp = temp->getNext();
    }
    temp->setNext(Datum(value));
    length++;
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
    if(head->getData()==NULL){
        return true;
    }
    return false;
}
int LList::size() const{
    return length;
}
void LList::clear(){
    head = tail;
    head->setData(NULL);
}

const LList LList::operator+(const LList &rhs)const{
    
}
const LList LList::operator=(const LList &rhs){

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
    if(index <0)
        return head->getData();
    if(index >size())
        return tail -> getData();
}
//lhs
int & LList::operator[](int index){
    if(index < size()) {
        Datum *temp = head;
        for(int i = 0; i<size(); i++){
            if(i == index)
                return temp->getData();
            temp = temp->getNext();
        }
    }
    if(index <0)
        return head->getData();
    if(index >size())
        return tail -> getData();
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

ostream & operator<< (ostream &lhs, const LList &rhs) {
    if(rhs.size() == 0)
        lhs << '-';
    for(int i=0; i<rhs.size(); i++){
        lhs << rhs.getData(i) << ' ';
    }
    return lhs;
}

/* istream & operator>>(istream &lhs, LList &rhs) {
    /* rhs.insert(rhs.size(),lhs);
    return lhs; */
    for(int i = 0; i< rhs.size(); i++)
        lhs >> rhs.getData(i);
    return lhs;
}*/