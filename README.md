# CSCE240_FinalProject
Objective:

Demonstrate mastery of pointers and dynamic memory management.
Become familiar with Liked Lists.
Become familiar the operator overloading and OOP in C++.
Become familiar with the computational and space complexity of data structures
Become familiar with the development of templated classes
Develop communication skills by working on a team project
Description:
Create an abridged version of a Linked List class The project should contain a Datum class that describes a single data point and LList that defines the object Linked List with all of its member methods and data.

Project requirements:

Your program should contain two objects with the following criteria:

An object named Datum describes a single data item in the Linked List.
The Datum object should hold an integer value.
The Datum object should contain a default constructor.
The Datum object may contain a variety of alternate constructors.
The Datum object should contain a copy constructor.
All member variables should be private.
Should make proper use of getters and setters.
An object named LList utilizes the Datum object in order to define a Linked List.

The LList object should contain int values.
Should contain a default constructor.
Should contain an alternate constructor LList(int[] anArray, int size) that allows the user to create a LList from an array.
Should contain a copy constructor that will create a LList identical to the one that is passed to it.
Should contain an overloaded operator+ that will append two lists. This should be a cascade-capable operation.
Should contain an overloaded operator= that will assign the content of lhs with rhs. This should be a cascade-capable operation.
Should contain a void insert(int index, int value) method that inserts value at the position index.
Need to check for the appropriate index. If the index is outside of the list boundaries, then add it at the beginning or the end depending on the appropriate side.
Should contain an int remove(int index) method that will remove the item at the index and return the value of the removed item.
If the index is outside of the list boundaries, then remove the first or last element depending on the appropriate side.
Should contain boolean contains(int value) method
Should overload the operator[] (int index) method that can be used in the lhs or rhs of an assignment operator. 
This method will either return the value of the array at the given index or set the value at a given index.
If the index is out of the boundary then return either the first or last element
Should contain an int indexOf(int value) method
Returns the index of the first occurrence of the value
Should contain a boolean isEmpty() method
Should contain a size() method that returns the size of the list. 
Should contain a  clear() method that empties the LList
Should contain an overloaded operator<< method that prints all elements of the LList in one row delimited by one space
Should contain an overloaded operator>> method that will obtain a value of stream to be appended to the end of the LList object
Should contain an operator== that returns true if the two linked lists are identical and false if they are different.
