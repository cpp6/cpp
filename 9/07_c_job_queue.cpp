#include <iostream>
#include <string>
using namespace std;

#define SIZE 10

string queue[SIZE];
int front = 0;
int rear = -1;

void addJob() {
    if (rear == SIZE - 1) {
        cout << "Queue is full. Cannot add more jobs." << endl;
        return;
    }

    string job;
    cout << "Enter job name: ";
    cin.ignore();
    getline(cin, job);

    rear++;
    queue[rear] = job;

    cout << "Job added: " << job << endl;
}

void deleteJob() {
    if (front > rear) {
        cout << "Queue is empty. No job to delete." << endl;
        return;
    }

    cout << "Job deleted: " << queue[front] << endl;
    front++;
}

void displayJobs() {
    if (front > rear) {
        cout << "Queue is empty. No jobs to display." << endl;
        return;
    }

    cout << "Jobs in the queue:" << endl;
    for (int i = front; i <= rear; i++) {
        cout << "- " << queue[i] << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n--- Job Queue Menu ---" << endl;
        cout << "1. Add Job" << endl;
        cout << "2. Delete Job" << endl;
        cout << "3. Display Jobs" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            addJob();
        } else if (choice == 2) {
            deleteJob();
        } else if (choice == 3) {
            displayJobs();
        } else if (choice == 4) {
            cout << "Exiting program." << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
