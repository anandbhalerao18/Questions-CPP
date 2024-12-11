// 1.	Write a C++ program to implement a student database containing at least 15 records. The database should store details such as Roll No, Name, and SGPA for each student. Implement Bubble Sort to sort the list of students by their Roll Numbers in ascending order and display the sorted roll call list.

#include <iostream>
#include <string>
using namespace std;

// Structure to represent a student
struct Student {
    int rollNo;
    string name;
    float sgpa;
};

// Function to display the student database
void displayStudents(Student students[], int n) {
    cout << "\nRoll No\tName\t\tSGPA\n";
    cout << "--------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << students[i].rollNo << "\t" << students[i].name << "\t\t" << students[i].sgpa << endl;
    }
}

// Bubble Sort function to sort students by Roll No in ascending order
void bubbleSort(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                // Swap the two students
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int size = 15; // Number of students
    Student students[size] = {
        {105, "Alice", 9.2}, {101, "Bob", 8.5}, {104, "Charlie", 9.0},
        {102, "David", 8.7}, {110, "Eve", 9.4}, {108, "Frank", 7.8},
        {106, "Grace", 8.9}, {103, "Hannah", 9.1}, {109, "Ivy", 8.6},
        {107, "Jack", 8.4}, {115, "Karen", 7.9}, {112, "Leo", 9.3},
        {114, "Mia", 9.0}, {113, "Nina", 8.2}, {111, "Oscar", 9.1}
    };

    cout << "Student Database before sorting:\n";
    displayStudents(students, size);

    // Sorting the database by Roll No
    bubbleSort(students, size);

    cout << "\nStudent Database after sorting by Roll No (Ascending Order):\n";
    displayStudents(students, size);

    return 0;
}
