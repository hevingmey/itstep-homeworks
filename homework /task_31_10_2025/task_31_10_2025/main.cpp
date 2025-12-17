#include <iostream>
using namespace std;

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value, Node* next = nullptr)
            : data(value), next(next) {}
    };

    Node* head;
    Node* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    ~List() {
        DeleteAll();
    }

    void AddH(const T& value) {
        Node* newNode = new Node(value, head);
        head = newNode;
        if (tail == nullptr) {
            tail = head;
        }
    }

    void AddT(const T& value) {
        Node* newNode = new Node(value, nullptr);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool DeleteH() {
        if (head == nullptr)
            return false;

        Node* temp = head;
        head = head->next;
        delete temp;

        if (head == nullptr)
            tail = nullptr;

        return true;
    }

    bool DeleteT() {
        if (head == nullptr)
            return false;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return true;
        }

        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }

        delete tail;
        tail = current;
        tail->next = nullptr;
        return true;
    }

    void DeleteAll() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void Show() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    List<int> list;

    list.AddH(3);
    list.AddH(2);
    list.AddH(1);
    list.Show();

    list.AddT(4);
    list.AddT(5);
    list.Show();

    list.DeleteH();
    list.Show();

    list.DeleteT();
    list.Show();

    list.DeleteAll();
    list.Show();

    return 0;
}
