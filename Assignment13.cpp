/* Pizza parlor accepting maximum M orders. Orders are served on a first come first served
basis. Order once placed cannot be canceled. Write C++ program to simulate the system
using a circular queue using arrays.
*/
#include<iostream>
using namespace std;

#define maxsize 8

class PizzaParlor {
    int p[maxsize];
    int r, f;

public:
    PizzaParlor() {
        r = -1;
        f = -1;
    }

    // Function to place an order (enqueue)
    void enqueue(int x) {
        if (f == (r + 1) % maxsize) {  // Check if the queue is full
            cout << "Pizza Parlor is full" << endl;
        } else {
            if (f == -1 && r == -1) {  // If the queue is empty
                f = 0;
                r = 0;
            } else {
                r = (r + 1) % maxsize;  // Circular increment
            }
            p[r] = x;
            cout << "Order " << x << " placed successfully" << endl;
        }
    }

    // Function to serve an order (dequeue)
    int dequeue() {
        int x = -1;
        if (f == -1) {  // Check if the queue is empty
            cout << "No Order to Serve!" << endl;
        } else {
            cout << "Order " << p[f] << " served successfully" << endl;
            x = p[f];
            if (f == r) {  // If the queue becomes empty after serving
                f = -1;
                r = -1;
            } else {
                f = (f + 1) % maxsize;  // Circular increment
            }
        }
        return x;
    }

    // Function to display current orders in the queue
    void display() {
        if (f == -1) {  // If the queue is empty
            cout << "No order in the queue." << endl;
        } else {
            cout << "Current Orders in the queue are:" << endl;
            for (int i = f; i != r; i = (i + 1) % maxsize) {
                cout << "Order " << p[i] << endl;
            }
            cout << "Order " << p[r] << endl;  // Print the last element
        }
    }
};

int main() {
    PizzaParlor p;
    int x;
    int choice;

    do {
        // Display menu
        cout << "\n1. Place Order\n2. Serve Order\n3. Display Orders\n4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Place order
                cout << "Enter order number: ";
                cin >> x;
                p.enqueue(x);
                break;
            }
            case 2: {
                // Serve order
                p.dequeue();
                break;
            }
            case 3: {
                // Display orders
                p.display();
                break;
            }
            case 4: {
                // Exit
                cout << "Exiting the program." << endl;
                break;
            }
            default: {
                cout << "Invalid choice, please try again." << endl;
            }
        }
    } while (choice != 4);

    return 0;
}
