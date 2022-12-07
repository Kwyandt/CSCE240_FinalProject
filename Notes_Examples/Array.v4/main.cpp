#include <iostream>
#include "myArray.h"

using namespace std;

int main() {
    myArray A1;
    myArray A2(10);
    myArray A3(10, -2);
    myArray A4(A3);


    cout << "A1: ";
    A1.print();
    cout << "A2: ";
    A2.print();
    cout << "A3: ";
    A3.print();
    cout << "A4: ";
    A4.print();

    if(A1 == A2) {cout << "A1 == A2" << endl;} else { cout << "A1 != A2" << endl;}
    if(A1 == A3) {cout << "A1 == A3" << endl;} else { cout << "A1 != A3" << endl;}
    if(A3 == A4) {cout << "A3 == A4" << endl;} else { cout << "A3 != A4" << endl;}

//    A3.append(A2); //The previous version
//    A3 + A2; //The new version but kinka odd
    A1 = A2 + A3 + A4;
    A1 = A4 = A3 + A2; //This is what we really want
    cout << "A1: ";
    A1.print();
    cout << "A2: ";
    A2.print();
    cout << "A3: ";
    A3.print();
    cout << "A4: ";
    A4.print();

    cout << "A4[3] = " << A4[3] << endl;
    A4[3] = -999;
    cout << "A4[3] = " << A4[3] << endl;

    A4 = -A3;
    A4.print();

    return 0;
}
