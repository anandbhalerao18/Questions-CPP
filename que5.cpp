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
    const int n = 5;
    Student students[n] = {
        {"Alice", 1, 8.5},
        {"Bob", 2, 9.0},
        {"Charlie", 3, 7.8},
        {"David", 4, 8.9},
        {"Eve", 5, 8.2}
    };

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
