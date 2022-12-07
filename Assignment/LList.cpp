#include <iostream>
#include "LList.h"
#include "Datum.h"

using namespace std;

/**
 * @brief Construct a new LList::LList object
 * 
 */
LList::LList(){
    setSize(0);
    head = tail = NULL;
}

/**
 * @brief Construct a new LList::LList object
 * 
 * @param arr An array that the LList is created out of
 * @param size The size of the array
 */
LList::LList(int arr[], int size){
    head = tail = NULL;
    setSize(0);
    for(int i=0; i<size; i++){
        insert(i, arr[i]);
    }
}

/**
 * @brief Construct a copy of a LList::LList object
 * 
 * @param list The list that is being copied
 */
LList::LList(const LList& list){
    head = tail = NULL;
    setSize(0);
    for(int i=0; i<list.size(); i++){
        insert(i, list.getData(i));
    }
}

/**
 * @brief Destroy the LList::LList object
 * 
 */
LList::~LList() {
    //length = 0;
    Datum *temp = head;
    while (head != NULL) {
        head = temp->getNext();
        delete temp;
        temp = head;
    }
}
        
/**
 * @brief Inserts a new node at the supplied index
 * 
 * @param index The index the node gets added at
 * @param value The value of the new node
 */
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

/**
 * @brief Removes the node from that index
 * 
 * @param index The index at that location
 * @return int The value at that index
 */
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

/**
 * @brief Checks if the list contains a certian value
 * 
 * @param value The value that is being checked for 
 * @return true If the list contains the value
 * @return false If the list does not contain the value
 */
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

/**
 * @brief Finds the index of a certian value
 * 
 * @param value The value that is being searched for
 * @return int The index of that value
 */
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

/**
 * @brief Checks if the linked list is empty
 * 
 * @return true Returns true if the list is empty
 * @return false Returns false if the list has stuff in it
 */
bool LList:: isEmpty(){
    if(head==NULL){
        return true;
    }
    return false;
}

/**
 * @brief Returns the size of the list
 * 
 * @return int The size of the list
 */
int LList::size() const{
    return length;
}

/**
 * @brief Emptys the list out
 * 
 */
void LList::clear(){
    length = 0;
    Datum *temp = head;
    while (head != NULL) {
        head = temp->getNext();
        delete temp;
        temp = head;
    }
}

/**
 * @brief Adds the supplied list to the end of the current one
 * 
 * @param rhs The list thats being added
 * @return const LList The combination of the list
 */
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

/**
 * @brief Sets the current list to the supplied list
 * 
 * @param rhs The list the value is being changed to
 * @return const LList The new linked list
 */
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
    if(size() == 0){
        return dummy;
    }
    if(index < size()) {
        Datum *temp = head;
        for(int i = 0; i<size(); i++){
            if(i == index){
                return temp->getData();
            }
            temp = temp->getNext();
        }
    }
    else if(index <0){
        return head->getData();
    }
    return tail->getData();
}
//lhs
int& LList::operator[](int index){
    if(size() == 0){
        return dummy;
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
    //lhs >> rhs[rhs.size()];
    /* rhs.length = rhs.length + 1; */
    int input;
    lhs >> input;
    rhs.insert(rhs.size(), input);
    return lhs;
}
