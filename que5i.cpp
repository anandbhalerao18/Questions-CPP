// 5.	Write a C++ program to search for a particular student by their Name using Binary Search (without recursion).
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int rollNumber;
    float sgpa;
};

void displayStudent(const Student &s) {
    cout << "Name: " << s.name << ", Roll Number: " << s.rollNumber << ", SGPA: " << s.sgpa << endl;
}

int binarySearch(Student students[], int n, string target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (students[mid].name == target) {
            return mid; // Student found
        }
        if (students[mid].name < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Student not found
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    cin.ignore(); // Clear the input buffer

    Student students[n];
    cout << "Enter student details (Name, Roll Number, SGPA):\n";
    for (int i = 0; i < n; ++i) {
        cout << "Student " << i + 1 << ":\n";
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "Roll Number: ";
        cin >> students[i].rollNumber;
        cout << "SGPA: ";
        cin >> students[i].sgpa;
        cin.ignore(); // Clear the input buffer
    }

    // Sort students alphabetically by name
    sort(students, students + n, [](const Student &a, const Student &b) {
        return a.name < b.name;
    });

    string targetName;
    cout << "Enter the name of the student to search: ";
    getline(cin, targetName);

    int result = binarySearch(students, n, targetName);

    if (result != -1) {
        cout << "Student found:\n";
        displayStudent(students[result]);
    } else {
        cout << "Student not found.\n";
    }

    return 0;
}



