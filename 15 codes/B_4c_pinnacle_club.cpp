/*
B-4c
The Department of Computer Engineering has a student's club named 'Pinnacle Club'. Students of the second, third and final year of the department can be granted membership on request. 
Similarly one may cancel the membership of the club. The first node is reserved for the president of the club and the last node is reserved for the secretary of the club. 
Write a program to maintain club member's information using singly linked lists(Create SLL for club). Store student PRN and Name. 
Write functions to:. a) Compute total number of members of club b) Display members c) Two linked lists exist for two divisions, Concatenate two lists.
*/

#include <iostream>
using namespace std;

struct Node {
    int prn;
    string name;
    Node* next;
};

class PinnacleClub {
private:
    Node* head;

public:

    PinnacleClub() {
        head = nullptr;
    }

    void addPresident(int prn, string name) {
        Node* newNode = new Node{prn, name, head};
        head = newNode;
    }

    void addSecretary(int prn, string name) {
        Node* newNode = new Node{prn, name, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void addMember(int prn, string name) {
        Node* newNode = new Node{prn, name, nullptr};
        if (!head || !head->next) {
            cout << "Add President and Secretary first.\n";
            return;
        }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display() {
        if (!head) {
            cout << "Club is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Club Members:\n";
        while (temp) {
            cout << temp->prn << " - " << temp->name << endl;
            temp = temp->next;
        }
    }

    int countMembers() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void concatenate(PinnacleClub& other) {
        if (!head) {
            head = other.head;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = other.head;
    }
};

int main() {
    PinnacleClub divA, divB;
    int choice, prn;
    string name;

    while (true) {
        cout << "\n--- Pinnacle Club Menu ---\n";
        cout << "1. Add President\n";
        cout << "2. Add Secretary\n";
        cout << "3. Add Member\n";
        cout << "4. Display Members\n";
        cout << "5. Count Members\n";
        cout << "6. Concatenate Division B to A\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter PRN and Name of President: ";
                cin >> prn >> name;
                divA.addPresident(prn, name);
                break;
            case 2:
                cout << "Enter PRN and Name of Secretary: ";
                cin >> prn >> name;
                divA.addSecretary(prn, name);
                break;
            case 3:
                cout << "Enter PRN and Name of Member: ";
                cin >> prn >> name;
                divA.addMember(prn, name);
                break;
            case 4:
                divA.display();
                break;
            case 5:
                cout << "Total Members: " << divA.countMembers() << endl;
                break;
            case 6:
                cout << "Enter Division B Members:\n";
                cout << "President PRN and Name: ";
                cin >> prn >> name;
                divB.addPresident(prn, name);
                cout << "Secretary PRN and Name: ";
                cin >> prn >> name;
                divB.addSecretary(prn, name);
                divA.concatenate(divB);
                cout << "Division B concatenated to Division A.\n";
                break;
            case 7:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

/*
Algo:
Start
Define structure Node
Fields: prn, name, and pointer next.
Create class PinnacleClub with:
Pointer head (initially NULL).
Functions for operations.
Function addPresident(prn, name)
Create new node.
Set newNode->next = head.
Update head = newNode.
Function addSecretary(prn, name)
Create new node.
Traverse to end and attach node as last.
Function addMember(prn, name)
Traverse to node before secretary.
Insert new member node before secretary.
Function display()
Traverse from head and print PRN and name of each member.
Function countMembers()
Initialize counter = 0.
Traverse entire list, increment counter, and return total.
Function concatenate(otherList)
Traverse to last node of current list
Set its next pointer to head of otherList.
In main()
Create two lists divA and divB.
Display menu to perform all operations (add, count, display, concatenate).
Repeat until user exits.
Stop
*/
