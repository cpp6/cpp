/*
B-5b
The ticket booking system of Cinemax theater has to be implemented. There are 10 rows and 7 seats in each row. 
A doubly linked list has to be maintained to keep track of free seats in rows. Assume some random booking to start with. 
Use an array to store pointers (Head pointer) to each row. On demand a) The list of booked seats is to be displayed(while creating nodes, show that some seats are already booked using status field) b) The booking can be cancelled.
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

void cancelBooking(int row_number, int seat_number) {
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
    } else if (temp->status == 0) {
        cout << "Seat is already free.\n";
    } else {
        temp->status = 0;
        cout << "Booking cancelled.\n";
    }
}

void menu() {
    int choice, row, seat;
    do {
        cout << "\n--- Cinemax Theater Booking System ---\n";
        cout << "1. Display Available Seats\n";
        cout << "2. Book a Seat\n";
        cout << "3. Cancel a Booking\n";
        cout << "4. Exit\n";
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
                cout << "Enter Row (1-10): ";
                cin >> row;
                cout << "Enter Seat (1-7): ";
                cin >> seat;
                cancelBooking(row, seat);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}

int main() {
    initializeTheater();
    menu();
    return 0;
}

/*
Algo:
Start
Create a Seat structure with:
seat_number
status (0 = free, 1 = booked)
prev, next pointers
Initialize Theater
For 10 rows:
Create 7 Seat nodes linked as a doubly linked list.
Store each row’s head pointer in rows[i].
Randomly mark some seats as booked (status = 1).
Display Available Seats
Traverse each row and print all seat_number where status == 0.
Book a Seat
Input row and seat number.
If already booked → show message.
Else → set status = 1.
Cancel Booking
Input row and seat number.
If already free → show message.
Else → set status = 0.
Menu
1: Display Available Seats
2: Book Seat
3: Cancel Booking
4: Exit
End
*/
