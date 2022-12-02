#include <iostream>
#include "Datum.h"

using namespace std;

int main()
{
    Datum *first = new Datum(1);

    cout << "first is at: " << first << " has: " << (*first).data << " points to: " << (*first).next << endl;
    cout << "first is at: " << first << " has: " << first->data << " points to: " << first->next << endl;

    return 0;
}
