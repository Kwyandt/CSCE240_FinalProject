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

}
int LList::remove(int index){

}
bool LList::contains(int value){

}
int LList::indexOf(int value){

}
bool LList:: isEmpty(){

}
/* int LList::size() const{

} */
void LList::clear(){

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

}
        
void LList::setData(int data, int index){
    Datum *temp = head;
    for(int i = 0; i<getSize(); i++){
        if(i == index){
            
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