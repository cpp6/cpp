/*
A-3a
Consider the telephone book database of N clients. Make use of a hash table implementation to quickly look up a client's telephone number. 
Make use of linear probing collision handling techniques.
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

void insert(Client table[], string name, string phone) {
    int index = hashFunction(name);
    int original = index;

    for (int i = 0; i < TABLE; i++) {
        if (!table[index].occupied) {
            table[index].name = name;
            table[index].phone = phone;
            table[index].occupied = true;
            cout << "Inserted at index " << index << endl;
            return;
        }
        index = (index + 1) % TABLE;
    }

    cout << "Hash table full! Cannot insert.\n";
}

string search(Client table[], string name) {
    int index = hashFunction(name);
    int original = index;

    for (int i = 0; i < TABLE; i++) {
        if (!table[index].occupied)
            return "Not found";

        if (table[index].name == name)
            return table[index].phone;
            
        index = (index + 1) % TABLE;
    }

    return "Not found";
}

void display(Client table[]) {
    cout << "\nHash Table:\n";
    for (int i = 0; i < TABLE; i++) {
        cout << i << ": ";
        if (table[i].occupied)
            cout << table[i].name << " -> " << table[i].phone;
        else
            cout << "Empty";
        cout << endl;
    }
}

int main() {
    Client table[TABLE];
    for (int i = 0; i < TABLE; i++)
        table[i].occupied = false;

    int choice;
    string name, phone;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert Client\n";
        cout << "2. Search Client\n";
        cout << "3. Display Table\n";
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
            cout << "Enter name to search: ";
            cin >> name;
            phone = search(table, name);
            cout << "Result: " << phone << endl;
            break;

        case 3:
            display(table);
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}

/*
Algorithm
Start
Initialize hash table of size 10 with all slots empty.
Hash Function:
Calculate sum of ASCII values of characters in name.
Index = sum % 10.
Insert(name, phone):
Find index using hash function.
If slot empty → insert data.
Else → move linearly to next slot (index + 1) % 10 until empty slot found.
Search(name):
Find index using hash function.
If name found → display phone.
Else → move linearly until found or empty slot → “Not found”.
Display:
Show all table slots with name and phone or “Empty”.
Use menu for Insert, Search, Display, Exit.
Stop
*/
