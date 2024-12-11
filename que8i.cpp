// 8.	Write a function dequeue() to remove an element and display()to display all the elements currently present from the Circular Queue.
#include <iostream>
using namespace std;

#define MAX 5  // Defining the size of the circular queue

class CircularQueue {
    int queue[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if the queue is full
    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    // Enqueue operation (inserting an element)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
        } else {
            if (front == -1) {  // First element to be inserted
                front = rear = 0;
            } else {
                rear = (rear + 1) % MAX;
            }
            queue[rear] = value;
            cout << value << " enqueued to the queue." << endl;
        }
    }

    // Dequeue operation (removing an element)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
        } else {
            cout << queue[front] << " dequeued from the queue." << endl;
            if (front == rear) {  // Last element in the queue
                front = rear = -1;
            } else {
                front = (front + 1) % MAX;
            }
        }
    }

    // Display the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue elements: ";
            int i = front;
            while (i != rear) {
                cout << queue[i] << " ";
                i = (i + 1) % MAX;
            }
            cout << queue[rear] << endl;
        }
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
