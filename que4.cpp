//4.	Create a C++ program to search for students in the SE AIML class based on their SGPA. The program should allow the user to input an SGPA value and return a list of all students who have the same SGPA. If more than one student has the same SGPA, print the details of all such students. Use a suitable search algorithm for this task.

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
    const int n = 5;
    Student students[n] = {
        {"Alice", 101, 9.0},
        {"Bob", 102, 8.5},
        {"Charlie", 103, 9.0},
        {"David", 104, 7.5},
        {"Eve", 105, 8.5}
    };

    float sgpaToSearch;
    cout << "Enter the SGPA to search: ";
    cin >> sgpaToSearch;

    searchBySGPA(students, n, sgpaToSearch);

    return 0;
}
