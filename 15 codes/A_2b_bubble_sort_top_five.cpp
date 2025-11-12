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

/* Algorithm
Bubble sort:
1. Start
2. Read the number of elements n
3. Read the array elements A[0] to A[n-1]
4. Repeat for i = 0 to n-2:
● Repeat for j = 0 to n-i-2:
○ If A[j] > A[j+1] then
■ Swap A[j] and A[j+1]
5. End of loop
6. Display the sorted array
7. Display the top 5 scores (last 5 elements of sorted array)
8. Stop
*/
