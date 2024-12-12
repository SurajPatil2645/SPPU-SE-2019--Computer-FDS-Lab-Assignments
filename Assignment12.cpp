/* A double-ended queue (deque) is a linear list in which additions and deletions may be made
at either end. Obtain a data representation mapping a deque into a one dimensional array.
Write C++ program to simulate deque with functions to add and delete elements from either
end of the deque.
*/
#include <iostream>
using namespace std;

class Deque {
public:
    int f, r;
    int ar[10];

    Deque() {
        f = -1;
        r = -1;
    }

    bool empty() {
        if (f == -1 && r == -1) {
            cout << "Queue Empty.";
            return true;
        } else {
            return false;
        }
    }

    bool full() {
        return (r == 9);
    }

    void enr(int v) {
        if (full()) {
            cout << "Queue Full." << endl;
        } else {
            if (f == -1) f = 0;
            ar[++r] = v;
            cout << "Job added." << endl;
        }
    }

    void enf(int v) {
        if (f == 0) {
            cout << "Queue Full." << endl;
        } else {
            if (f == -1) {
                f = r = 0;
                ar[f] = v;
            } else {
                ar[--f] = v;
            }
            cout << "Job added." << endl;
        }
    }

    void der() {
        if (empty()) {
            cout << "Queue Empty.";
        } else {
            int x = ar[r--];
            if (r < f) f = r = -1;
            cout << "Job id " << x << " removed." << endl;
        }
    }

    void def() {
        if (empty()) {
            cout << "Queue Empty.";
        } else {
            int x = ar[f++];
            if (f > r) f = r = -1;
            cout << "Job id " << x << " removed." << endl;
        }
    }

    void display() {
        if (empty()) {
            cout << "Queue Empty." << endl;
            return;
        }
        for (int i = f; i <= r; ++i) {
            cout << ar[i] << " <- ";
        }
        cout << endl;
    }
};

int main() {
    Deque d1;
    int c;
    do {
        cout << "Enter choice:" << endl;
        cout << "1-Insert job from front." << endl;
        cout << "2-Insert job from end." << endl;
        cout << "3-Remove from front." << endl;
        cout << "4-Remove from end." << endl;
        cout << "5-Display." << endl;
        cout << "6-Exit." << endl;
        cin >> c;

        switch (c) {
            case 1: {
                int val;
                cout << "Enter job id:" << endl;
                cin >> val;
                d1.enf(val);
                break;
            }
            case 2: {
                int val;
                cout << "Enter job id:" << endl;
                cin >> val;
                d1.enr(val);
                break;
            }
            case 3:
                d1.def();
                break;
            case 4:
                d1.der();
                break;
            case 5:
                d1.display();
                break;
            case 6:
                break;
            default:
                cout << "Invalid input." << endl;
        }
    } while (c != 6);

    return 0;
}
