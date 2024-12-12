/* Second year Computer Engineering class, set A of students like Vanilla Ice-cream and
set B of students like butterscotch ice-cream. Write C++ program to store two sets using

linked list. Compute and display-
a) Set of students who like both vanilla and butterscotch

b) Set of students who like either vanilla or butterscotch or not both
c) Number of students who like neither vanilla nor butterscotch
*/
#include <iostream>
using namespace std;

class Node {
public:
    int rno;
    Node* next;
};

class SLL {
public:
    Node* header = nullptr;

    void create_new_node() {
        int n;
        cout << "Enter Total no. of Students: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            Node* new_node = new Node();
            cout << "Enter roll no.: ";
            cin >> new_node->rno;
            new_node->next = header;
            header = new_node;
        }
    }

    void display() {
        Node* temp = header;
        while (temp != nullptr) {
            cout << temp->rno << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void insert(Node* new_node) {
        new_node->next = header;
        header = new_node;
    }

    SLL get_intersection(SLL& other) {
        SLL result;
        Node* temp1 = header;

        while (temp1 != nullptr) {
            Node* temp2 = other.header;
            while (temp2 != nullptr) {
                if (temp1->rno == temp2->rno) {
                    result.insert(new Node{ temp1->rno, nullptr });
                    break;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return result;
    }

    SLL get_union(SLL& other) {
        SLL result;

        // Add all elements from the first list
        Node* temp1 = header;
        while (temp1 != nullptr) {
            result.insert(new Node{ temp1->rno, nullptr });
            temp1 = temp1->next;
        }

        // Add elements from the second list if not already present
        Node* temp2 = other.header;
        while (temp2 != nullptr) {
            if (!result.contains(temp2->rno)) {
                result.insert(new Node{ temp2->rno, nullptr });
            }
            temp2 = temp2->next;
        }
        return result;
    }

    bool contains(int roll_no) {
        Node* temp = header;
        while (temp != nullptr) {
            if (temp->rno == roll_no) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int count_neither(SLL& all_students) {
        int count = 0;
        Node* temp = all_students.header;

        while (temp != nullptr) {
            if (!contains(temp->rno)) {
                count++;
            }
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    SLL all_students, vanilla_students, butterscotch_students;

    cout << "Enter total Students in the class: " << endl;
    all_students.create_new_node();
    cout << "All Students List: ";
    all_students.display();

    cout << "For Vanilla: " << endl;
    vanilla_students.create_new_node();
    cout << "Vanilla Students List: ";
    vanilla_students.display();

    cout << "For Butterscotch: " << endl;
    butterscotch_students.create_new_node();
    cout << "Butterscotch Students List: ";
    butterscotch_students.display();

    SLL intersection = vanilla_students.get_intersection(butterscotch_students);
    cout << "Students who like both Vanilla and Butterscotch: ";
    intersection.display();

    SLL union_students = vanilla_students.get_union(butterscotch_students);
    cout << "Students who like either Vanilla or Butterscotch: ";
    union_students.display();

    int neither_count = union_students.count_neither(all_students);
    cout << "Number of students who like neither Vanilla nor Butterscotch: " << neither_count << endl;

    return 0;
}
