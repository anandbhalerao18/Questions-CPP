// 7.	Write a function enqueue(int value) to insert a new element  and display()to display all the elements currently present into the Circular Queue.
#include <iostream>
using namespace std;

#define MAX 5 // Maximum size of the queue

class CircularQueue {
    int front, rear, queue[MAX];

public:
    CircularQueue() {
        front = rear = -1;
    }

    // Function to insert an element into the queue (Enqueue)
    void enqueue(int value) {
        if ((rear + 1) % MAX == front) {
            cout << "Queue is full!" << endl; // Overflow condition
        } else {
            if (front == -1) { // If the queue is empty
                front = rear = 0;
            } else {
                rear = (rear + 1) % MAX;
            }
            queue[rear] = value; // Insert the value into the queue
        }
    }

    // Function to display all elements in the queue
    void display() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Queue elements: ";
            int i = front;
            while (i != rear) {
                cout << queue[i] << " ";
                i = (i + 1) % MAX;
            }
            cout << queue[rear] << endl; // Display the last element
        }
    }
};

int main() {
    CircularQueue cq;

    // Predefined data
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    // Display the elements of the queue
    cq.display();

    return 0;
}
