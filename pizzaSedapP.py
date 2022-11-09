
#dictionary for CustomerInfo
CustomerInfo={}
#dictionary for CusFlavour
CusFlavour={}
#dictionary for Crust
Crust ={}
#dictionary for Beverage
Beverage = {}

#totalSales, totalprice, discount and plasticBags is declared as GLOBAL VARIABLE so that any functions can use it
#the value will reset when the system ends
totalSales = 0
discount = 0
plasticBags = 0.20
totalPrice = 0

def viewPromo():
    print "\nPROMOTION FOR TODAY !!\n\n"
    print "!! BUY 2 REGULAR PIZZA AT THE PRICE OF 1. !!\n"

def takeCusInfo():
    print "\n-------------------------------------------"
    print "|            Customer Info                 |"
    print "-------------------------------------------\n"

    CustomerInfo["name"]= raw_input("Customer name : ")
    CustomerInfo["telNo"] = raw_input("Telephone number : ")

    #a member will receive a total of 5% discount from the total price accumulated
    membership = raw_input("Membership? (y/n) : ")
    CustomerInfo["membership"] = membership

    #take away will be charged 20 cents for plastic bags
    eatOption = raw_input("Dine in or Take away? (d/t) : ")
    CustomerInfo["eatOption"] = eatOption
    print "\n"

    return CustomerInfo
    
def viewFlavour():

    #the dictionary is inside the main to make it global variable
    #key: "The quantity", "The flavour", "The price", "The discount", "Total Price"
    #value is inserted by the user
    
    print "-------------------------------------------"
    print "|            Choose Pizza Flavour           |"
    print "-------------------------------------------\n"
    print "  flavour        code   Mini(RM)   Regular(RM)   Large(RM)"
    print "Hawaii Supreme    h      6.70       12.50        16.67"
    print "Triple Chicken    t      8.75       13.50        18.45"	
    print "Beef Peperoni     b      6.20       11.32        16.70"	
    print "Veggie Lover      v      5.35       10.46        14.30\n"

    flavourCode = raw_input("Enter flavour code : ")
    pizzaSize = raw_input("Pizza size ? (m/r/l) : ")
    
    #to insert the quantity into CusFlavour dictionary
    CusFlavour["qnty"] = float(raw_input("Quantity : "))

    #if the customer choose REGULAR pizza size, for every 2 regular pizza will be charged as 1 regular pizza only
    #customer discount initial value is 0
    #customer ordered pizza flavour, price, size, quantity, promo discount and total price will be inserted into CusFlavour dictionary
    CusFlavour["discount"] = 0.00
    if flavourCode == 'h':
        #to insert the flavour into cusFlavour dictionary
        CusFlavour["flavour"]= "Hawaii Supreme"
        if pizzaSize == 'm':
            CusFlavour["price"]= 6.70
            CusFlavour["size"] = pizzaSize
        elif pizzaSize == 'r':
            CusFlavour["price"]= 12.50
            CusFlavour["size"] = pizzaSize
            if(CusFlavour["qnty"] >= 2):
                CusFlavour["discount"] = (CusFlavour["price"] * (CusFlavour["qnty"]/2))
        else:
            CusFlavour["price"] = 16.67
            CusFlavour["size"] = pizzaSize
            
    elif flavourCode=='t':
        CusFlavour["flavour"]= "Triple Chicken"
        if pizzaSize=='m':
            CusFlavour["price"]= 8.75
            CusFlavour["size"] = pizzaSize
        elif pizzaSize=='r':
            CusFlavour["price"]= 13.50
            CusFlavour["size"] = pizzaSize
            if(CusFlavour["qnty"] >= 2):
                CusFlavour["discount"] = (CusFlavour["price"] * (CusFlavour["qnty"]/2))
        else:
            CusFlavour["price"]= 18.45
            CusFlavour["size"] = pizzaSize
            
    elif flavourCode=='b':
        CusFlavour["flavour"]= "Beef Peperoni"
        if pizzaSize=='m':
            CusFlavour["price"]= 16.20
            CusFlavour["size"] = pizzaSize
        elif pizzaSize=='r':
            CusFlavour["price"]= 11.32
            CusFlavour["size"] = pizzaSize
            if(CusFlavour["qnty"] >= 2):
                CusFlavour["discount"] = (CusFlavour["price"] * (CusFlavour["qnty"]/2))
        else:
            CusFlavour["price"]= 16.70
            CusFlavour["size"] = pizzaSize
        
    else:
        CusFlavour["flavour"]= "Veggie Lover"
        if pizzaSize=='m':
            CusFlavour["price"]= 5.35
            CusFlavour["size"] = pizzaSize
        elif pizzaSize=='r':
            CusFlavour["price"]= 10.46
            CusFlavour["size"] = pizzaSize
            if(CusFlavour["qnty"] >= 2):
                CusFlavour["discount"] = (CusFlavour["price"] * (CusFlavour["qnty"]/2))
        else:
            CusFlavour["price"]= 14.30
            CusFlavour["size"] = pizzaSize

    #calculate and insert total price before discount for pizza into CusFlavour dictionary
    CusFlavour["totalPrice"]= CusFlavour["price"] * CusFlavour["qnty"]
    print "\n" 
    return CusFlavour

def viewCrust():
    print "--------------------------------------------------------"
    print "|                 Choose pizza crust                   |"
    print "--------------------------------------------------------\n"
    print "    Crust        Code     Price(RM)"
    print "Cheese             c        3.45"
    print "Hand-stretch       h        2.00\n"

    crustCode = raw_input ("Enter crust code : ")

    #crust price will be calculated based on the quantity of pizza ordered
    #customer desired pizza crust and crust price will be inserted into Crust dictionary
    if crustCode=='c':
       #insert "Cheese" into crust dictionary
       Crust["crust"]= "Cheese"
       #insert the crust price into crust dictionary
       Crust["price"] = 3.45 * CusFlavour["qnty"] 
    else:
       Crust["crust"]= "Hand-stretch"
       Crust["price"]= 2.00 * CusFlavour["qnty"] 
    print "\n"
    
    return Crust

def viewBeverage():
    print "-------------------------------------------------"
    print "|                  Choose beverage              |"
    print "-------------------------------------------------\n"
    print "*** All beverages will be served in a large(L) sized cup ***\n"
    print "  Beverage     Code    Price(RM)\n"
    print "Pepsi           p        3.45"
    print "Coke            c        2.12"
    print "Ice lemon tea   i        4.00"
    print "Sprite          s        3.50"
    print "No beverage     n        0.00"
    print "\n"

    beverageCode = raw_input("Enter beverage code : ")

    #if the customer choose 'no beverage', quantity will be automatically set as a 0
    if beverageCode == 'n':
        Beverage["qnty"] = 0
    else:
        Beverage["qnty"] = int(raw_input("Quantity    : "))

    #customer ordered beverage, beverage price and quantity will be inserted into Beverage dictionary
    if beverageCode == 'p':
        Beverage["beverage"] = "Pepsi"
        Beverage["price"] = 3.45
    elif beverageCode == 'c':
        Beverage["beverage"] = "Coke"
        Beverage["price"] = 2.12
    elif beverageCode == 'i':
        Beverage["beverage"] = "Ice lemon tea"
        Beverage["price"] = 4.00
    elif beverageCode == 's':
        Beverage["beverage"] = "Sprite"
        Beverage["price"] = 3.50
    else:
        Beverage["beverage"] = "No beverage"
        Beverage["price"] = 0.00

    #calculating total price for beverages
    Beverage["totalPrice"] = Beverage["price"] * Beverage["qnty"]
    print "\n"

    return Beverage

#function to diaplay customer's order receipt
def printReceipt():
    global discount
    global totalPrice
    global plasticBags
    
    print "\n *************** OFFICIAL RECEIPT **************** \n"
    print " --------------- Customer details ----------------"
    print " Name             :", CustomerInfo["name"]
    print " Telephone number :", CustomerInfo["telNo"]
    
    if CustomerInfo["membership"] == 'y':
        print " Membership       : YES"
    else:
        print " Membership       : NOT A MEMBER"

    if CustomerInfo["eatOption"] == 't':
        print " Option           : Take away"
    else:
        print " Option           : Dine in"

    print "\n--------------------- Order ----------------------"
    print "      FnB                      Qnty    Total(RM)"
    print " *flavour*"

    if CusFlavour["flavour"] == "Beef Peperoni":
        print " ",CusFlavour["flavour"],"(",CusFlavour["size"],")","         ",('%.0f' %CusFlavour["qnty"]),"     ",('%.2f' %CusFlavour["totalPrice"])
    elif CusFlavour["flavour"]== "Veggie Lover":
        print " ",CusFlavour["flavour"],"(",CusFlavour["size"],")","          ",('%.0f' %CusFlavour["qnty"]),"     ",('%.2f' %CusFlavour["totalPrice"])
    else:
        print " ",CusFlavour["flavour"],"(",CusFlavour["size"],")","        ",('%.0f' %CusFlavour["qnty"]),"     ",('%.2f' %CusFlavour["totalPrice"])

    print " \n*crust*"
    if Crust["crust"] == "Cheese":
        print " ",Crust["crust"],"                              ",('%.2f' %Crust["price"])
    else:
        print  " ",Crust["crust"],"                        ",('%.2f' %Crust["price"])

    print " \n*beverage*"
    if Beverage["beverage"] == "Pepsi":
        print  " ",Beverage["beverage"],"                       ",Beverage["qnty"],"     ",('%.2f' %Beverage["totalPrice"])
    elif Beverage["beverage"] == "Coke":
        print  " ",Beverage["beverage"],"                        ",Beverage["qnty"],"     ",('%.2f' %Beverage["totalPrice"])
    elif Beverage["beverage"] == "Ice lemon tea":
        print  " ",Beverage["beverage"],"               ",Beverage["qnty"],"     ",('%.2f' %Beverage["totalPrice"])
    elif Beverage["beverage"] == "Sprite":
        print  " ",Beverage["beverage"],"                      ",Beverage["qnty"],"     ",('%.2f' %Beverage["totalPrice"])
    else:
        print  " ",Beverage["beverage"],"                 ",Beverage["qnty"],"     ",('%.2f' %Beverage["totalPrice"])

    if CustomerInfo["membership"] == 'y':
        print "* Member discount *                - ","(", ('%.2f' %discount),")"

    if CusFlavour["discount"] > 0:
        print "* Pizza Promo *                    - ","(", ('%.2f' %CusFlavour["discount"]),")"

    if CustomerInfo["eatOption"] == 't':
        print "* Plastic bags *                   + ","(", ('%.2f' %plasticBags),")"
    
    print "------------------------------------------------"
    print "                   Total amount (RM)  :",('%.2f' %totalPrice)
    print "\n *************** OFFICIAL RECEIPT **************** \n\n"

#function to view total sales for a day
def viewTotalSales():
    global totalSales
    print "\n--------------------------------------------------------"
    print "|                 Total Sales for Today                |"
    print "--------------------------------------------------------\n"
	
    print "*********************** RM ",totalSales," ***********************\n"
    print "Keep up the good work !!\n\n"

#function to calculate pizza total price, discount and total sales for a day
def calcTotalSales():
    
    global totalSales
    global discount
    global totalPrice 

    #take away will be add 20 cents to the total price
    #CusFlavour["discount"] is the discount value for pizza promotion
    if CustomerInfo["eatOption"] != 't':
        totalPrice = round(( CusFlavour["totalPrice"] + Crust["price"] + Beverage["totalPrice"] ) - CusFlavour["discount"], 2)
    else:
        totalPrice = round(( CusFlavour["totalPrice"] + Crust["price"] + Beverage["totalPrice"] ) - CusFlavour["discount"] + plasticBags, 2)

    #calculate discount that will be received by customer who is a member, for display in receipt
    discount = round(totalPrice * 0.05, 2)

    #discount price will be suctracted from the total price
    if CustomerInfo["membership"] == 'y':
        totalPrice = round(totalPrice * 0.95, 2)

    #final total price will added to the total sales for that day (cumulative sales)
    totalSales = round(totalSales + totalPrice, 2)
    
# main routine

#Use while loop for taking order from customers
endSystem = 'y'
while endSystem != 'n':

    print "****************************************************"
    print "--------------------------------------------"
    print "      Customer Pizza Ordering System        "
    print "--------------------------------------------\n"
    print "Enter option:"
    print "1. Order"
    print "2. Print Receipt"
    print "3. !! PROMO FOR TODAY!!"
    print "4. View total sales"
    print "5. End System.\n"

    option = raw_input("Option : ")

    #function will be called according to the input
    #function 1 is for TAKING ORDERS
    if option == '1':
        takeCusInfo()
        viewFlavour()
        viewCrust()
        viewBeverage()
        calcTotalSales()
        print "*** Ordering process done. Proceed with receipt printing. ***\n"
    #function 2 is for PRINTING RECEIPT
    #will print the receipt correctly when an order has been taken
    elif option == '2':
        printReceipt()
    #function 3 is for user to see whats the promo for that day
    elif option == '3':
        viewPromo();
    #function 4 is for user to see the total sales for that day
    #totalSales will ONLY be calculated when an order has been taken
    elif option == '4':
        viewTotalSales()
    #code 5 is for ending the system, wrap the day
    elif option == '5':
        endSystem='n'
    #invalid input notice
    else:
        print"\nINVALID INPUT. Please key in the correct option number.\n"
    
print "\nThank you for your hard work today !!"
