/*
B-4a
The Department of Computer Engineering has a student's club named "Pinnacle Club'. 
Students of the second, third and final year of the department can be granted membership on request. 
Similarly one may cancel the membership of the club. The first node is reserved for the president of the club and the last node is reserved for the secretary of the club. 
Write a program to maintain club member's information using singly linked lists. Store student PRN and Name. 
Write functions to: a) Add members as well as president or even secretary. (Any 2) b) Compute total number of members of club c) Display members
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
};

int main() {
    PinnacleClub A;
    int choice, prn;
    string name;

    while (true) {
        cout << "\n--- Pinnacle Club Menu ---\n";
        cout << "1. Add President\n";
        cout << "2. Add Secretary\n";
        cout << "3. Add Member\n";
        cout << "4. Display Members\n";
        cout << "5. Count Members\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter PRN and Name of President: ";
                cin >> prn >> name;
                A.addPresident(prn, name);
                break;
            case 2:
                cout << "Enter PRN and Name of Secretary: ";
                cin >> prn >> name;
                A.addSecretary(prn, name);
                break;
            case 3:
                cout << "Enter PRN and Name of Member: ";
                cin >> prn >> name;
                A.addMember(prn, name);
                break;
            case 4:
                A.display();
                break;
            case 5:
                cout << "Total Members: " << A.countMembers() << endl;
                break;
            case 6:
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
Create structure Node
Fields:
prn (integer)
name (string)
next (pointer to next node)
Initialize class PinnacleClub
head pointer set to NULL.
Functions
addPresident(prn, name)
Create a new node with given details.
Set newNode->next = head.
Update head = newNode.
addSecretary(prn, name)
Create a new node.
If list is empty → make this node head.
Else traverse to last node and link new node at the end.
addMember(prn, name)
Check if president and secretary exist.
Create a new node.
Traverse till node before secretary.
Insert the new node before secretary.
display()
Traverse the linked list from head.
Print PRN and Name of each node.
countMembers()
Initialize counter = 0.
Traverse through the list, increment counter for each node.
Return total count.
Main Function
Use menu to perform operations:
1 → Add President
2 → Add Secretary
3 → Add Member
4 → Display Members
5 → Count Members
6 → Exit
Repeat until user selects Exit.
Stop
*/

