# CSCE240_FinalProject
Objective:

Demonstrate mastery of pointers and dynamic memory management.<br />
Become familiar with Liked Lists.<br />
Become familiar the operator overloading and OOP in C++.<br />
Become familiar with the computational and space complexity of data structures<br />
Become familiar with the development of templated classes<br />
Develop communication skills by working on a team project<br /><br />
Description:<br />
Create an abridged version of a Linked List class The project should contain a Datum class that describes a single data point and LList that defines the object Linked List with all of its member methods and data.<br />

Project requirements:

Your program should contain two objects with the following criteria:<br />

An object named Datum describes a single data item in the Linked List.<br />
The Datum object should hold an integer value.<br />
The Datum object should contain a default constructor.<br />
The Datum object may contain a variety of alternate constructors.<br />
The Datum object should contain a copy constructor.<br />
All member variables should be private.<br />
Should make proper use of getters and setters.<br />
An object named LList utilizes the Datum object in order to define a Linked List.<br />

The LList object should contain int values.<br />
Should contain a default constructor.<br />
Should contain an alternate constructor LList(int[] anArray, int size) that allows the user to create a LList from an array.<br />
Should contain a copy constructor that will create a LList identical to the one that is passed to it.<br />
Should contain an overloaded operator+ that will append two lists. This should be a cascade-capable operation.<br />
Should contain an overloaded operator= that will assign the content of lhs with rhs. This should be a cascade-capable operation.<br />
Should contain a void insert(int index, int value) method that inserts value at the position index.<br />
Need to check for the appropriate index. If the index is outside of the list boundaries, then add it at the beginning or the end depending on the appropriate side.<br />
Should contain an int remove(int index) method that will remove the item at the index and return the value of the removed item.<br />
If the index is outside of the list boundaries, then remove the first or last element depending on the appropriate side.<br />
Should contain boolean contains(int value) method<br />
Should overload the operator[] (int index) method that can be used in the lhs or rhs of an assignment operator. <br />
This method will either return the value of the array at the given index or set the value at a given index.<br />
If the index is out of the boundary then return either the first or last element<br />
Should contain an int indexOf(int value) method<br />
Returns the index of the first occurrence of the value<br />
Should contain a boolean isEmpty() method<br />
Should contain a size() method that returns the size of the list. <br />
Should contain a  clear() method that empties the LList<br />
Should contain an overloaded operator<< method that prints all elements of the LList in one row delimited by one space<br />
Should contain an overloaded operator>> method that will obtain a value of stream to be appended to the end of the LList object<br />
Should contain an operator== that returns true if the two linked lists are identical and false if they are different.<br />
