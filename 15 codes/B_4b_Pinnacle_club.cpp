/*
B-4b
The Department of Computer Engineering has a student's club named 'Pinnacle Club Students of the second, third and final year of the department can be granted membership on request. 
Similarly one may cancel the membership of the club. The first node is reserved for the president of the club and the last node is reserved for the secretary of the club. 
Write a program to maintain club member's information using singly linked lists. Store student PRN and Name. 
Write functions to: a) Delete the members as well as president or even secretary. (Any 2) b) Compute total number of members of club c) Display members
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

    void deletePresident() {
        if (!head) {
            cout << "No President to delete.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "President deleted.\n";
    }

    void deleteSecretary() {
        if (!head || !head->next) {
            cout << "No Secretary to delete.\n";
            return;
        }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
        cout << "Secretary deleted.\n";
    }

    void deleteMember(int prn) {
        if (!head || !head->next) {
            cout << "No members to delete.\n";
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->next) {
            if (temp->next->prn == prn) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                cout << "Member deleted.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Member not found.\n";
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
        cout << "4. Delete President\n";
        cout << "5. Delete Secretary\n";
        cout << "6. Delete Member\n";
        cout << "7. Display Members\n";
        cout << "8. Count Members\n";
        cout << "9. Exit\n";
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
                A.deletePresident();
                break;
            case 5:
                A.deleteSecretary();
                break;
            case 6:
                cout << "Enter PRN of Member to delete: ";
                cin >> prn;
                A.deleteMember(prn);
                break;
            case 7:
                A.display();
                break;
            case 8:
                cout << "Total Members: " << A.countMembers() << endl;
                break;
            case 9:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

