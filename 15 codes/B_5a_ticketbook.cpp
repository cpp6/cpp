/*
B-5a
The ticket booking system of Cinemax theater has to be implemented. There are 10 rows and 7 seats in each row. 
A doubly linked list has to be maintained to keep track of free seats in rows. Assume some random booking to start with. 
Use an array to store pointers (Head pointer) to each row. On demand a) The list of available seats is to be displayed b) The seats are to be booked
*/

#include <iostream>
using namespace std;

struct Seat {
    int seat_number;
    int status; 
    Seat* prev;
    Seat* next;

    Seat(int num) {
        seat_number = num;
        status = 0;
        prev = next = nullptr;
    }
};

Seat* rows[10];

void initializeTheater() {
    for (int i = 0; i < 10; i++) {
        Seat* head = nullptr;
        Seat* tail = nullptr;
        for (int j = 1; j <= 7; j++) {
            Seat* newSeat = new Seat(j);
            if (!head) {
                head = tail = newSeat;
            } else {
                tail->next = newSeat;
                newSeat->prev = tail;
                tail = newSeat;
            }
        }
        rows[i] = head; 
    }
}

void displayAvailableSeats() {
    cout << "\nAvailable Seats:\n";
    for (int i = 0; i < 10; i++) {
        Seat* temp = rows[i];
        bool found = false;
        cout << "Row " << i + 1 << ": ";
        while (temp != nullptr) {
            if (temp->status == 0) {
                cout << temp->seat_number << " ";
                found = true;
            }
            temp = temp->next;
        }
        if (!found)
            cout << "No seats available";
        cout << endl;
    }
}

void bookSeat(int row_number, int seat_number) {
    if (row_number < 1 || row_number > 10 || seat_number < 1 || seat_number > 7) {
        cout << "Invalid row or seat number.\n";
        return;
    }

    Seat* temp = rows[row_number - 1];
    while (temp != nullptr && temp->seat_number != seat_number) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Seat not found.\n";
    } else if (temp->status == 1) {
        cout << "Seat already booked.\n";
    } else {
        temp->status = 1;
        cout << "Seat booked successfully.\n";
    }
}

void menu() {
    int choice, row, seat;
    do {
        cout << "\n---Theater Booking System ---\n";
        cout << "1. Display Available Seats\n";
        cout << "2. Book a Seat\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAvailableSeats();
                break;
            case 2:
                cout << "Enter Row (1-10): ";
                cin >> row;
                cout << "Enter Seat (1-7): ";
                cin >> seat;
                bookSeat(row, seat);
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);
}

int main() {
    initializeTheater();
    menu();
    return 0;
}

/*
Algo;
Start
Create structure Seat with seat_number, status, prev, next.
Initialize 10 rows with 7 seats each using doubly linked list (initializeTheater()).
DisplayAvailableSeats() – Traverse each row and show seats where status == 0.
BookSeat(row, seat) –
Check valid row & seat number.
Traverse to find the seat.
If already booked → show message.
Else → set status = 1 (booked).
Menu() –
1: Display available seats
2: Book a seat
3: Exit
Call initializeTheater() and menu() in main().
Stop
*/
