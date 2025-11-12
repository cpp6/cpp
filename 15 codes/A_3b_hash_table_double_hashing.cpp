/*
A-3b
Consider the telephone book database of N clients. Make use of a hash table implementation to quickly look up a client's telephone number. 
Make use of double hashing collision. handling techniques.
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

int secondHash(string key) {
    int sum = 0;
    for (int i = 0; i < key.length(); i++)
        sum += key[i];
    return 7 - (sum % 7); 
}

void insert(Client table[], string name, string phone) {
    int index1 = hashFunction(name);
    int step = secondHash(name);

    for (int i = 0; i < TABLE; ++i) {
        int idx = (index1 + i * step) % TABLE;
        if (!table[idx].occupied || table[idx].name == name) {
            table[idx].name = name;
            table[idx].phone = phone;
            table[idx].occupied = true;
            cout << "Stored at index " << idx << "\n";
            return;
        }
    }
    cout << "Hash table full\n";
}

string search(Client table[], const string& name) {
    int index1 = hashFunction(name);
    int step = secondHash(name);
    
    for (int i = 0; i < TABLE; ++i) {
        int idx = (index1 + i * step) % TABLE;
    
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
Initialize hash table of size 10 with all slots empty.
Hash Function (h1):
Compute sum of ASCII values of characters in name.
Index = sum % 10.
Second Hash Function (h2):
Compute same sum.
Step size = 7 - (sum % 7).
Insert(name, phone):
Calculate index1 = h1(name) and step = h2(name).
For i = 0 to TABLE–1:
Compute new index = (index1 + i * step) % TABLE.
If slot empty or same name → store data and mark occupied
If no empty slot → print “Hash table full”.
Search(name):
Compute index1 and step.
For i = 0 to TABLE–1:
Compute index = (index1 + i * step) % TABLE.
If slot empty → return “Not found”.
If name matches → return phone number.
Display:
Show all indices with names and numbers or print “Empty”.
Menu:
1 → Insert client
2 → Search client
3 → Display table
4 → Exit
Stop
*/
