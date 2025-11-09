/*
C-7
Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. 
If the operating system does not use priorities, then the jobs are processed in the order they enter the system. Write a CPP program for simulating job queue. 
Write functions to add job and delete job from the queue
*/

#include <iostream>
#include <string>
using namespace std;

#define SIZE 10

string queue[SIZE];
int front = 0;
int rear = -1;

void addJob() {
    if (rear == SIZE - 1) {
        cout << "Queue is full. Cannot add more jobs.\n";
        return;
    }

    string job;
    cout << "Enter job name: ";
    cin.ignore();
    getline(cin, job);

    rear++;
    queue[rear] = job;

    cout << "Job added: " << job << "\n";
}

void deleteJob() {
    if (front > rear) {
        cout << "Queue is empty. No job to delete.\n";
        return;
    }

    cout << "Job deleted: " << queue[front] << "\n";
    front++;
}

void displayJobs() {
    if (front > rear) {
        cout << "Queue is empty. No jobs to display.\n";
        return;
    }

    cout << "Jobs in the queue:\n";
    for (int i = front; i <= rear; i++) {
        cout << "- " << queue[i] << "\n";
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n--- Job Queue Menu ---\n";
        cout << "1. Add Job\n";
        cout << "2. Delete Job\n";
        cout << "3. Display Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addJob();
                break;
            case 2:
                deleteJob();
                break;
            case 3:
                displayJobs();
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
