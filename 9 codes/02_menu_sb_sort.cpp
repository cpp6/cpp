#include <iostream>
using namespace std;

const int MAX = 100;

void selectionSort(float arr[], int n) {
	
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

void bubbleSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void displayTopFive(float arr[], int n) {
    cout << "Top five scores:\n";
    for (int i = n - 1; i >= max(n - 5, 0); i--) {
        cout << arr[i] << endl;
    }
}

int main() {
    float percentages[MAX];
    int n, choice;

    cout << "Enter number of students: ";
    cin >> n;
    cout << "Enter percentages:\n";
    for (int i = 0; i < n; i++) {
        cin >> percentages[i];
    }

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Selection Sort & Display Top 5\n";
        cout << "2. Bubble Sort & Display Top 5\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        float sorted[MAX];
        copy(percentages, percentages + n, sorted);

        switch (choice) {
        case 1:
            selectionSort(sorted, n);
            displayTopFive(sorted, n);
            break;
        case 2:
            bubbleSort(sorted, n);
            displayTopFive(sorted, n);
            break;
        case 3:
            cout << "Exiting.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 3);
			
    return 0;
}

