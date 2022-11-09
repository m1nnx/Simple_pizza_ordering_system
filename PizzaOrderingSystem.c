#include <stdio.h>
#include <string.h>

//function prototype declaration
void viewPromo ();
void takeCusInfo ();
void viewFlavour ();
void viewCrust ();
void viewBeverage ();
void printReceipt ();
void viewTotalSales ();
void calcTotalSales ();


//*IMPORTANT NOTES*
//struct is used to store customer information ONLY for printing receipt purposes
//it will be deleted once a new order comes in
//struct is declared as GLOBAL so that it is easy for any functions to use it
struct CustomerInfo
{
	char name[50];
	char telNo[15];
	char membership;
	char eatOption;
};
struct CustomerInfo Cus;


struct CusFlavour
{
	char flavour[30];
	double price;
	int qnty;
	double totalPrice;
	double discount; 
	char size;
};
struct CusFlavour Cus2;


struct Crust
{
	char crust[30];
	double price;
};
struct Crust Cus3;


struct Beverage
{
	char beverage[30];
	double price;
	int qnty;
	double totalPrice;
};
struct Beverage Cus4;

//totalSales is declared as GLOBAL so that any functions can use it
//the value will reset when the system ends
double totalSales = 0;
double discount = 0;
double plasticBags = 0.20;
double totalPrice = 0;



int main()
{
	//looping for taking order from customers
	char endSystem = 'y';
	while (endSystem != 'n')
	{
		printf("****************************************************************************\n");
		printf("---------------------------------------------------\n");
		printf("|       Customer Pizza Ordering System            |\n");
		printf("---------------------------------------------------\n\n");
		
		int option;
		printf("1. Order\n");
		printf("2. Print Receipt\n");
		printf("3. !! PROMO FOR TODAY !!\n");
		printf("4. View total sales\n");
		printf("5. End system.\n\n");
		printf("Option ? : ");
		scanf(" %d",&option);
		printf("\n");
		
		//function will be called according to the input
		//function 1 is for TAKING ORDERS
		if(option == 1)
		{
			takeCusInfo ();
			viewFlavour ();
			viewCrust ();
			viewBeverage ();
			calcTotalSales ();
			printf("*** Ordering process done. Proceed with receipt printing. ***\n\n");
		}
		//function 2 is for PRINTING RECEIPT
		//will print the receipt correctly when an order has been taken
		else if(option == 2)
		{
			printReceipt ();
		}
		//function 3 is for user to see whats the promo for that day
		else if(option == 3)
		{
			viewPromo();
		}
		//function 4 is for user to see the total sales for that day
		//totalSales will ONLY be calculated when an order has been taken
		else if(option == 4)
		{
			viewTotalSales();
		}
		
		else if(option == 5)
		{
			endSystem = 'n';
		}
		else
		printf("\nINVALID INPUT. Please key in the correct option number.\n\n");	
	}
	printf("\nThank you for hard work today !!");
	
}


void viewPromo ()
{
	printf("\nPROMOTION FOR TODAY !!\n\n");
	printf("!! BUY 2 REGULAR PIZZA AT THE PRICE OF 1. !!\n\n");
}


void takeCusInfo ()
{
	char name[50];
	printf("--------------------------------------------------------\n");
	printf("|                    Customer Info                     |\n");
	printf("--------------------------------------------------------\n\n");
	
	printf("Customer name : ");
	getchar();
	fgets(Cus.name,50,stdin);
	printf("Telephone number : ");
	scanf("%s",Cus.telNo);
	
	//a member will receive a total of 5% discount from the total price accumulated
	printf("Membership? (y/n) : ");
	scanf("%s",&Cus.membership);
	
	//take away will be charged 20 cents for plastic bags
	printf("Dine in or Take away? (d/t) : ");
	scanf("%s",&Cus.eatOption);
	printf("\n\n");
}


void viewFlavour ()
{
	char flavourCode,pizzaSize;
	
	printf("--------------------------------------------------------\n");
	printf("|                 Choose pizza flavour                 |\n");
	printf("--------------------------------------------------------\n\n");
	
	printf("    Flavour      Code     Mini(RM)  Regular(RM)  Large(RM)\n");
	printf("Hawaii Supreme    h        6.70      12.50        16.67\n");
	printf("Triple Chicken    t        8.75      13.50        18.45\n");	
	printf("Beef Peperoni     b        6.20      11.32        16.70\n");	
	printf("Veggie Lover      v        5.35      10.46        14.30\n\n");
	
	printf("Enter flavour code   : ");
	scanf(" %c",&flavourCode);
	printf("Pizza size ? (m/r/l) : ");
	scanf(" %c",&pizzaSize);
	printf("Quantity             : ");
	scanf("%d",&Cus2.qnty);
	
	//if the customer choose REGULAR pizza size, for every 2 regular pizza will be charged as 1 regular pizza only
	//customer discount initial value is 0
	Cus2.discount = 0.00;
	if (flavourCode == 'h')
	{
		strcpy(Cus2.flavour,"Hawaii Supreme");
		if (pizzaSize == 'm')
			{
				Cus2.price = 6.70;
				Cus2.size = pizzaSize;
			}
		else if (pizzaSize == 'r')
		{
			Cus2.price = 12.50;
			Cus2.size = pizzaSize;
			if(Cus2.qnty >= 2)
			{
				Cus2.discount = (Cus2.price * (Cus2.qnty/2));
			}
		}
		else
			{
				Cus2.price = 16.67;
				Cus2.size = pizzaSize;
			}
	}
	else if (flavourCode == 't')
	{
		strcpy(Cus2.flavour,"Triple Chicken");
		if (pizzaSize == 'm')
			{
				Cus2.price = 8.75;
				Cus2.size = pizzaSize;
			}
		else if (pizzaSize == 'r')
		{
			Cus2.price = 13.50;
			Cus2.size = pizzaSize;
			if(Cus2.qnty >= 2)
			{
				Cus2.discount = (Cus2.price * (Cus2.qnty/2));
			}
		}
		else
			{
				Cus2.price = 18.45;
				Cus2.size = pizzaSize;
			}
	}
	else if (flavourCode == 'b')
	{
		strcpy(Cus2.flavour,"Beef Peperoni");
		if (pizzaSize == 'm')
			{
				Cus2.price = 6.20;
				Cus2.size = pizzaSize;
			}
		else if (pizzaSize == 'r')
		{
			Cus2.price = 11.32;
			Cus2.size = pizzaSize;
			if(Cus2.qnty >= 2)
			{
				Cus2.discount = (Cus2.price * (Cus2.qnty/2));
			}
		}
		else
			{
				Cus2.price = 16.70;
				Cus2.size = pizzaSize;
			}
	}
	else
	{
		strcpy(Cus2.flavour,"Veggie Lover");
		if (pizzaSize == 'm')
			{
				Cus2.price = 5.35;
				Cus2.size = pizzaSize;
			}
		else if (pizzaSize == 'r')
		{
			Cus2.price = 10.46;
			Cus2.size = pizzaSize;
			if(Cus2.qnty >= 2)
			{
				Cus2.discount = (Cus2.price * (Cus2.qnty/2));
			}
		}
		else
			{
				Cus2.price = 14.30;
				Cus2.size = pizzaSize;
			}
	}
	
	//total price is calculated before the discount for pizza
	Cus2.totalPrice = Cus2.price * Cus2.qnty;
	printf("\n\n");
}


void viewCrust ()
{
	char crustCode;
	
	printf("--------------------------------------------------------\n");
	printf("|                 Choose pizza crust                   |\n");
	printf("--------------------------------------------------------\n\n");
	
	printf("    Crust        Code     Price(RM)\n");
	printf("Cheese             c        3.45\n");
	printf("Hand-stretch       h        2.00\n");	
	printf("\n");
	printf("Enter crust code : ");
	scanf(" %c",&crustCode);
	
	//crust price will be calculated based on the quantity of pizza ordered
	if(crustCode == 'c')
	{
		strcpy(Cus3.crust,"Cheese");
		Cus3.price = 3.45 * Cus2.qnty;
	}
	else
	{
		strcpy(Cus3.crust,"Hand-stretch");
		Cus3.price = 2.00 * Cus2.qnty;
	}
	printf("\n\n");
}


void viewBeverage ()
{
	char beverageCode;
	
	printf("--------------------------------------------------------\n");
	printf("|                   Choose beverage                    |\n");
	printf("--------------------------------------------------------\n\n");
	
	printf("*** All beverages will be served in a large(L) sized cup ***\n\n");
	printf("    Beverage    Code     Price(RM)\n");
	printf("Pepsi            p        3.45\n");
	printf("Coke             c        2.12\n");	
	printf("Ice lemon tea    i        4.00\n");	
	printf("Sprite           s        3.50\n");	
	printf("No beverage      n        0.00\n");	
	printf("\n");
	printf("Enter beverage code : ");
	scanf(" %c",&beverageCode);
	
	//if the customer choose 'no beverage', quantity will be automatically set as 0
	if(beverageCode == 'n')
		Cus4.qnty = 0;
	else
	{
		printf("Quantity            : ");
		scanf(" %d",&Cus4.qnty);
	}
	
	if(beverageCode == 'p')
	{
		strcpy(Cus4.beverage,"Pepsi");
		Cus4.price = 3.45;
	}
	else if (beverageCode == 'c')
	{
		strcpy(Cus4.beverage,"Coke");
		Cus4.price = 2.12;
	}
	else if (beverageCode == 'i')
	{
		strcpy(Cus4.beverage,"Ice lemon tea");
		Cus4.price = 4.00;
	}
	else if (beverageCode == 's')
	{
		strcpy(Cus4.beverage,"Sprite");
		Cus4.price = 3.50;
	}
	else
	{
		strcpy(Cus4.beverage,"No beverage");
		Cus4.price = 0.00;
	}
	
	//calculating total price for beverages
	Cus4.totalPrice = Cus4.price * Cus4.qnty;
	printf("\n");
}


void printReceipt ()
{
	printf(" *************** OFFICIAL RECEIPT **************** \n\n");
	printf(" --------------- Customer details ----------------\n");
	printf("Name             : %s",Cus.name);
	printf("Telephone number : %s\n",Cus.telNo);

	if(Cus.membership == 'y')
	{
		printf("Membership       : YES\n");
	}
	else
		printf("Membership       : NOT A MEMBER\n");
		
	if(Cus.eatOption == 't')
	{
		printf("Option           : Take away\n");
	}
	else
		printf("Option           : Dine in\n");
		
	printf("\n--------------------- Order ----------------------\n");
	printf("      FnB                      Qnty    Total(RM)\n");
	printf("*flavour*\n");
		
	if((strcmp(Cus2.flavour,"Beef Peperoni")) == 0 )
		printf("%s (%c)               %d        %0.2f\n",Cus2.flavour,Cus2.size,Cus2.qnty,Cus2.totalPrice);
	else if ((strcmp(Cus2.flavour,"Veggie Lover")) == 0)
		printf("%s (%c)                %d        %0.2f\n",Cus2.flavour,Cus2.size,Cus2.qnty,Cus2.totalPrice);
	else
		printf("%s (%c)              %d        %0.2f\n",Cus2.flavour,Cus2.size,Cus2.qnty,Cus2.totalPrice);
		
	printf("\n*crust*\n");
	if ((strcmp(Cus3.crust,"Cheese")) == 0)
		printf("%s                                   %0.2f\n",Cus3.crust,Cus3.price);
	else
		printf("%s                             %0.2f\n",Cus3.crust,Cus3.price);
		
	printf("\n*beverage*\n");
	if ((strcmp(Cus4.beverage,"Pepsi")) == 0)
		printf("%s                           %d        %0.2f\n",Cus4.beverage,Cus4.qnty,Cus4.totalPrice);
	else if ((strcmp(Cus4.beverage,"Coke")) == 0)
		printf("%s                            %d        %0.2f\n",Cus4.beverage,Cus4.qnty,Cus4.totalPrice);
	else if ((strcmp(Cus4.beverage,"Ice lemon tea")) == 0)
		printf("%s                   %d        %0.2f\n",Cus4.beverage,Cus4.qnty,Cus4.totalPrice);
	else if ((strcmp(Cus4.beverage,"Sprite")) == 0)
		printf("%s                          %d        %0.2f\n",Cus4.beverage,Cus4.qnty,Cus4.totalPrice);
	else
		printf("%s                     %d        %0.2f\n",Cus4.beverage,Cus4.qnty,Cus4.totalPrice);
	
	
	printf("\n");
	if(Cus.membership == 'y')
	{
		printf("* Member discount *                   - (%0.2f)\n",discount);
	}
	
	
	if(Cus2.discount > 0.00)
	{
		printf("* Pizza Promo *                       - (%0.2f)\n",Cus2.discount);
	}
	
	if(Cus.eatOption == 't')
	{
		printf("* Plastic bags *                      + (%0.2f)\n",plasticBags);
	}
	
	printf("------------------------------------------------\n");
	printf("                    Total amount (RM)  : %0.2f\n\n",totalPrice);
    printf(" *************** OFFICIAL RECEIPT **************** \n\n\n");
	
}


void viewTotalSales ()
{
	printf("--------------------------------------------------------\n");
	printf("|                 Total Sales for Today                |\n");
	printf("--------------------------------------------------------\n\n");
	
	printf("*********************** RM %0.2f ***********************\n\n",totalSales);
	printf("Keep up the good work !!\n\n\n");
}


void calcTotalSales ()
{
	//take away will be add 20 cents to the total price
	// CUs2.discount is the discount value for pizza promotion
	if(Cus.eatOption != 't')
		totalPrice = (Cus2.totalPrice + Cus3.price + Cus4.totalPrice) - Cus2.discount;
	else
		totalPrice = (Cus2.totalPrice + Cus3.price + Cus4.totalPrice) - Cus2.discount + plasticBags;
		
	//calculate discount that will be received by customer who is a member
	discount = totalPrice * 0.05;
	
	//discount price will be suctracted from the total price
	if(Cus.membership == 'y')
	{
		totalPrice = totalPrice * 0.95;
	}
	
	//final total price will added to the total sales for that day
	totalSales = totalSales + totalPrice;	
}
