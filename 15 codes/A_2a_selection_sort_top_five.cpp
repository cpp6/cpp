
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

// Algorithm

/*
Selection sort:
1. Start
2. Read the number of elements n
3. Read the array elements A[0] to A[n-1]
4. Repeat for i = 0 to n-2:
● Set min_index = i
● Repeat for j = i+1 to n-1:
If A[j] < A[min_index] then
■ Set min_index = j
● If min_index ≠ i then
○ Swap A[i] and A[min_index]
5. End of loop
6. Display the sorted array
7. Display the top 5 scores (last 5 elements of sorted array)
8. Stop
*/
