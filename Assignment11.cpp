* Queues are frequently used in computer programming, and a typical example is the
creation of a job queue by an operating system. If the operating system does not use
priorities, then the jobs are processed in the order they enter the system. Write C++
program for simulating job queue. Write functions to add job and delete job from queue.
*/
#include<iostream>
using namespace std;

#define N 5

class queue {
    int q[N];
    int r, f;

public:
    queue() {
        r = -1;
        f = -1;
    }

    void enqueue(int x) {
        if (r == N - 1) {
            cout << "Queue Overflow" << endl;
        } else if (r == -1 && f == -1) {
            r = 0;
            f = 0;
            q[r] = x;
        } else {
            r++;
            q[r] = x;
        }
    }

    int dequeue() {
        int x = -1;
        if (f == -1) {
            cout << "Queue Underflow" << endl;
        } else {
            x = q[f];
            f++;
        }
        return x;
    }

    void display() {
        cout << "Elements are:" << endl;
        for (int i = f; i <= r; i++) {
            cout << q[i] << endl;
        }
    }
};

int main() {
    queue q;
    int x;
    int choice;
    do {
        cout << "\n1.Enqueue Operation\n2.Dequeue Operation\n3.Display\n4.Exit" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the element:" << endl;
                cin >> x;
                q.enqueue(x);
                break;
            case 2:
                cout << "Deleted successfully" << endl;
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            default:
                cout << "Exit successfully" << endl;
        }
    } while (choice < 4);
    return 0;
}
