#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;

//structure to store the drinks type

struct drinkType
{
    string name;
    string code;
    double price;
    int remaining;
};

//read items from the file

int readItems(ifstream &inFile, drinkType drinks[])
{
    int index = 0;
    string name, code;
    double price;
    int remaining;
    while(!(inFile.eof()))
    {
        inFile >> name >> code >> remaining >> price;
        drinks[index].name = name;
        drinks[index].code = code;
        drinks[index].remaining = remaining;
        drinks[index].price = price;
        index++;
    }
    return index; //return the size of the list
}

void outputItem(string name, string itemCode, int remaining, double price)
{
    //output items to screen
    cout << setw(20) << name << setw(20) << itemCode << setw(20) << remaining << setw(20) << price << endl;
}

int purchaseItem(int size, drinkType drinks[], string code)
{
    int totalSold = 0;
    for(int i = 0; i < size; i++)
    {
        if(drinks[i].code == code)
        {
            if (drinks[i].remaining == 0)
            {
                cout << "Item sold out" << endl;
                break;
            }
            else{
                drinks[i].remaining -= 1;
                totalSold++;
                ofstream myfile ("order.txt");
                if (myfile.is_open())
                {
                    for(int i = 0; i < size; i++)
                    { //print all the items in the list
                        myfile << drinks[i].name << " " << drinks[i].code << " " << drinks[i].remaining << " " << drinks[i].price << endl;
                    }
                }
                myfile.close();
            }

            double moneyInserted;
            cout << "Enter money you want to insert : ";
            cin >> moneyInserted;
            if(moneyInserted >= drinks[i].price)
            {
                //change is displayed to the user
                cout << "Change : $ " << moneyInserted - drinks[i].price << "\n";
                cout << "Take your drink !" << endl;
            }
            else
                cout << "Insufficient Funds\n";

            if (moneyInserted < drinks[i].price){
                drinks[i].remaining += 1;
                ofstream myfile ("order.txt");
                if (myfile.is_open())
                {
                    for(int i = 0; i < size; i++)
                    { //print all the items in the list
                        myfile << drinks[i].name << " " << drinks[i].code << " " << drinks[i].remaining << " " << drinks[i].price << endl;
                    }
                }
                myfile.close();
            }
            return totalSold;
        }
    }
    return totalSold;
}

void insertItem(ifstream &inFile, drinkType drinks[]){
    int index = 0;
    string n, c;
    double p;
    int r;
    int i;
    index = readItems(inFile, drinks); //index stores the size of the item list

    for(i = 0; i < index-1; i++)
    { //print all the items in the list
        outputItem(drinks[i].name, drinks[i].code, drinks[i].remaining, drinks[i].price);
    }

    cout << "Enter new drink name: ";
    cin >> n;
    cout << "Enter " << n << " code: ";
    cin >> c;
    cout << "Enter " << n << " remaining: ";
    cin >> r;
    cout << "Enter " << n << " price: ";
    cin >> p;

    drinks[index].name = n;
    drinks[index].code = c;
    drinks[index].remaining = r;
    drinks[index].price = p;
    index ++;

    ofstream myfile ("order.txt");
    if (myfile.is_open())
    {
        for(int i = 0; i < index; i++)
        { //print all the items in the list
            myfile << drinks[i].name << " " << drinks[i].code << " " << drinks[i].remaining << " " << drinks[i].price << endl;
        }
    }
    myfile.close();

}

void updatePrice(ifstream &inFile, drinkType drinks[]){
    int index = 0, i;
    string c;
    double p;
    index = readItems(inFile, drinks); //index stores the size of the item list
    for(i = 0; i < index; i++)
    { //print all the items in the list
        outputItem(drinks[i].name, drinks[i].code, drinks[i].remaining, drinks[i].price);
    }
    cout << endl << "Enter the code you want to change the price for: ";
    cin >> c;
    cout << "Enter the new price for that code: ";
    cin >> p;
    for(i = 0; i < index; i++)
    {
        if (drinks[i].code == c)
            drinks[i].price = p;
    }
    ofstream myfile ("order.txt");
    if (myfile.is_open())
    {
        for(int i = 0; i < index; i++)
        { //print all the items in the list
            myfile << drinks[i].name << " " << drinks[i].code << " " << drinks[i].remaining << " " << drinks[i].price << endl;
        }
    }
    myfile.close();
}

int purchase(){
    int index = 0;
    int MAX_ITEMS = 20;
    drinkType drinks[MAX_ITEMS];
    string filename = "order.txt";
    ifstream inFile;
    inFile.open(filename.c_str());
    int totalSold;
    index = readItems(inFile, drinks); //index stores the size of the item list
    string code;
    char choice = 'Y';
    do{
        cout << endl;
        cout << "*************************** WELCOME TO VEN'S MACHINE ***************************\n" << endl;
        cout << setw(43) << "MENU\n" << endl;
        cout << setw(20) << "Drink Name" << setw(20) << "Code" << setw(20) << "Remaining" << setw(20) << "Price" << endl;
        for(int i = 0; i < index; i++)
        { //print all the items in the list
            outputItem(drinks[i].name, drinks[i].code, drinks[i].remaining, drinks[i].price);
        }
        cout << "\n********************************************************************************" << endl;
        cout << "\nEnter drink code : ";
        cin >> code;
        totalSold = purchaseItem(index, drinks, code);
        cout << endl << "Continue? (Y/N) : ";
        cin >> choice;
        while (!(choice == 'Y' || choice == 'N') )
        { //while user doesn't enter a valid choice
            cout << endl << "Continue? (Y/N) : ";
            cin >> choice;
        }
    }while(choice == 'Y');
    cout << "\nThank You and Come Again !" << endl;
    return totalSold;
}
int main()
{
    int totalSold = 0;
    int MAX_ITEMS = 20;
    drinkType drinks[MAX_ITEMS];
    string filename = "order.txt";
    ifstream inFile;
    inFile.open(filename.c_str());
    int ch;
    do
    {
        cout << endl;
        cout << "********* MENU *********\n" << endl;
        cout << "1. Buy an item" << endl;
        cout << "2. Insert a new drinks in menu" << endl;
        cout << "3. Update the price of drinks" << endl;
        cout << "4. Total drinks sold" << endl;
        cout << "5. Exit" << endl;
        cout << "\n Enter you choice: ";
        cin >> ch;
        cout << endl;
        if (ch == 1)
            totalSold = purchase();
        else if (ch == 2)
            insertItem(inFile, drinks);
        else if (ch == 3)
            updatePrice(inFile, drinks);
        else if (ch == 4)
            cout << "Total number of drink sold: " << totalSold << endl;
        else
            break;
    }while(ch != 5); //while the choice is y
    cout << "\n Exiting !!!!!" << endl;
    return 0;
}
