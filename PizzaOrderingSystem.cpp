#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <iomanip>

using namespace std;

//function prototype declaration
void viewPromo ();
void takeCusInfo (string& , string& , char& , char& );
void viewFlavour (string&, double&, int&, double&, double&, char&);
void viewCrust (string&, double&, int&);
void viewBeverage (string&, double&, int&, double&);
void printReceipt (string, string, char, char,string, double, int, double, double , char, string, double, string, double, int, double, int);
void calcTotalSales (double, double, double, double , char, char);
void viewTotalSales ();
void viewCustSale(double *, int);

//Global variables
double totalSales = 0;
double discountMember = 0;
double plasticBags = 0.20;
double totalPrice = 0;

int main()
{
	string name;
	string telNo;
	char membership;
	char eatOption;
	string flavour;
	double flavourPrice;
	int Fqnty;
	double FtotalPrice;
	double discount;
	char size;
	string crust;
	double crustPrice;
	string beverage;
	double beveragePrice;
	int Bqnty;
	double BtotalPrice;
	double custSale[50];
	int custNo = 0;
	
	//looping for taking order from customers
	char endSystem = 'y';
	while (endSystem != 'n')
	{
		cout<<"****************************************************************************\n";
		cout<<"---------------------------------------------------\n";
		cout<<"|       Customer Pizza Ordering System            |\n";
		cout<<"---------------------------------------------------\n\n";
		
		int option;
		cout<<"Please enter number for desired process:\n";
		cout<<"1. Order\n";
		cout<<"2. Print Receipt\n";
		cout<<"3. !! PROMO FOR TODAY !!\n";
		cout<<"4. View sales by customer number\n";
		cout<<"5. View total sales\n";
		cout<<"6. End system.\n\n";
		cout<<"Option ? : ";
		cin>>option;
		cout<<"\n";
		
		//function will be called according to the input
		//function 1 is for TAKING ORDERS
		if(option == 1)
		{
			takeCusInfo (name, telNo, membership, eatOption);
			viewFlavour (flavour, flavourPrice, Fqnty, FtotalPrice, discount, size);
			viewCrust (crust, crustPrice, Fqnty);
			viewBeverage (beverage, beveragePrice, Bqnty, BtotalPrice);
			calcTotalSales (FtotalPrice, discount, crustPrice, BtotalPrice, eatOption, membership);
			custSale[custNo] = totalPrice;
			cout<<("*** Ordering process done. Proceed with receipt printing. ***\n\n");
			custNo++;
		}
		//function 2 is for PRINTING RECEIPT
		//will print the receipt correctly when an order has been taken
		else if(option == 2)
		{
			printReceipt(name, telNo, membership, eatOption, flavour, flavourPrice, Fqnty, FtotalPrice, discount, size, crust, crustPrice, beverage, beveragePrice, Bqnty, BtotalPrice, custNo);
		}
		//function 3 is for user to see whats the promo for that day
		else if(option == 3)
		{
			viewPromo();
		}
		//function 4 is to view customer's total sale via customer number
		else if(option == 4)
		{	
			viewCustSale(custSale, 50);
		}
		//function 5 is for user to see the total sales for that day
		//totalSales will ONLY be calculated when an order has been taken
		else if(option == 5)
		{
			viewTotalSales();
		}
		
		else if(option == 6)
		{
			endSystem = 'n';
		}
		else
		cout<<("\nINVALID INPUT. Please key in the correct option number.\n\n");	
		
	}
	cout<<("\nThank you for hard work today !!");
	
}

void viewPromo ()
{
	cout<<"\nPROMOTION FOR TODAY !!\n\n";
	cout<<"!! BUY 2 REGULAR PIZZA AT THE PRICE OF 1. !!\n\n";
}


void takeCusInfo (string& name, string& telNo, char& membership, char& eatOption)
{
	
	cout<<"--------------------------------------------------------\n";
	cout<<"|                    Customer Info                     |\n";
	cout<<"--------------------------------------------------------\n\n";
	
	cout<<"Customer name : ";
	getline(cin >> ws, name);
	cout<<"Telephone number : ";
	getline(cin, telNo);
	
	//a member will receive a total of 5% discount from the total price accumulated
	cout<<"Membership? (y/n) : ";
	cin>>membership;
	
	//take away will be charged 20 cents for plastic bags
	cout<<"Dine in or Take away? (d/t) : ";
	cin>>eatOption;
	cout<<"\n\n";
	cin.ignore();
}


void viewFlavour (string& flavour, double& flavourPrice, int& Fqnty, double& FtotalPrice, double& discount, char& size)
{
	char flavourCode,pizzaSize;
	
	cout<<"--------------------------------------------------------\n";
	cout<<"|                 Choose pizza flavour                 |\n";
	cout<<"--------------------------------------------------------\n\n";
	
	cout<<"    Flavour      Code     Mini(RM)  Regular(RM)  Large(RM)\n";
	cout<<"Hawaii Supreme    h        6.70      12.50        16.67\n";
	cout<<"Triple Chicken    t        8.75      13.50        18.45\n";	
	cout<<"Beef Peperoni     b        6.20      11.32        16.70\n";	
	cout<<"Veggie Lover      v        5.35      10.46        14.30\n\n";
	
	cout<<"Enter flavour code   : ";
	cin>>flavourCode;
	cout<<"Pizza size ? (m/r/l) : ";
	cin>>pizzaSize;
	cout<<"Quantity             : ";
	cin>>Fqnty;
	
	//if the customer choose REGULAR pizza size, for every 2 regular pizza will be charged as 1 regular pizza only
	//customer discount initial value is 0
	discount = 0.00;
	if (flavourCode == 'h')
	{
		flavour = "Hawaii Supreme";
		if (pizzaSize == 'm')
			{
				flavourPrice = 6.70;
				size = pizzaSize;
			}
		else if (pizzaSize == 'r')
		{
			flavourPrice = 12.50;
			size = pizzaSize;
			if(Fqnty >= 2)
			{
				discount = (flavourPrice * (Fqnty/2));
			}
		}
		else
			{
				flavourPrice = 16.67;
				size = pizzaSize;
			}
	}
	else if (flavourCode == 't')
	{
		flavour = "Triple Chicken";
		if (pizzaSize == 'm')
			{
				flavourPrice = 8.75;
				size = pizzaSize;
			}
		else if (pizzaSize == 'r')
		{
			flavourPrice = 13.50;
			size = pizzaSize;
			if(Fqnty >= 2)
			{
				discount = (flavourPrice * (Fqnty/2));
			}
		}
		else
			{
				flavourPrice = 18.45;
				size = pizzaSize;
			}
	}
	else if (flavourCode == 'b')
	{
		flavour =  "Beef Peperoni";
		if (pizzaSize == 'm')
			{
				flavourPrice = 6.20;
				size = pizzaSize;
			}
		else if (pizzaSize == 'r')
		{
			flavourPrice = 11.32;
			size = pizzaSize;
			if(Fqnty >= 2)
			{
				discount = (flavourPrice * (Fqnty/2));
			}
		}
		else
			{
				flavourPrice = 16.70;
				size = pizzaSize;
			}
	}
	else
	{
		flavour = "Veggie Lover";
		if (pizzaSize == 'm')
			{
				flavourPrice = 5.35;
				size = pizzaSize;
			}
		else if (pizzaSize == 'r')
		{
			flavourPrice = 10.46;
			size = pizzaSize;
			if(Fqnty >= 2)
			{
				discount = (flavourPrice * (Fqnty/2));
			}
		}
		else
			{
				flavourPrice = 14.30;
				size = pizzaSize;
			}
	}
	
	//total price is calculated before the discount for pizza
	FtotalPrice = flavourPrice * Fqnty;
	cout<<("\n\n");
}


void viewCrust (string& crust, double& crustPrice, int& Fqnty)
{
	char crustCode;
	
	cout<<"--------------------------------------------------------\n";
	cout<<"|                 Choose pizza crust                   |\n";
	cout<<"--------------------------------------------------------\n\n";
	
	cout<<"    Crust        Code     Price(RM)\n";
	cout<<"Cheese             c        3.45\n";
	cout<<"Hand-stretch       h        2.00\n";	
	cout<<"\n";
	cout<<"Enter crust code : ";
	cin>>crustCode;
	
	//crust price will be calculated based on the quantity of pizza ordered
	if(crustCode == 'c')
	{
		crust = "Cheese";
		crustPrice = 3.45 * Fqnty;
	}
	else
	{
		crust = "Hand-stretch";
		crustPrice = 2.00 * Fqnty;
	}
	cout<<("\n\n");
}


void viewBeverage (string& beverage, double& beveragePrice, int& Bqnty, double& BtotalPrice)
{
	char beverageCode;
	
	cout<<"--------------------------------------------------------\n";
	cout<<"|                   Choose beverage                    |\n";
	cout<<"--------------------------------------------------------\n\n";
	
	cout<<"*** All beverages will be served in a large(L) sized cup ***\n\n";
	cout<<"    Beverage    Code     Price(RM)\n";
	cout<<"Pepsi            p        3.45\n";
	cout<<"Coke             c        2.12\n";	
	cout<<"Ice lemon tea    i        4.00\n";	
	cout<<"Sprite           s        3.50\n";	
	cout<<"No beverage      n        0.00\n";	
	cout<<"\n";
	cout<<"Enter beverage code : ";
	cin>>beverageCode;
	
	//if the customer choose 'no beverage', quantity will be automatically set as 0
	if(beverageCode == 'n')
		Bqnty = 0;
	else
	{
		cout<<("Quantity            : ");
		cin>>Bqnty;
	}
	
	if(beverageCode == 'p')
	{
		beverage = "Pepsi";
		beveragePrice = 3.45;
	}
	else if (beverageCode == 'c')
	{
		beverage = "Coke";
		beveragePrice = 2.12;
	}
	else if (beverageCode == 'i')
	{
		beverage = "Ice lemon tea";
		beveragePrice = 4.00;
	}
	else if (beverageCode == 's')
	{
		beverage = "Sprite";
		beveragePrice = 3.50;
	}
	else
	{
		beverage = "No beverage";
		beveragePrice = 0.00;
	}
	
	//calculating total price for beverages
	BtotalPrice = beveragePrice * Bqnty;
	cout<<("\n");
}


void printReceipt (string name, string telNo, char membership, char eatOption, string flavour, double FlavourPrice, int Fqnty, double FtotalPrice, double discount, char size,string crust, double crustPrice,
string beverage, double beveragePrice, int Bqnty, double BtotalPrice, int custNo)
{
	cout<<" *************** OFFICIAL RECEIPT **************** \n\n";
	cout<<" --------------- Customer details ----------------\n";
	cout<<"Name             : "<<name;
	cout<<"\nCust No.         : "<<custNo;
	cout<<"\nTelephone number : "<<telNo;

	if(membership == 'y')
	{
		cout<<"\nMembership       : YES\n";
	}
	else
		cout<<"\nMembership       : NOT A MEMBER\n";
		
	if(eatOption == 't')
	{
		cout<<"Option           : Take away\n";
	}
	else
		cout<<"Option           : Dine in\n";
		
	cout<<"\n--------------------- Order ----------------------\n";
	cout<<"      FnB                      Qnty    Total(RM)\n";
	cout<<"*flavour*\n";
	
	std::cout << std::setprecision(2) << std::fixed;
	
	cout<< flavour <<"("<<size<<")"<<endl;
	std::cout << std::setw (34);
	std::cout << Fqnty;
	std::cout << std::setw (10);
	std::cout << FtotalPrice << std::endl;;
		
	cout<<"\n\n*crust*\n";
	
	cout<<crust<<endl;
	std::cout << std::setw (43);
	std::cout << crustPrice;
	
	cout<<"\n\n*beverage*\n";
	
	cout<<beverage<<endl;
	std::cout << std::setw (34);
	std::cout << Bqnty;
	std::cout << std::setw (10);
	std::cout << BtotalPrice << std::endl;;

	
	cout<<"\n\n";
	if(membership == 'y')
	{
		std::cout<<"* Member discount *                   - "<<discountMember;
	}
	
	if(discount > 0.00)
	{
		std::cout<<"\n* Pizza Promo *                       - "<<discount;
	}
	
	if(eatOption == 't')
	{
		std::cout<<"\n* Plastic bags *                      + "<<plasticBags;
	}
	
	cout<<"\n------------------------------------------------\n";
	std::cout<<"                   Total amount (RM)  : "<<totalPrice;
    cout<<"\n\n *************** OFFICIAL RECEIPT **************** \n\n\n";
    
}

void viewCustSale(double custSale[], int arrSize)
{
	cout<<"--------------------------------------------------------\n";
	int no;
	cout<<"\n\nEnter the customer's number :";
	cin>>no;
	cout<<"The total price of customer number "<<no<<" order is RM"<<custSale[no-1];
	cout<<"\n\n--------------------------------------------------------\n";
	cout<<"\n\n";
}

void viewTotalSales ()
{
	cout<<"--------------------------------------------------------\n";
	cout<<"|                 Total Sales for Today                |\n";
	cout<<"--------------------------------------------------------\n\n";
	
	cout<<"*********************** RM"<<totalSales<<" ***********************\n\n";
	cout<<"Keep up the good work !!\n\n\n";
}


void calcTotalSales (double FtotalPrice, double discount, double crustPrice, double BtotalPrice, char eatOption, char membership)
{
	//take away will be add 20 cents to the total price
	// discount is the discount value for member
	if(eatOption != 't')
		totalPrice = (FtotalPrice + crustPrice + BtotalPrice) - discount;
	else
		totalPrice = (FtotalPrice + crustPrice + BtotalPrice) - discount + plasticBags;
		
	//calculate discount that will be received by customer who is a member
	discountMember = totalPrice * 0.05;
	
	//discount price will be suctracted from the total price
	if(membership == 'y')
	{
		totalPrice = totalPrice * 0.95;
	}
	
	//final total price will added to the total sales for that day
	totalSales = totalSales + totalPrice;	
}

