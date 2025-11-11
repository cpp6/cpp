/*
A-2b
Write a program to store the first year percentage of students in an array. 
Write function for sorting array of floating point numbers in ascending order using - Bubble sort and display top five scores
*/

#include <iostream>
using namespace std;

void bubbleSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void displayTopFive(float arr[], int n) {
    cout << "\nTop Five Scores:\n";
    int start = max(0, n - 5);
    for (int i = n - 1; i >= start; i--) {
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

    bubbleSort(percentages, n);

    cout << "\nPercentages in Ascending Order:\n";
    for (int i = 0; i < n; i++)
        cout << percentages[i] << " ";
    cout << endl;

    displayTopFive(percentages, n);

    return 0;
}

