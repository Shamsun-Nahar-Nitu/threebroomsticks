#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

void currency(float money);
void CenterPrint(const string& text, int width);

int main()
{
    string name, ItemList[12];
    int NumberOfItem, serve[12];
    float serving, TotalPrice = 0, Allprice[12];
    int LineLength = 80;
    char lineSymbol = '-';
    string line(LineLength, lineSymbol);
    string shopName = "The Three Broomsticks";
    string greeting1 = "Head Inside for a Warm Hearty Meal!";
    string ShopAddress = "The Wizarding World, Hogwarts,Hogsmeade";
    string greeting2 = "Thank You for visiting us. Have a wonderful day!";
    string itemNo[6] = {"Fresh-brewed coffee", "Macaroni & Cheese", "Butterbeer (Non-Alcoholic)", "Chocolate Trifle", "Seasoned Wedge Fries", "Iced Tea"};
    float price[6] = {30.49, 150.50, 50, 100, 45, 15.99};

    cout << line << endl;
    CenterPrint(shopName, LineLength);
    CenterPrint(greeting1, LineLength);
    cout << line << endl;

    cout << "What is your name? ";
    getline(cin, name);

    cout << "We are glad to have you here, " << name << "! This is our menu for today!\n";

    for (int i = 0; i < 6; i++)
    {
        cout << i + 1 << ". " << left << setw(30) << itemNo[i] 
             << " -------  BDT  " << fixed << setprecision(2) << right << setw(6) << price[i] << endl;
    }

    cout << "How many different items do you want to order? ";
    cin >> NumberOfItem;

    if (NumberOfItem > 0 && NumberOfItem < 7)
    {
        cout << "Alright! Enter the serial numbers of the items you want to order:" << endl;

        for (int i = 0; i < NumberOfItem; i++)
        {
            int j;
            cout << "Item Serial Number: ";
            cin >> j;
            ItemList[i] = itemNo[j - 1];
            cout << "Your Item - " << left << setw(30) << ItemList[i] 
                 << " How many servings? ";
            cin >> serving;
            serve[i] = serving;
            Allprice[i] = price[j - 1] * serving;
            TotalPrice += Allprice[i];
        }

        float vat = TotalPrice * 5 / 100;
        float TotalAmount = TotalPrice + vat;

    S:
        cout << endl
             << "Your Bill is         :  BDT  " << fixed << setprecision(2) << TotalAmount << endl
             << "Enter your bill here :  BDT  ";
        float paid;
        cin >> paid;

        if (paid >= TotalAmount)
        {
            string location;
            cout << "Please, provide us your address. So that we can deliver the parcel : " << endl;
            cin.ignore();
            getline(cin, location);

            cout << line << "\n";
            CenterPrint(shopName, LineLength);
            CenterPrint(ShopAddress, LineLength);
            cout << line << endl;

            cout << "Customer Name : " << name << endl
                 << "Address       : " << location << endl
                 << line << endl
                 << "Order Details :" << endl;

            for (int i = 0; i < NumberOfItem; i++)
            {
                cout << left << setw(27) << ItemList[i] 
                     << " ----- Serving: " << serve[i] 
                     << " ----- Price:  BDT  " << fixed << setprecision(2) << right << setw(6) << Allprice[i] << endl;
            }

            cout << line << endl
                 << "Total Price                : BDT " << fixed << setprecision(2) << TotalPrice << endl
                 << "VAT for your purchase (5%) : BDT " << vat << endl
                 << line << endl
                 << "Total Price with 5% VAT    : BDT " << TotalAmount << endl
                 << "Your Payment               : BDT " << paid << endl;

            float returned = paid - TotalAmount;
            cout << line << endl
                 << "Returned Money             : BDT " << fixed << setprecision(2) << returned << endl
                 << "Please, make sure that you have recieved : " << endl;

            currency(returned);

            cout << line << endl;
            CenterPrint(greeting2, LineLength);
            cout << line << endl;
        }
        else
        {
            cout << "Please pay the bill that has been charged!\n";
            goto S;
        }
    }
    else
    {
        cout << "We are sorry for not meeting your requirement. \n"
             << "Hope you find something you like the next time you visit us " << name << '!' << endl;
    }

    return 0;
}

void CenterPrint(const string& text, int width)
{
    int padding = (width - text.length()) / 2;
    cout << setw(padding + text.length()) << text << endl;
}

void currency(float money)
{
    if (money < 0.01) {
        cout << "No change required." << endl;
        return;
    }

    int NoteValue[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int NumberOfNote[10] = {0};

    int int_money = floor(money);
    for (int i = 0; i < 10; i++)
    {
        NumberOfNote[i] = int_money / NoteValue[i];
        int_money -= NumberOfNote[i] * NoteValue[i];
    }

    int cents = round((money - floor(money)) * 100);

    for (int i = 0; i < 10; i++)
    {
        if (NumberOfNote[i] > 0)
            cout << "Note of " << setw(4) << NoteValue[i] << " TK : " << NumberOfNote[i] << endl;
    }
    cout << "Cents           : " << cents << endl;
}