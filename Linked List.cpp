#include<iostream>
#include <fstream>
#include <string>
using namespace std;
void insert();
void display();
void remove_all();
void remove();
void search();

//create the structure of the list
struct Nom{
    string iNom;
    Nom *next;
};

// declare a head pointer as a global variable, so that it can be used in other functions
 Nom *head;

/* This is the main function.
 */
int main(){

    //create an empty list
    head = NULL ;
    insert();//insert the first element
    insert(); //to insert another element
    insert(); //to insert another element
	display();//display all elements in the list
	search();  //call the search function
    remove();  //call the remove function
    display();//display all elements in the list
	remove_all(); //call the remove_all function

    /* Note that you can call insert function by using a loop
     * example of inserting 10 elements:
     * for (int i = 0; i< 10; i++) {
     *     insert();
     * }
     * You can also call display() function anywhere if you want
     * to see your elements in the list
     */

}
/* This insert function will insert an element into the list.
 */
void insert(){
	
	ofstream addCustomer; //declare file
	ofstream totalCust;  //decalre file for make total
	addCustomer.open("customer.txt",ios::app); //file name customer.txt
		
	if (addCustomer.is_open())
	{
    //create a new element that need to be inserted into the list
    Nom *newptr, *cur, *prev;
    cur = head;
    prev = NULL;

    newptr = new Nom;
    cout<<"\nPlease enter a new value to be inserted : ";
    cin.ignore();
    getline(cin,newptr->iNom);
    newptr->next = NULL;

    //insert into an empty list
    if(head == NULL){
        head = newptr;
    }
    else{
        // a loop to move prev and cur along the list and stop at appropriate place
        // to insert a new element
        while(cur != NULL){
            prev = cur;
            cur = cur->next;
        }
        //insert in front of the list
        if(prev == NULL){
            newptr->next = cur;
            head = newptr;
        }
        else {
        //coding to insert at the middle or the end of the list
        newptr->next = cur;
        prev->next = newptr;
        }
    }
    
    {
    	addCustomer<<cur->iNom<<endl;
	}
	}addCustomer.close();//close file
}

/* This function will remove all nodes from the list.
 * After calling this function, the list is empty
 * Thus, no more node is available to view, update or remove.
 */
void remove_all(){
    Nom *cur;
    cur = head;
	cout<<"\n**Delete list**"<<endl;
    while(head != NULL){
        cur = head; // cur points to the head
        head = head->next;  //head points to the next
        delete cur;
    }
}

/* Display function is a function to display all elements in the list.
 * This function will dislay "sorry the list is empty", if the list is empty.
 * Otherwise it will display all elements in the list
 */
void display(){
      Nom *cur;
      cur = head;
      cout<<"\n**Display list**\n";
      if (head == NULL){
          cout<<"\nSorry the list is empty"<<endl;
      }
      else {
          while(cur != NULL){
             cout<<cur->iNom<<"->";
             cur = cur->next;
          }
          cout<<"NULL\n";
      }
}
/* Search function is used to search an element in the list.
 * If the element is found, an appropriate msg will be displayed.
 * Otherwise another appropriate msg will also be displayed.
 */

void search(){
    string iData;
    Nom *cur;
    cout<<"\nPlease enter a data that you want to find : ";
    cin>>iData;
    cur = head;
    //move cur pointer along the list
    while(cur != NULL && iData != cur->iNom){
        cur = cur->next;
    }
    if(cur == NULL)
        cout<<"\nSorry the data is not found\n";
    else
        cout<<"\nYes, the data is found!\n";

}
/* Remove function is a function that removes only one node from the list.
 * The function will prompt a user to enter a value to be removed and the
 * date will be searched from the list. If it is found, then it will be removed,
 * Otherwise, we simply display a message saying that the data is not found
 * So, we cannot remove the data.
 */

void remove(){
    string iData;
    Nom *cur, *prev;

    if(head == NULL){  //we cannot remove if the list is empty
        cout<<"\nSorry, the list is empty"<<endl;
    }
    else{
        cout<<"\nPlease enter a data to be removed : ";
        cin>>iData;
        prev = NULL;
        cur = head;
        /*move prev and cur pointers along the list */
        while(cur != NULL && iData != cur->iNom){
            prev = cur;
            cur = cur->next;
        }
        /* if the data is in front of the list, remove it.
         */
        if(prev == NULL){
            head = head->next;
            delete cur;
        }
        else {
            /*if cur has reached the end of the list, that means the data that
             *we want to remove is not in the list.
             *Otherwise, remove the data by linking the pointers
             */
            if(cur == NULL){
                cout<<"\nSorry we cannot remove the data as it is not in the list"<<endl;
            }
            else{
                prev->next = cur->next;
                delete cur;
            }
        }
  }
}

