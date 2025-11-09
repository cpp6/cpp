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
        cout << "4. Delete President\n";
        cout << "5. Delete Secretary\n";
        cout << "6. Delete Member\n";
        cout << "7. Display Members\n";
        cout << "8. Count Members\n";
        cout << "9. Concatenate Division B to A\n";
        cout << "10. Exit\n";
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
                divA.deletePresident();
                break;
            case 5:
                divA.deleteSecretary();
                break;
            case 6:
                cout << "Enter PRN of Member to delete: ";
                cin >> prn;
                divA.deleteMember(prn);
                break;
            case 7:
                divA.display();
                break;
            case 8:
                cout << "Total Members: " << divA.countMembers() << endl;
                break;
            case 9:
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
            case 10:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

