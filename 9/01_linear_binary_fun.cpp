#include <iostream>
#include <algorithm> 
using namespace std;

const int MAX = 100;

bool linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return true;
    }
    return false;
}

bool binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1,mid;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return true;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main() {
    int roll[MAX], n, choice, searchKey;

    cout << "Enter number of students: ";
    cin >> n;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
        	int i;
            cout << "\nEnter roll numbers in random order:\n";
            for (int i = 0; i < n; i++)
                cin >> roll[i];
            cout << "Enter roll number to search: ";
            cin >> searchKey;
            if (linearSearch(roll, n, searchKey))
                cout << "Student attended the training program.";
            else
                cout << "Student did NOT attend program.\n";
            break;

        case 2:
        	int mid;
            cout << "\nEnter roll numbers:\n";
            for (int i = 0; i < n; i++)
                cin >> roll[i];
            sort(roll, roll + n); 

            cout << "Enter roll number to search: ";
            cin >> searchKey;
            if (binarySearch(roll, n, searchKey))
                cout << "Student attended the training program.";
            else
                cout << "Student did NOT attend the program.\n";
            break;

        case 3:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 3);

    return 0;
}

