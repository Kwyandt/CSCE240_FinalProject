#include <iostream>
#include "Datum.h"

using namespace std;

int main()
{

    Datum first(1);
    Datum *head = new Datum(1);
    Datum *tail;
    Datum *temp;


    tail = head;

    temp = new Datum (2);
    cout << "head: " << head << " " << head->getData() << " " << head->getNext() << endl;
    cout << "tail: " << tail << " " << tail->getData() << " " << tail->getNext() << endl;
    cout << "temp " << temp << " " << temp->getData() << " " << temp->getNext() << endl << endl;

    tail->setNext(*temp);
//    cout << "head: " << head << " " << head->getData() << " " << head->getNext() << endl;
//    cout << "tail: " << tail << " " << tail->getData() << " " << tail->getNext() << endl;
//    cout << "temp " << temp << " " << temp->getData() << " " << temp->getNext() << endl << endl;
//
//    tail = temp;
//    cout << "head: " << head << " " << head->getData() << " " << head->getNext() << endl;
//    cout << "tail: " << tail << " " << tail->getData() << " " << tail->getNext() << endl;
//    cout << "temp " << temp << " " << temp->getData() << " " << temp->getNext() << endl << endl;
//
//    temp = new Datum (3);
//    tail->setNext(*temp);
//    tail = temp;
//    cout << "head: " << head << " " << head->getData() << " " << head->getNext() << endl;
//    cout << "tail: " << tail << " " << tail->getData() << " " << tail->getNext() << endl;
//    cout << "temp " << temp << " " << temp->getData() << " " << temp->getNext() << endl << endl;


    return 0;
}
