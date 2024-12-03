#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    int per_id;
    string per_name;
    int per_age;

public:

    Person(int id = 0, string name = "", int age = 0) : per_id(id), per_name(name), per_age(age) {}

    void input() {
        cout << "Enter ID: ";
        cin >> per_id;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, per_name);
        cout << "Enter Age: ";
        cin >> per_age;
    }

    void output() const {
        cout << "ID: " << per_id << ", Name: " << per_name << ", Age: " << per_age << endl;
    }
};

struct Node {
    Person data;
    Node* next;

    Node(Person p) : data(p), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:

    LinkedList() : head(nullptr) {}

    void insertHead(Person p) {
        Node* newNode = new Node(p);
        newNode->next = head;
        head = newNode;
    }

    void display() const {
        Node* current = head;
        while (current != nullptr) {
            current->data.output();
            current = current->next;
        }
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    int n;
    cout << "Enter the number of persons: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter details for person " << i + 1 << ":" << endl;
        Person p;
        p.input();
        list.insertHead(p);
    }

    cout << "\nDetails of all persons in the list:" << endl;
    list.display();

    return 0;
}