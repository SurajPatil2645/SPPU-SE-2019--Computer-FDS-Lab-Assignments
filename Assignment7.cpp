/* Department of Computer Engineering has student's club named 'Pinnacle Club'. Students
of second, third and final year of department can be granted membership on request.
Similarly one may cancel the membership of club. First node is reserved for president of
club and last node is reserved for secretary of club. Write C++ program to maintain club
member‘s information using singly linked list. Store student PRN and Name. Write
functions to:
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Two linked lists exists for two divisions. Concatenate two lists.
*/
#include <iostream>
using namespace std;

class Node {
public:
    int prn;
    string name;
    string desg;
    Node* next;
};

class SLL {
public:
    Node* header = nullptr;

    Node* create_new_node() {
        Node* new_node = new Node();
        cout << "Enter PRN, Name, Designation: ";
        cin >> new_node->prn >> new_node->name >> new_node->desg;
        new_node->next = nullptr;
        return new_node;
    }

    void insertP() {
        Node* temp = create_new_node();
        temp->next = header;
        header = temp;
    }

    void insertS() {
        Node* new_node = create_new_node();
        if (header == nullptr) {
            header = new_node;
        } else {
            Node* temp = header;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    void insertM() {
        int pos;
        cout << "Enter position to insert member: ";
        cin >> pos;
        Node* new_node = create_new_node();
        if (pos == 1) {
            new_node->next = header;
            header = new_node;
        } else {
            Node* temp = header;
            for (int i = 1; temp != nullptr && i < pos - 1; i++) {
                temp = temp->next;
            }
            if (temp != nullptr) {
                new_node->next = temp->next;
                temp->next = new_node;
            } else {
                cout << "Position is out of bounds.\n";
            }
        }
    }

    void display() {
        Node* temp = header;
        while (temp != nullptr) {
            cout << temp->prn << " -> " << temp->name << " -> " << temp->desg << endl;
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void delP() {
        if (header == nullptr) {
            cout << "No president to delete!\n";
            return;
        }
        Node* temp = header;
        header = header->next;
        delete temp;
        cout << "President deleted!\n";
    }

    void delS() {
        if (header == nullptr) {
            cout << "No secretary to delete!\n";
            return;
        }
        Node* temp = header;
        while (temp->next != nullptr && temp->next->next != nullptr) {
            temp = temp->next;
        }
        if (temp->next != nullptr) {
            delete temp->next;
            temp->next = nullptr;
            cout << "Secretary deleted!\n";
        } else {
            cout << "No secretary to delete!\n";
        }
    }

    void delM() {
        int pos;
        cout << "Enter position to delete member: ";
        cin >> pos;
        if (pos == 1) {
            delP();
        } else {
            Node* temp = header;
            for (int i = 1; temp != nullptr && i < pos - 1; i++) {
                temp = temp->next;
            }
            if (temp != nullptr && temp->next != nullptr) {
                Node* temp1 = temp->next;
                temp->next = temp1->next;
                delete temp1;
                cout << "Member deleted!\n";
            } else {
                cout << "Position is out of bounds.\n";
            }
        }
    }
};

void concatenate(Node*& l1, Node* l2) {
    if (l1 == nullptr) {
        l1 = l2;
    } else {
        Node* temp = l1;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = l2;
    }
}

int main() {
    int x;
    SLL l1, l2;

    // First Division Operations
    do {
        cout << "Division 1 Pinnacle Club:\n";
        cout << "Which operation you want to perform:\n";
        cout << "1) Insert President\n2) Insert Member\n3) Insert Secretary\n";
        cout << "4) Display List\n5) Delete President\n6) Delete Secretary\n";
        cout << "7) Delete Member\n8) Exit\n";
        cin >> x;

        switch (x) {
            case 1: l1.insertP(); break;
            case 2: l1.insertM(); break;
            case 3: l1.insertS(); break;
            case 4: l1.display(); break;
            case 5: l1.delP(); break;
            case 6: l1.delS(); break;
            case 7: l1.delM(); break;
            case 8: break;
            default: cout << "Invalid option!\n"; break;
        }
    } while (x != 8);

    // Second Division Operations
    do {
        cout << "Division 2 Pinnacle Club:\n";
        cout << "Which operation you want to perform:\n";
        cout << "1) Insert President\n2) Insert Member\n3) Insert Secretary\n";
        cout << "4) Display\n5) Delete President\n6) Delete Secretary\n";
        cout << "7) Delete Member\n8) Exit\n";
        cin >> x;

        switch (x) {
            case 1: l2.insertP(); break;
            case 2: l2.insertM(); break;
            case 3: l2.insertS(); break;
            case 4: l2.display(); break;
            case 5: l2.delP(); break;
            case 6: l2.delS(); break;
            case 7: l2.delM(); break;
            case 8: break;
            default: cout << "Invalid option!\n"; break;
        }
    } while (x != 8);

    cout << "CONCATENATING TWO CLUBS:\n";
    concatenate(l1.header, l2.header);
    cout << "Final List:\n";
    l1.display();

    return 0;
}
