#include <iostream>
#include "Datum.h"

using namespace std;

int main()
{
    Datum first(1);
    Datum second(2);
    Datum third(3);

    cout << "Before linking" << endl;
    cout << &first << " " << first.getData() << " " << first.getNext() << endl;
    cout << &second << " " << second.getData() << " " << second.getNext() << endl;
    cout << &third << " " << third.getData() << " " << third.getData() << endl;

    first.setNext(second);
    second.setNext(third);
//    first = &second; //Can't do this.
//    first.next = &second;
//    second.next = &third;
//
    cout << endl << "After linking" << endl;
    cout << &first << " " << first.getData() << " " << first.getNext() << endl;
    cout << &second << " " << second.getData() << " " << second.getNext() << endl;
    cout << &third << " " << third.getData() << " " << third.getData() << endl;

//    cout << "Indirect access to second and third through first" << endl;
//    cout << (*first.next).data << endl;
//    cout << (*(*first.next).next).data << endl;
//
//    cout << "Traversing a linked list" << endl;
//    Datum *temp;
//    temp = &first; //temp points to the head node.
//    cout << &first << " " << first.data << " " << first.next << endl;
//    cout << (*temp).data << " " << (*temp).next << endl;
//    temp = (*temp).next;
//    cout << (*temp).data << " " << (*temp).next << endl;
//    temp = (*temp).next;
//    cout << (*temp).data << " " << (*temp).next << endl;

    return 0;
}
