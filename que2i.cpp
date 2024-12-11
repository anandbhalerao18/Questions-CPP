// 1.	Write a C++ program to implement a student database containing at least 15 records. The database should store details such as Roll No, Name, and SGPA for each student. Implement Bubble Sort to sort the list of students by their Roll Numbers in ascending order and display the sorted roll call list.

#include <iostream>
#include <string>
using namespace std;

// Structure to hold student data
struct Student {
    int rollNo;
    string name;
    float sgpa;
};

// Function to display student details
void displayStudents(Student students[], int size) {
    cout << "Roll No\tName\t\tSGPA\n";
    for (int i = 0; i < size; i++) {
        cout << students[i].rollNo << "\t" << students[i].name << "\t\t" << students[i].sgpa << endl;
    }
}

// Function to sort students alphabetically by name using Insertion Sort
void insertionSortByName(Student students[], int size) {
    for (int i = 1; i < size; i++) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].name > key.name) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter the number of students (up to 15): ";
    cin >> n;

    Student students[15];
    cout << "Enter details of " << n << " students (Roll No, Name, SGPA):\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ":\n";
        cout << "Roll No: ";
        cin >> students[i].rollNo;
        cin.ignore(); // Ignore leftover newline character
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "SGPA: ";
        cin >> students[i].sgpa;
    }

    cout << "\nOriginal List of Students:\n";
    displayStudents(students, n);

    insertionSortByName(students, n);

    cout << "\nSorted List of Students by Name:\n";
    displayStudents(students, n);

    return 0;
}
