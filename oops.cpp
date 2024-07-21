#include <iostream>
#include <string.h>

using namespace std;

struct itemEntry
{
    float unitPrice;
    int copies, product_id;
    char name[30];
    char company[30];
};

class Store
{
public:
    int numItem;
    itemEntry database[100];

    Store()
    {
        numItem = 0;
    }

    void insertItem(char itemName[], char company[], int pid, int c, float p);
    void deleteItem(char itemName[], int pid);
    itemEntry *searchItem(char itemName[], int pid);
    void updateItem(char itemName[], int pid, int total, float price);
    void displayInventory();
};

void Store::insertItem(char itemName[], char company[], int pid, int c, float p)
{
    strcpy(database[numItem].name, itemName);
    strcpy(database[numItem].company, company);
    database[numItem].product_id = pid;
    database[numItem].copies = c;
    database[numItem].unitPrice = p;
    cout << "\n\t\t ITEM INSERTED SUCCESSFULLY\n";
    numItem++;
}

void Store::deleteItem(char itemName[], int pid)
{
    for (int i = 0; i < numItem; i++)
    {
        if ((strcmp(itemName, database[i].name) == 0) && (database[i].product_id == pid))
        {
            database[i].copies--;
            cout << "\n\t\t ITEM DELETED SUCCESSFULLY\n";
            return;
        }
    }
    cout << "\n\t\t ITEM NOT FOUND\n";
}

itemEntry *Store::searchItem(char itemName[], int pid)
{
    for (int i = 0; i < numItem; i++)
    {
        if ((strcmp(itemName, database[i].name) == 0) && (database[i].product_id == pid))
            return &database[i];
    }
    return NULL;
}

void Store::updateItem(char itemName[], int pid, int total, float price)
{
    itemEntry *item = searchItem(itemName, pid);
    if (item != NULL)
    {
        item->copies += total;
        item->unitPrice += price;
    }
    else
    {
        cout << "\n\t\t ITEM NOT FOUND\n";
    }
}

void Store::displayInventory()
{
    cout << "\n\t------------->INVENTORY<--------------\n";
    for (int i = 0; i < numItem; i++)
    {
        cout << "\n\tItem " << i + 1 << ":\n";
        cout << "\t\tName: " << database[i].name << "\n";
        cout << "\t\tCompany: " << database[i].company << "\n";
        cout << "\t\tProduct ID: " << database[i].product_id << "\n";
        cout << "\t\tCopies: " << database[i].copies << "\n";
        cout << "\t\tUnit Price: " << database[i].unitPrice << "\n";
    }
}

int main()
{
    Store sto;
    char name[30], company[30];
    int product_id, copies, unit_price, option;

    do
    {
        cout << "\n\t-------------COMPUTER STOCK STORE<--------------";
        cout << "\n\t\t-------------->MENU<------------";
        cout << "\n\t\t\t    1 FOR INSERT ITEM";
        cout << "\n\t\t\t    2 FOR DELETE ITEM";
        cout << "\n\t\t\t    3 FOR SEARCH ITEM ";
        cout << "\n\t\t\t    4 FOR UPDATE ITEM ";
        cout << "\n\t\t\t    5 FOR DISPLAY ITEM---------------------------------8";
        cout << "\n\t\t\t    6 FOR EXIT";
        cout << "\n\t\t  ENTER YOUR CHOICE : ";
        cin >> option;

        switch (option)
        {
        case 1:
            cin.ignore(); // Ignore newline character left in the buffer
            cout << "\n\t\t\t ENTER NAME OF COMPUTER MODEL : ";
            cin.getline(name, 80);
            cout << "\n\t\t\t COMPANY: ";
            cin.getline(company, 80);
            cout << "\n\t\t\t ENTER PRODUCT ID : ";
            cin >> product_id;
            cout << "\n\t\t\t NO. OF COPIES : ";
            cin >> copies;
            cout << "\n\t\t\t UNIT PRICE PER ITEM : ";
            cin >> unit_price;
            sto.insertItem(name, company, product_id, copies, unit_price);
            break;
        case 2:
            cin.ignore(); // Ignore newline character left in the buffer
            cout << "\n\t\t\t ENTER NAME OF COMPUTER MODEL : ";
            cin.getline(name, 80);
            cout << "\n\t\t\t ENTER PRODUCT ID : ";
            cin >> product_id;
            sto.deleteItem(name, product_id);
            break;
        case 3:
            cin.ignore(); // Ignore newline character left in the buffer
            cout << "\n\t\t\t ENTER NAME OF COMPUTER MODEL : ";
            cin.getline(name, 80);
            cout << "\n\t\t\t ENTER PRODUCT ID : ";
            cin >> product_id;
            itemEntry *test;
            test = sto.searchItem(name, product_id);
            if (test != NULL)
            {
                cout << "\n\t------------->SEARCHING RESULT<--------------";
                cout << "\n\t\t\t   ITEM FOUND"
                     << "\n\t\t\t NAME OF THE COMPUTER MODEL :" << test->name << "\n\t\t\t COMPANY NAME :"
                     << test->company << "\n\t\t\t PRODUCT ID:" << test->product_id
                     << "\n\t\t\t NUMBER OF COPIES AVAILABLE:" << test->copies
                     << "\n\t\t\t UNIT PRICES PER ITEM:" << test->unitPrice;
            }
            else
                cout << "\n\t\t\t ITEM NOT FOUND";
            break;
        case 4:
            cin.ignore(); // Ignore newline character left in the buffer
            cout << "\n\t\t\t ENTER NAME OF COMPUTER MODEL : ";
            cin.getline(name, 80);
            cout << "\n\t\t\t ENTER PRODUCT ID : ";
            cin >> product_id;
            cout << "\n\t\t\t ENTER TOTAL NEW ENTRY : ";
            cin >> copies;
            cout << "\n\t\t\t ENTER NEW PRICE : ";
            cin >> unit_price;
            sto.updateItem(name, product_id, copies, unit_price);
            break;
        case 5:
            sto.displayInventory();
            break;
        }
    } while (option != 6);

    return 0;
}