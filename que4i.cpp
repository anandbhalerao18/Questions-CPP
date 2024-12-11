// 4.	Create a C++ program to search for students in the SE AIML class based on their SGPA. The program should allow the user to input an SGPA value and return a list of all students who have the same SGPA. If more than one student has the same SGPA, print the details of all such students. Use a suitable search algorithm for this task.

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollNumber;
    float sgpa;
};

void searchBySGPA(Student students[], int n, float sgpaToSearch) {
    bool found = false;
    cout << "Students with SGPA " << sgpaToSearch << ":\n";
    for (int i = 0; i < n; i++) {
        if (students[i].sgpa == sgpaToSearch) {
            found = true;
            cout << "Name: " << students[i].name 
                 << ", Roll Number: " << students[i].rollNumber 
                 << ", SGPA: " << students[i].sgpa << endl;
        }
    }
    if (!found) {
        cout << "No students found with SGPA " << sgpaToSearch << ".\n";
    }
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student students[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Roll Number: ";
        cin >> students[i].rollNumber;
        cout << "SGPA: ";
        cin >> students[i].sgpa;
    }

    float sgpaToSearch;
    cout << "Enter the SGPA to search: ";
    cin >> sgpaToSearch;

    searchBySGPA(students, n, sgpaToSearch);

    return 0;
}
