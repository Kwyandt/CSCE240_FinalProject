#include <iostream>
#include "LList.h"
#include "Datum.h"

using namespace std;

LList::LList(){
    setSize(0);
    head = tail = NULL;
}
LList::LList(int arr[], int size){
    head = tail = NULL;
    setSize(0);
    for(int i=0; i<size; i++){
        insert(i, arr[i]);
    }
}
LList::LList(const LList& list){
    head = tail = NULL;
    setSize(0);
    for(int i=0; i<list.size(); i++){
        insert(i, list.getData(i));
    }
}

//destructor
LList::~LList() {
    length = 0;
    Datum *temp = head;
    while (head != NULL) {
        head = temp->getNext();
        delete temp;
        temp = head;
    }
}
        
void LList::insert (int index, int value){
    if(index <= 0){
        Datum *temp = head;
        head = new Datum(value);
        if(size()>0)
            head->setNext(*temp);
        else
            tail = head;
        length++;
    }
    else if(index >= length){
        Datum *temp = new Datum(value);
        tail->setNext(*temp);
        tail = tail->getNext();
        length++;
    }
    else{
        Datum *temp = head;
        Datum *next;
        Datum *data = new Datum(value);
        for(int i = 0; i < index-1; i++){
            temp = temp->getNext();
        }
        next = temp->getNext();
        temp->setNext(*data);
        temp->getNext()->setNext(*next);
        length++;
    }
}
int LList::remove(int index){
    if(size() == 0){
        return -1;
    }
    int ret = 0;
    if(index <= 0){
        ret = head->getData();
        Datum *temp = head->getNext();
        delete head;
        head = temp;
        length--;
    }
    else if(index >= (length-1)){
        Datum *temp = head;
        for(int i = 0; i < length-2; i++){
            temp = temp->getNext();
        }
        ret = temp->getNext()->getData();
        delete tail;
        tail = temp;
        temp = NULL;
        tail->setNext(*temp);
        length--;
    }
    else{
        Datum *temp = head;
        for(int i = 0; i < index-1; i++){
            temp = temp->getNext();
        }
        Datum *next = temp->getNext();
        ret = next->getData();
        temp->setNext(*next->getNext());
        delete next;
        length--;
    }
    return ret;
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
    length = 0;
    Datum *temp = head;
    while (head != NULL) {
        head = temp->getNext();
        delete temp;
        temp = head;
    }
}

const LList LList::operator+(const LList &rhs)const{
    if(size()>0 && rhs.size()>0){
        LList newList(*this);
        for(int i=0; i<rhs.size(); i++){
            newList.insert(newList.size(), rhs.getData(i));
        }
        return newList;
    }
    else if(size()<=0){
        return rhs;
    }
    return *this;

}
const LList LList::operator=(const LList &rhs){
    clear();
    for(int i=0; i<rhs.size(); i++){
            insert(size(), rhs.getData(i));
        }
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
    if(size() == 0){
        return length;
    }
    if(index < size()) {
        Datum *temp = head;
        for(int i = 0; i<size(); i++){
            if(i == index){
                return temp->getData(0);
            }
            temp = temp->getNext();
        }
    }
    else if(index <0){
        return head->getData(0);
    }
    return tail->getData(0);
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

ostream& operator<<(ostream &lhs, const LList &rhs) {
    if(rhs.size() == 0)
        lhs << "-";
    for(int i=0; i<rhs.size(); i++){
        lhs << rhs.getData(i) << " ";
    }
    return lhs;
}
//obtain a value of stream to be appended to the end of the LList object
//TODO not actually modiying
istream& operator>>(istream &lhs, LList &rhs) {
    lhs >> rhs[rhs.size()];
    rhs.length = rhs.length + 1;
    return lhs;
}
