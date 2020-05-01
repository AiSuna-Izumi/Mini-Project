#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
void customer();
void vendor();
void product();
void sales();
using namespace std;
int main()
{
	int choice;
	//main menu
	while(choice !=5)
	{
		system("cls");
		cout<<"=========================================== \n";
		cout<<"1. Customer \n";
		cout<<"2. Vendor \n";
		cout<<"3. Product \n";
		cout<<"4. Sales \n";
		cout<<"5. Exit \n";
		cout<<"=========================================== \n";
		cout<<"Enter your required \n";
		cin>>choice;
		
		//start if
		if(choice==1)
		customer();
		else if(choice==2)
		vendor();
		else if(choice==3)
		product();
		else if(choice==4)
		sales();
		//end if
	}
	
	cout<<"THANK YOU FOR USING IT \n";
	//end program
	return 0;
}

void addCustomer();
void showCustomer();
void customer()
{
		system("cls");
	int choice;
	{
		//start with customer
		cout<<"====================CUSTOMER======================= \n";
		cout<<"1. Add Customer \n";
		cout<<"2. Show Customer \n";
		cout<<"3. Back Main Menu \n";
		cout<<"=========================================== \n";
		cout<<"Enter your required \n";
		cin>>choice;
		
		//start choice
		if(choice==1)
		addCustomer();
		else if(choice==2)
		showCustomer();
		//end choice
	}
	
}
void addCustomer()
{
	system("cls");
	double studentDiscount,order,payment, quantity, price, total, totalAmount,discount;
    string  Ic, bankAcc, studentId, bankName, product,name,creditCardNum;
    char studentConfirm;
	//add customer using file
	ofstream addCustomer; //declare file
	ofstream totalCust;  //decalre file for make total
	addCustomer.open("customer.txt",ios::app); //file name customer.txt
		
		if (addCustomer.is_open())
		{
			//start input customer to make receipt and save it
			cin.ignore();
			cout<<"Customer name : ";
			getline(cin,name);
				
				cout<<"Customer Ic : ";
				getline(cin,Ic);
				cout<<"Customer Bank Name : ";
				getline(cin,bankName);
				cout<<"Customer Bank Account number : ";
				getline(cin,bankAcc);
				cout<<"Customer Credit Card Number : ";
				getline(cin,creditCardNum);
				cout<<"STUDENT (Y/N)";
				cin>>studentConfirm;
				if ((toupper(studentConfirm))== 'Y')
				{
				cout<<"Student Id: ";
				cin.ignore();
				getline(cin,studentId);
				studentDiscount=0.05;
				
				}
				else 
				studentDiscount=0;
			
				cin.ignore();
				discount= 0.05+studentDiscount;
				cout<<"Enter Product: ";
				getline(cin, product);
				cout<<"Quantity: ";
				cin>>quantity;
				cout<<"Enter Price:$ ";
				cin>>price;
				
				total=price*discount;
				totalAmount=(price-total)*quantity;
				cout<<"Total:$ "<<totalAmount<<endl;
				
				{ //show receipt
				cout<<endl<<endl;
				cout<<" \t\t ----------RECEIPT---------- \n";
				cout<<"Customer name : "<<name<<endl;
				cout<<"Customer Ic : "<<Ic<<endl;
				cout<<"Customer Bank Name : "<<bankName<<endl;
				cout<<"Customer Bank Account number : "<<bankAcc<<endl;
				cout<<"Customer Credit Card Number : "<<creditCardNum<<endl;
				cout<<"Student Id: "<<studentId<<endl;
				cout<<"Enter Product: "<<product<<endl;
				cout<<"Quantity: "<<quantity<<endl;
				cout<<"Enter Price:$ "<<price<<endl;
				cout<<"Total:$ "<<totalAmount<<endl;
				cout<<"Time: "<<__TIMESTAMP__<<endl;
				}
				
				{//save customer detail to file
					addCustomer<<"Customer name : : "<<name<<endl;
		            addCustomer<<"Customer Ic :  "<<Ic<<endl;
		            addCustomer<<"Customer Bank Name : "<<bankName<<endl;
					addCustomer<<"Customer Bank Account number :  "<<bankAcc<<endl;
					addCustomer<<"Customer Credit Card Number : "<<creditCardNum<<endl;
					addCustomer<<"Enter Product: "<<product<<endl;
					addCustomer<<"Student Id: "<<studentId<<endl;
					addCustomer<<"Quantity: "<<quantity<<endl;
					addCustomer<<"Enter Price: "<<price<<endl;
					addCustomer<<"Total Purchase: $"<< totalAmount<<endl;
					addCustomer<<__TIMESTAMP__<<endl; //using time 
					addCustomer<<total<<endl;						
				}
		}addCustomer.close();//close file
		
	totalCust.open("totalCust.txt", ios::app);//name file for total all
	if(totalCust.is_open())
	{
		totalCust<<name<<" "<<totalAmount<<endl;
	}totalCust.close(); //save file total
	
	//choice for next program
		int choice;
		cout<<"PRESS 1 TO CONTINUE \n";
		cin>>choice;
}

//show customer
void showCustomer()
{
		system("cls");//make new page
	string studentDiscount,order,payment, quantity, price, total, totalAmount,discount;
string  Ic, bankAcc, studentId, bankName, product,name,creditCardNum, time;

ifstream showCustomer; //declare in file 
showCustomer.open("customer.txt", ios::in);//open customer.txt file

if (showCustomer.is_open()) 
{
	//start loop
	while(!showCustomer.eof())
	{
		//call item from file using string
		cout<<" \t\t ----------RECEIPT---------- \n";
		cout<<name<<endl;
		getline(showCustomer, name);
		cout<<Ic<<endl;
		getline(showCustomer, Ic);
		cout<<bankName<<endl;
		getline(showCustomer, bankName);
		cout<<bankAcc<<endl;
		getline(showCustomer, bankAcc);
		cout<<creditCardNum<<endl;
		getline(showCustomer, creditCardNum);
		cout<<product<<endl;
		getline(showCustomer, product);
		cout<<studentId<<endl;
		getline(showCustomer, studentId);
		cout<<quantity<<endl;
		getline(showCustomer, quantity);
		cout<<price<<endl;
		getline(showCustomer, price);
		cout<<total<<endl;
		getline(showCustomer, total);
		cout<<time<<endl;
		getline(showCustomer, time);
		cout<<totalAmount<<endl;
		getline(showCustomer, totalAmount);
		cout<<endl;
	}//end while
}
// if file not detect
else
cout<<"FILE NOT DETECT"<<endl;

//choice if done
	int choice;
		cout<<"PRESS 1 TO CONTINUE \n";
		cin>>choice;
}


void addVendor();
void showVendor();
void vendor()
{
	//start for input vendor
	system("cls");
	int choice;
	{
		//start choice for vendor
		cout<<"=========================================== \n";
		cout<<"1. Add Vendor \n";
		cout<<"2. Show Vendor \n";
		cout<<"3. Back Main Menu \n";
		cout<<"=========================================== \n";
		cout<<"Enter your required \n"; //make choice
		cin>>choice;
		
		if(choice==1)
		addVendor();
		else if(choice==2)
		showVendor();
		
	//end
	}
}
void addVendor()
{
		//start add vendor detail
		system("cls");
		string vedName,comNum,license,ic, product;
	int choice,no;
	double price, quantity, discount, total;
	

	ofstream addVendor; //declare out file for add vendor
	ofstream totalVendor; // declare for total all vendor
	addVendor.open("addVendor.txt",ios::app); //make file, add new file name addVendor.txt
	
	
	if(addVendor.is_open())
	{
		//start input detail for vendor, using double, string, and int
	cin.ignore();
	cout<< "NO REFERENCE :";
	cin>>no;
	cout << "Please Enter the Vendor Name: " ;
	cin.ignore();
	getline(cin, vedName);
	cout << "Please Enter Company Number: " ;
	getline(cin, comNum);
	cout << "Please Enter Vendor License: " ;
	getline(cin, license);
	cout << "Please Enter Vendor Identity Card No: " ;
	getline(cin, ic);
	cout<< "Enter Product: ";
	getline (cin, product);
	cout<< "Quantity: ";
	cin>>quantity;
	cout<< "Enter Price: ";
	cin>>price;
	
	discount=0.01*price; //calculate discount for vendor
	total=(price-discount)*quantity;
	//display total after discount
	cout<<"Total Purchase: $"<<total<<endl;
	
	{//display invoice or receipt for vendor
	cout<<endl<<endl;
	cout<<" \t\t ----------INVOICE---------- \n";
	cout<< "NO REFERENCE :"<<no<<endl;
	cout << "Please Enter the Vendor Name: " <<vedName<<endl;
	cout << "Please Enter Company Number: "<<comNum<<endl;
	cout << "Please Enter Vendor License: " <<license<<endl;
	cout << "Please Enter Vendor Identity Card No: "<<ic<<endl;
	cout<< "Enter Product: "<<product<<endl;
	cout<< "Quantity: "<<quantity<<endl;
	cout<< "Enter Price: "<<price<<endl;
	cout<<"Total Purchase: $"<<total<<endl;
	cout<<"Time: "<<__TIMESTAMP__<<endl;
	}
	{//save vendor file into addVendor.txt
		addVendor<<"NO REFERENCE: "<<no<<endl;
		addVendor<<"Please Enter the Vendor Name: "<<vedName<<endl;
		addVendor<<"Please Enter Company Number: "<<comNum<<endl;
		addVendor<<"Please Enter Vendor License: "<<license<<endl;
		addVendor<<"Please Enter Vendor Identity Card No: "<<ic<<endl;
		addVendor<<"Enter Product: "<<product<<endl;
		addVendor<<"Quantity: "<<quantity<<endl;
		addVendor<<"Enter Price: "<<price<<endl;
		addVendor<<"Total Purchase: $"<< total<<endl;
		addVendor<<__TIMESTAMP__<<endl;
		addVendor<<total<<endl;
	} addVendor.close(); //close addVendor.txt file
	
	}
	else
	cout<<"Files cannot be open \n";
	
	totalVendor.open("totalVendor.txt", ios::app);//open file for total 
	if(totalVendor.is_open())
	{
		totalVendor<<no<<" "<<total<<endl; //save file for total
	}totalVendor.close(); //close total file
	
	//end
		int choice1;
		cout<<"PRESS 1 TO CONTINUE \n";
		cin>>choice1;	
}
void showVendor()
{
	//for display or show all vendor
		system("cls");
		string no,vedName,comNum,license,ic, product, price, quantity, total, total1,time; //declare string
	ifstream showVendor; //declare that show vendor in file
	showVendor.open("addVendor.txt",ios::in); //open addVendor.txt file
	
	if(showVendor.is_open())
	{
		
		while (!showVendor.eof())
		{
			//start display all invoices from input vendor
		cout<<"\t\t ----------INVOICES---------- \n";
		cout<<no<<endl;
		getline(showVendor, no);
		cout<<vedName<<endl;
		getline(showVendor, vedName);
		cout<<comNum<<endl;
		getline(showVendor, comNum);
		cout<<license<<endl;
		getline(showVendor, license);
		cout<<ic<<endl;
		getline(showVendor, ic);
		cout<<product<<endl;
		getline(showVendor, product);
		cout<<quantity<<endl;
		getline(showVendor,quantity);
		cout<<price<<endl;
		getline(showVendor,price);
		cout<<total<<endl;
		getline(showVendor, total);
		cout<<time<<endl;
		getline(showVendor, time);
		getline(showVendor, total1);
		cout<<endl;
		}//end whiile
		int choice;
		cout<<"PRESS 1 TO CONTINUE \n";
		cin>>choice;
	}
	else
	cout<<"FILE NOT FOUND \n"; //if file not fou
}

void addProduct();
void showProduct();
void product()
{
	//main menu for product
		system("cls");
	int choice;
	{
		//make choice for product
		cout<<"=========================================== \n";
		cout<<"1. Add Product \n";
		cout<<"2. Show Product \n";
		cout<<"3. Back Main Menu \n";
		cout<<"=========================================== \n";
		cout<<"Enter your required \n"; //make choice
		cin>>choice;
		
		if (choice==1)
		addProduct();
		else if(choice==2)
		showProduct();
	}
}
void addProduct()
{
	//add new product
		system("cls");
		string brandName, brandCode;
	double price;
	
	ofstream addProduct; //declare new file
	addProduct.open("addProduct.txt",ios::app); //open addProduct.txt file
	
	if(addProduct.is_open())//open file
	{
		//start input for new product
		cin.ignore();
		cout<<"Brand Name : ";
		getline(cin, brandName);
		cout<<"Brand Code : ";
		getline(cin, brandCode);
		cout<<"Price:$ ";
		cin>>price;
		{//save input product to addProduct.txt file
			addProduct<<"Brand Name: "<<brandName<<endl;
			addProduct<<"Brand Code: "<<brandCode<<endl;
			addProduct<<"Price :$ "<<price<<endl;
			addProduct<<price<<endl;	
		}
		addProduct.close();	//save and close file
	}
	
	else
	cout<<"FILE NOT FOUND "<<endl;
	
		int choice;
		cout<<"PRESS 1 TO CONTINUE \n";
		cin>>choice;
}

void showProduct()
{
	//show product
		system("cls");
		string brandName, brandCode, price;
	ifstream showProduct; //declare showProduct 
	showProduct.open("addProduct.txt",ios::in);//open addProduct.txt file
	
	if (showProduct.is_open())//open file
	{
		
		while (!showProduct.eof())
		{//start show product until end of file
		cout<<brandName<<endl;
		getline(showProduct, brandName);
		cout<<brandCode<<endl;
		getline(showProduct, brandCode);
		cout<<price<<endl<<endl<<endl;
		getline(showProduct, price);
		}//end show product
		int choice;
		cout<<"PRESS 1 TO CONTINUE \n";
		cin>>choice;
	}
	
	else
	cout<<"FILE NOT FOUND \n";
	
	
//choice if done
	int choice;
		cout<<"PRESS 1 TO CONTINUE \n";
		cin>>choice;
}

void totalCust();
void totalVen();
void totalAll();
void sales()
{
		system("cls");
	int choice;
	{//main menu for total sales
		cout<<"=========================================== \n";
		cout<<"1. Total Customer \n";
		cout<<"2. Total Vendor \n";
		cout<<"3. Total Customer and Vendor \n";
		cout<<"4. Back Main Menu \n";
		cout<<"=========================================== \n";
		cout<<"Enter your required \n";//make choice
		cin>>choice;
		
		if (choice==1)
		totalCust();
		else if(choice==2)
		totalVen();
		else if(choice==3)
		totalAll();
		
	}
}
void totalCust()
{
	//for customer total
		system("cls");
	string name;
	double money, total;
	ifstream totalCustomer("totalCust.txt"); //declare and call totalCust.txt file
	
	if(totalCustomer.is_open())//open file
	{
			cout<<"*********************************************** \n";
		while(totalCustomer>>name>>money) //start show total customer 
		//call from totalCust.txt file
		{
			cout<<name<<":$ "<<money<<endl;
			total+=money;
		}
			cout<<"*********************************************** \n";
		//show total all customer that input from add customer
		cout<<"TOTAL: $ " <<total<<endl;
			cout<<"*********************************************** \n";
	}
	
	else
	cout<<"FILE NOT FOUND";
	
			int choice;
		cout<<"PRESS 1 TO CONTINUE \n";
		cin>>choice;
	
}
void totalVen()
{
	//for vendor total
		system("cls");
	string no;
	double money, total;
	ifstream totalVen("totalVendor.txt"); //declare and call totalVen.txt file
	
	if(totalVen.is_open())
	{
			cout<<"*********************************************** \n";
		while(totalVen>>no>>money) //start show total Vendor form file
		{
			cout<<no<<":$ "<<money<<endl; //show
			total+=money;//for total all
		}
			cout<<"*********************************************** \n";
		cout<<"TOTAL: $ " <<total<<endl; //display total from all vendor
			cout<<"*********************************************** \n";
	}
	
	else
	cout<<"FILE NOT FOUND";
	
			int choice;
		cout<<"PRESS 1 TO CONTINUE \n";
		cin>>choice;
}
void totalAll()
{
	//display total for all customer and vendor
		system("cls");
		string no, name;
	double moneyV, totalV, moneyC, totalC, totalAmount;
	ifstream totalVend("totalVendor.txt");//declare open file
	if(totalVend.is_open()) 
	{
		//display all vendor sales
		cout<<"\t\t TOTAL SALES VENDOR \t\t \n";
		while(totalVend>>no>>moneyV) //start show total vendor
		{
			cout<<no<<":$ "<<moneyV<<endl;
			totalV+=moneyV; //for total vendor it all
		}
	}
	else
	cout<<"FILE NOT FOUND \n";
	
	ifstream totalCusto ("totalCust.txt"); //open and declare total customer file
	if(totalCusto.is_open())
	{
		cout<<"\t\t TOTAL SALES CUSTOMER \t\t \n";
		while(totalCusto>>name>>moneyC) //start  show total cust
		{
			cout<<name<<":$ "<<moneyC<<endl;
			totalC+=moneyC;//for total customer it all
		}
	}
	
	totalAmount=totalV+totalC; //calculate total sales all customer and vendor
	cout<<"*********************************************** \n";
	cout<<endl<<endl<<endl;
	cout<<"TOTAL AMOUNT VENDOR: $ "<<totalV<<endl; //display total amount vendor
	cout<<"TOTAL AMOUNT CUSTOMER: $ "<<totalC<<endl; //display total amount customer
	cout<<"TOTAL AMOUNT VENDOR AND CUSTOMER: $"<<totalAmount<<endl<<endl; //display total amount customer and vendor
	cout<<"*********************************************** \n";
				int choice;
		cout<<"PRESS 1 TO CONTINUE \n";
		cin>>choice;
}
