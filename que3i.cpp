// 3.	Develop a C++ program to arrange the students of an SE AIML class based on their SGPA using Quick Sort. The program should identify the Top 10 students with the highest SGPA from the class and display their details (Roll No, Name, SGPA) in descending order of SGPA. Ensure the database contains at least 15 student records.
#include <iostream>
#include <string>
using namespace std;

// Structure to store student details
struct Student {
    int rollNo;
    string name;
    float sgpa;
};

// Function to partition the array
int partition(Student arr[], int low, int high) {
    float pivot = arr[high].sgpa; // Choosing last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].sgpa >= pivot) { // Sorting in descending order
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort function
void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to display top 10 students
void displayTop10(Student arr[], int size) {
    cout << "Top 10 Students with Highest SGPA:\n";
    cout << "Roll No\tName\t\tSGPA\n";
    for (int i = 0; i < size && i < 10; i++) {
        cout << arr[i].rollNo << "\t" << arr[i].name << "\t" << arr[i].sgpa << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of students (minimum 15): ";
    cin >> n;

    if (n < 15) {
        cout << "Please enter at least 15 records.\n";
        return 0;
    }

    Student students[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter details for student " << i + 1 << " (Roll No, Name, SGPA):\n";
        cin >> students[i].rollNo >> students[i].name >> students[i].sgpa;
    }

    quickSort(students, 0, n - 1);
    displayTop10(students, n);
    return 0;
}
