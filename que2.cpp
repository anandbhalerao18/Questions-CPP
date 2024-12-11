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
    Student students[15] = {
        {1, "neo", 9.2}, {2, "leo", 8.5}, {3, "don", 8.8}, {4, "rio", 9.0}, {5, "oman", 7.9},
        {6, "fizaa", 8.6}, {7, "gangsta", 9.1}, {8, "zebra", 8.2}, {9, "cindrella", 9.3}, {10, "bob", 7.8},
        {11, "jack", 8.4}, {12, "ballentine", 9.4}, {13, "eco", 8.9}, {14, "panther", 7.7}, {15, "women", 8.1}
    };

    cout << "Original List of Students:\n";
    displayStudents(students, 15);

    insertionSortByName(students, 15);

    cout << "\nSorted List of Students by Name:\n";
    displayStudents(students, 15);

    return 0;
}
