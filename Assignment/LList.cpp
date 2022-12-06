#include <iostream>
#include "LList.h"
#include "Datum.h"

using namespace std;

/* friend ostream & operator<< (ostream &lhs, const LList &rhs);
friend istream & operator>> (istream &lhs, LList &rhs); */
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
    size++;
}
int LList::remove(int index){
    Datum *temp = head;
    for(int i = 0; i < index-1; i++){
        temp = temp->getNext();
    }
    temp->setNext(*temp->getNext()->getNext());
    size--;
}
bool LList::contains(int value){
    Datum *temp = head;
    for(int i = 0; i < size; i++){
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
    for(int i = 0; i < size; i++){
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
int LList::length(){
    return size;
}
void LList::clear(){
    head = tail;
    head->setData(NULL);
}

const LList LList::operator+(const LList &rhs)const{
    
}
const LList LList::operator=(const LList &rhs){

}
int LList::operator[](int index) const{

}
/* int LList:: & operator[](int index){

} */
bool LList::operator==(const LList &rhs) const{
    if(rhs.getSize() != getSize())
        return false;
    Datum * temp 
    for(int i = 0; i<getSize(); i++){
        
    }
}
        
void LList::setData(int data, int index){
    Datum *temp = head;
    for(int i = 0; i<getSize(); i++){
        if(i == index){
            temp->setData(data);
        }
    }
}
int LList::getData(int index) const{
    Datum *temp = head;
    for(int i = 0; i<getSize(); i++){
        if(i == index)
            return temp->getData();
        temp->getNext();
    }
    return -1;
    
}
int LList::getSize() const{
    return size;
}

void LList::setSize(int _size){
    size = _size;
}

Datum LList::getHead() const {
    return *head;
}

Datum LList::getTail() const {
    return *tail;
}