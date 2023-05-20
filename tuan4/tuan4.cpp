#include <iostream>

using namespace std;

template <class E>
struct Node
{
    E data;
    Node<E> *prev;
    Node<E> *next;
    Node(E e = E(), Node<E> *p = nullptr, Node<E> *n = nullptr) : data(e), prev(p), next(n) {}
};

template <class E>
class DList
{
protected:
    Node<E> *head;
    Node<E> *tail;
    int size;

public:
    DList() : head(nullptr), tail(nullptr), size(0) {}

    void addFirst(const E &newdata)
    {
        Node<E> *new_node = new Node<E>(newdata);
        if (head == nullptr && tail == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        size++;
    }
    void addLast(const E &newdata)
    {
        Node<E> *new_node = new Node<E>(newdata);
        if (head == nullptr)
        {
            addFirst(newdata);
        }
        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
            size++;
        }
    }
    void insert(const E &newdata, int a)
    {
        if (head == nullptr)
        {
            addFirst(newdata);
        }
        if (a < 0 || a > size)
            return;
        if (a == size)
        {
            addLast(newdata);
        }
        Node<E> *new_node = new Node<E>(newdata);
        Node<E> *current = head;
        Node<E> *current2 = new Node<E>();
        int count = 1;
        while (count < a - 1)
        {
            current = current->next;
            count++;
        }
        current2 = current->next;
        current->next = new_node;
        new_node->prev = current;
        current2->prev = new_node;
        new_node->next = current2;
        size++;

        // if(index<0 || index>size){

        // }
    }
    void deleteFirst()
    {
        Node<E> *node = new Node<E>();
        node = head;
        if (head == nullptr)
            return;
        if (tail->prev == nullptr)
        {

            delete head;
            head = tail = nullptr;
            return;
        }
        head = head->next;
        head->next->prev = nullptr;
        delete node;

        size--;
    }
    void deleteLast()
    {
        Node<E> *node = new Node<E>();
        node = tail;
        if (tail == nullptr)
            return;
        if (tail->prev == nullptr)
        {
            delete tail;
            head = tail = nullptr;
            return;
        }
        tail->prev->next = nullptr;
        delete node;
        tail = tail->prev;
        size--;
    }
    void deleteAtIndex(int a)
    {
        Node<E> *current = head;
        Node<E> *current2 = new Node<E>();

        if (a < 0 || a > size)
        {
            cout << "khong hop le" << endl;
        }
        else if (a == 0)
            deleteFirst();
        else if (a == size)
            deleteLast();

        else
        {

            int count = 1;
            while (count < a)
            {
                // if(count==size){
                //     break;
                // }
                current = current->next;
                count++;
            }
            current->next->prev = current->prev;
            current->prev->next = current->next;
            current2 = current;
            delete current2;
            size--;
        }
    }
    void print() const
    {
        Node<E> *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void print2()
    {
        for (Node<E> *current = head; current != nullptr; current = current->next)
        {
            cout << current->data << endl;
        }
    }
};
int main()
{
    DList<int> list;
    list.addFirst(5);
    list.addLast(8);
    list.addLast(7);
    list.addLast(5);
    // list.addLast(6);
    list.insert(1, 3);
    // list.deleteFirst();
    // list.deleteAtIndex(3);
    list.deleteAtIndex(4);
    // list.deleteLast();
    list.print(); // Print the list (outputs: 5)
    return 0;
}