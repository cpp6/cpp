
/*
A-2a
Write a program to store the first year percentage of students in an array. Write function
for sorting array of floating point numbers in ascending order using - Selection Sort and display top five scores
*/

#include <iostream>
using namespace std;

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

void displayTopFive(float arr[], int n) {
    cout << "\nTop five scores:\n";
    for (int i = n - 1; i >= max(n - 5, 0); i--) {
        cout << arr[i] << endl;
    }
}

int main() {
    float percentages[100];
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter percentages of students:\n";
    for (int i = 0; i < n; i++) {
        cin >> percentages[i];
    }

    selectionSort(percentages, n);

    cout << "\nPercentages in Ascending Order:\n";
    for (int i = 0; i < n; i++)
        cout << percentages[i] << " ";
    cout << endl;

    displayTopFive(percentages, n);
    
    return 0;
}

