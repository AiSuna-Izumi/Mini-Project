#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;
//create the structure of the list
struct hotel{
    int number;
    string guestName;
    string date;
    string time;
    string room;
    int price;
    string phone;
    string ic;
    hotel *next;
};
hotel *head;

int main()
{
	hotel *newptr, *cur, *prev;
	newptr= new hotel;
	cur=head;
	int choice,number,y;
	string x;
	ifstream checkOut; //declare showProduct 
	checkOut.open("totalPrice.txt",ios::out);
	if (checkOut.is_open()) 
	{
			while(!checkOut.eof())
			{
			checkOut>>newptr->price;
			checkOut>>newptr->number;
			getline(checkOut,newptr->room);
			getline(checkOut,x);
			
			
			cout<<"price : "<<newptr->price<<endl;
			cout<<"number :"<<newptr->number<<endl;
			cout<<"room: "<<newptr->room<<endl<<endl;
			
			if(head==NULL)
			head = newptr;
		else
		{
			cur = head;
 			while(cur != NULL){ 
            prev = cur;
            cur = cur->next;
        }
        prev->next = newptr;
    	}
			}
			cout<<"Enter Guest Number \n";
			cin>>y;
	while(cur != NULL && y != cur->number){
        cur = cur->next;
    }
    if(cur == NULL)
        cout<<"\nSorry the data is not found\n";
    else
        cout<<"\nYes, the data is found!\n";
		
	}
	else
	cout<<"FILE NOT FOUND \n";

} 
