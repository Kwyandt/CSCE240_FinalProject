

/**
 * @brief benefits of linked list
 * 
 * linked lists are not a contiguous memory requirement so you can find more ways of doing it
 * 
 * exectution time: size variant, depends on what exactly you are doing with the operation
 * 
 * copy and insert, and append, are much easier
 */

/**
 * @brief pointerObject example
 * 
 * pointerObject.h
 * class pointerObject 
 * {
 *  public :
 *      pointerObject();
 *  
 * }
 * 
 * pointerObject.cpp
 * 
 * main.cpp
 * 
 * pointerObject S1;
 * poinetObject S2;
 * pointerObject *S3;
 * S3 = new pointerObject;
 * 
 * cout << *S1.Var1 << " " << *S1.Var2 << endl;  //this is what you want to point at it (order of operatiorns)
 * cout << *S1.Var1 << " " <<< *S2Var1 << endl; //-20 30
 * cout << (*S3).Var1 << " " << (*S3).Var2 << endl; //enforce the order
 * cout << S3->Var1 << " " S3->Var2 << endl; //two memory locations
 * cout << *S3->Var1 << " " *S3->Var2 << endl; //these last two show other ways this can be done , you should be mofre likelt to do one of the first 2 and middl3 2
 * cout << *(*S3).Var1 << " " << *(*S3).Var2 << endl; //-20 30
 */

/**
 * @brief the assignment info
 * 
 * 
 * single linked list, double linked list will just be an extention of that
 * 
 * keep track of the size to make it easier to see if something is too large or not
 * 
 * only ned two layers of reference 
 * 
 * its important to deep copy your datum
 * 
 * you don't have to copy the rest of the list just thee datum itself
 * 
 * no descructor in the datum because there is no new
 * 
 * delete it recursive
 */
