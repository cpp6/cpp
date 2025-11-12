/*
A-3c
Consider the telephone book database of N clients. Make use of a hash table implementation to quickly look up a client's telephone number. 
Make use of quadratic probing collision handling techniques
*/

#include <iostream>
using namespace std;

const int TABLE = 10;

struct Client {
    string name;
    string phone;
    bool occupied;
};

int hashFunction(string key) {
    int sum = 0;
    for (int i = 0; i < key.length(); i++)
        sum += key[i];
    return sum % TABLE;
}

void insert(Client table[], const string &name, const string &phone) {
    int h = hashFunction(name);
    for (int i = 0; i < TABLE; ++i) {
        int idx = (h + i * i) % TABLE;  

        if (!table[idx].occupied || table[idx].name == name) {
            table[idx].name = name;
            table[idx].phone = phone;
            table[idx].occupied = true;
            cout << "Stored at index " << idx << "\n";
            return;
        }
    }
    cout << "Hash table full. Cannot insert.\n";
}

string search(Client table[], const string &name) {
    int h = hashFunction(name);
    for (int i = 0; i < TABLE; ++i) {
        int idx = (h + i * i) % TABLE;

        if (!table[idx].occupied) 
            return "Not found";
        if (table[idx].name == name) 
            return table[idx].phone;
    }
    return "Not found";
}

void display(Client table[]) {
    cout << "\nIndex\tEntry\n";
    for (int i = 0; i < TABLE; ++i) {
        cout << i << "\t";
        if (table[i].occupied) 
            cout << table[i].name << " -> " << table[i].phone << "\n";
        else 
            cout << "Empty\n";
    }
}

int main() {
    Client table[TABLE];
    for (int i = 0; i < TABLE; ++i) 
        table[i].occupied = false;

    int choice;
    string name, phone;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert client\n";
        cout << "2. Search client\n";
        cout << "3. Display table\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter phone number: ";
                cin >> phone;
                insert(table, name, phone);
                break;
            case 2:
                cout << "Name to search: "; 
                cin >> name;
                cout << "Result: " << search(table, name) << "\n";
                break;
            case 3:
                display(table);
                break;
            case 4:
                cout << "Exiting\n";
                break;
            default:
                cout << "Invalid\n";
        }
    } while (choice != 4);

    return 0;
}

/*
Algo:
Start
Initialize a hash table of size 10 with all slots empty.
Hash Function:
Compute sum of ASCII values of all characters in name.
Index = sum % 10.
Insert(name, phone):
Compute h = hashFunction(name).
For i = 0 to TABLE - 1:
Compute index = (h + i*i) % TABLE.
If slot empty or same name → store name, phone, mark occupied → stop.
If no empty slot → print “Hash table full”.
Search(name):
Compute h = hashFunction(name).
For i = 0 to TABLE - 1:
Compute index = (h + i*i) % TABLE.
If slot empty → return “Not found”.
If name matches → return phone number.
After loop → “Not found”
Display:
Print all indices with stored name and phone, or “Empty”.
Menu:
1 → Insert client
2 → Search client
3 → Display table
4 → Exit
Stop
*/
