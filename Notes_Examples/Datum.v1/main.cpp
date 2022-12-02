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
    cout << &third << " " << third.getData() << " " << third.getNext() << endl;

    first.setNext(second);
    second.setNext(third);
    cout << "After linking" << endl;
    cout << &first << " " << first.getData() << " " << first.getNext() << endl;
    cout << &second << " " << second.getData() << " " << second.getNext() << endl;
    cout << &third << " " << third.getData() << " " << third.getNext() << endl;

    return 0;
}
