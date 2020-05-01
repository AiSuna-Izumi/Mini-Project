#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
void reserve();
void checkOut();
void checkRoom();
void customerDetail();
using namespace std;
//create the structure of the list
struct hotel{
    string number;
    string guestName;
    string date;
    string time;
    string room;
    string price;
    string phone;
    string ic;
    hotel *next;
};
hotel *head;

int main()
{
	system("cls");
	int choice,x,i;
	while(choice !=5)
	{
		system("color 10");
		system("cls");
		cout<<"NEW\n";
		cout<<"=========================================== \n";
		cout<<"1. Reserve Hotel\n";
		cout<<"2. Check Room \n";
		cout<<"3. Check Out (Payment)) \n";
		cout<<"4. Customer Detail \n";
		cout<<"5. Exit \n";
		cout<<"=========================================== \n";
		cout<<"Enter your required \n";
		cin>>choice;
		
		//start if
		if(choice==1){
		reserve();
		x+=1;}
		else if(choice==2)
		checkRoom();
		else if(choice==3)
		checkOut();
		else if(choice==4){
		while(i<=x){
			i++;
			customerDetail();
		}
		
		}
		//end if
		
	}
	
	cout<<"THANK YOU FOR USING IT \n";
	//end program
	return 0;
}
void reserve()
{
	system("color 20");
	int choice,x;
	double price;
	hotel *newptr, *cur, *prev;
	newptr= new hotel;
	time_t current_time;
	current_time = time(NULL);
	ofstream addCustomer; //declare file
	ofstream totalCust;  //decalre file for make total
	addCustomer.open("customerReserve.txt",ios::app); //file name customerReserve.txt
	if (addCustomer.is_open())
	{
		do{
			{
			system("cls");
			//start input customer to make receipt and save it
			cin.ignore();
			cout<<"Guest Number: ";
			getline(cin,newptr->number);
			cout<<"Enter Guest`s Name : ";
			getline (cin,newptr->guestName);
			cout<<"Date Booking (dd/mm/yy) : ";
			getline(cin,newptr->date);
			cout<<"Time Check in : ";
			getline(cin,newptr->time);
			cout<<"Type Of Room : \n"<<"1.Single Bed \t"<<"2.Queen Bed \t"<<"3. Double Bed \n";
			cin>>x;
			if (x==1){
			newptr->room="Single Bed";
			newptr->price=80;}
			else if(x==2){
			newptr->room="Queen Bed";
			newptr->price=100;}
			else if(x==3){
			newptr->room="Double Bed";
			newptr->price=90;}
			else
			cout<<"Wrong Input \n";
			cin.ignore();
			cout<<"Phone Number: ";
			getline(cin,newptr->phone);
			cout<<"Identity Card/Passport: ";
			getline(cin, newptr->ic);
			newptr->next = NULL;
			
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
		{
			cout<<"\t\t********************************************************\n\n";
			cout<<"BOOKING DETAIL\n\n";
			cout<<"Guest Number: "<<newptr->number<<endl;
			cout<<"Enter Guest`s Name : "<<newptr->guestName<<endl;
			cout<<"Date Booking (dd/mm/yy) : "<<newptr->date<<endl;
			cout<<"Time Check in : "<<newptr->time<<endl;
			cout<<"Type Of Room : \n"<<"1.Single Bed \t"<<"2.Queen Bed \t"<<"3. Double Bed\t : "<<newptr->room<<endl;
			cout<<"Price =RM "<<newptr->price<<endl;
			cout<<"Phone Number:  "<<newptr->phone<<endl;
			cout<<"Identity Card/Passport: "<<newptr->ic<<endl<<endl;
		}
		{
			addCustomer<<newptr->number<<endl;
			addCustomer<<newptr->guestName<<endl;
			addCustomer<<newptr->date<<endl;
			addCustomer<<newptr->time<<endl;
			addCustomer<<newptr->room<<endl;
			addCustomer<<newptr->price<<endl;
			addCustomer<<newptr->phone<<endl;
			addCustomer<<newptr->ic<<endl<<endl;
		}
		
	totalCust.open("totalPrice.txt", ios::app);//name file for total all
	if(totalCust.is_open())
	{
		totalCust<<newptr->price<<endl;
		totalCust<<newptr->number<<endl;
		totalCust<<newptr->room<<endl<<endl;
	}totalCust.close(); //save file total
	
		//choice for next program
		cout<<"PRESS 1 TO EXIT \n";
		cin>>choice;
		}while (choice!=1);
	}addCustomer.close();//close file
	
}
void checkOut()
{
	system("cls");
	system("color 30");
	int choice;
	double room, pay, price, total;
	cout<<" \t\t\t CHECK OUT ROOM \t\t\t\n\n";
	do{
	
	cout<<"Type Of Room : \n"<<"1.Single Bed \t"<<"2.Queen Bed \t"<<"3. Double Bed \n";
	cin>>room;
	if (room==1)
	{
		cout<<"RM 60 \n";
		price=60;
	}
	else if(room==2)
	{
		cout<<"RM 100 \n";
		price=100;
	}
	else if(room==3)
	{
		cout<<"RM 80 \n";
		price=80;
	}
	else
	{
		cout<<"SORRY WRONG INPUT \n";
	}
	
	total+=price;
	cout<<"TOTAL PRICE : RM "<<total;
	cout<<endl<<endl;
		cout<<"PRESS 1 TO ADD OR 2 TO EXIT \n";
		cin>>choice;
	}while (choice !=2);
}
void checkRoom()
{
	system("cls");
	system("color 50");
	double choice;
	hotel *newptr, *cur, *prev;
	newptr= new hotel;
	string x;
	cout<<"************************************************\n\n";
	cout<<"_____________________ROOM THAT BEEN BOOKING_________________\n";
	cout<<"\t\tNumber Guest\t"<<"Room Type"<<endl;
	ifstream room("totalPrice.txt");//declare open file
	if(room.is_open()) 
	{
		while(!room.eof())
		{
			getline(room,newptr->price);
			getline(room,newptr->number);
			getline(room,newptr->room);
			getline(room,x);
			
			cout<<"\t\t"<<newptr->number<<"\t\t"<<newptr->room<<endl;
			
		}
	}
	
	else
	cout<<"File Not Found \n";
	
	cout<<"________________________________________________\n \n";
	cout<<"************************************************\n\n";
	cout<<"PRESS 1 TO CONTINUE \n";
	
	cin>>choice;
}
void customerDetail()
{
	system("cls");
	system("color 40");
	hotel *newptr, *cur, *prev;
	newptr= new hotel;
	cur=head;
	int choice,f;
	string x;
	{
			cout<<"Guest Number: "<<newptr->number<<endl;
			cout<<"Enter Guest`s Name : "<<newptr->guestName<<endl;
			cout<<"Date Booking (dd/mm/yy) : "<<newptr->date<<endl;
			cout<<"Time Check in : "<<newptr->time<<endl;
			cout<<"Type Of Room : "<<newptr->room<<endl;
			cout<<"Price : RM "<<f<<endl;
			cout<<"Phone Number "<<newptr->phone<<endl;
			cout<<"Identity Card/Passport: "<<newptr->ic<<endl<<endl;
	}	
	
	
	cout<<"PRESS 1 TO CONTINUE \n";
	cin>>choice;	
}
