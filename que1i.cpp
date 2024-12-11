// 1.	Write a C++ program to implement a student database containing at least 15 records. The database should store details such as Roll No, Name, and SGPA for each student. Implement Bubble Sort to sort the list of students by their Roll Numbers in ascending order and display the sorted roll call list.

#include <iostream>
#include <string>
using namespace std;

// Structure to hold student details
struct Student {
    int rollNo;        // Roll Number
    string name;       // Name of the student
    float sgpa;        // SGPA
};

// Function to input student details
void inputStudentDetails(Student students[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Roll Number: ";
        cin >> students[i].rollNo;
        cout << "Name: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, students[i].name);
        cout << "SGPA: ";
        cin >> students[i].sgpa;
    }
}

// Function to display student details
void displayStudents(const Student students[], int size) {
    cout << "\nSorted Student List:\n";
    cout << "Roll No\tName\t\tSGPA\n";
    for (int i = 0; i < size; i++) {
        cout << students[i].rollNo << "\t" << students[i].name << "\t\t" << students[i].sgpa << endl;
    }
}

// Function to sort students by roll number using Bubble Sort
void bubbleSort(Student students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                // Swap the students
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int numStudents = 15;
    Student students[numStudents];

    // Input details of students
    inputStudentDetails(students, numStudents);

    // Sort the students by roll number
    bubbleSort(students, numStudents);

    // Display the sorted list
    displayStudents(students, numStudents);

    return 0;
}
