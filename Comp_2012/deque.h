#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
class BiLNode {
public:
    T data {};
    BiLNode<T> *next {nullptr};
    BiLNode<T> *prev {nullptr};
    BiLNode(T input) {
        data = input;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class Deque {
private:
    BiLNode<T> *head {nullptr};
    BiLNode<T> *tail {nullptr};
    int size {0};
public:
    Deque() = default;
    ~Deque() {
        BiLNode <T>* tmp = head;
        while(tmp != nullptr) {
            tmp = tmp->next;
            delete head;
            head = tmp;
        }
    }

    void push_back(const T& value) {
        if(head == nullptr) {
            head = new BiLNode<T> (value);
            tail = head;
        } else {
            BiLNode<T> *tmp = new BiLNode<T> (value);
            tmp->prev = tail;
            tail->next = tmp;
            tail = tmp;
        }
        size++;
    }

    void push_front(const T& value) {
        if(head == nullptr) {
            head = new BiLNode<T> (value);
            tail = head;
        } else {
            BiLNode<T> *tmp = new BiLNode<T> (value);
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
        }
        size++;
    }

    T pop_back() {
        if (head == nullptr) {
            cout << "Nothing in deque!";
        }
        if (head->next == nullptr) {
            T tmp = head->data;
            delete head;
            head = nullptr;
            size--;
            return tmp;
        }
        T tmp = tail->data;
        BiLNode<T> *bftail = tail->prev;
        delete tail;
        tail = bftail;
        tail->next = nullptr;
        size--;
        return tmp;
    }

    T pop_front() {
        if (head == nullptr) {
            cout << "Nothing in deque!";
        }
        if (head->next == nullptr) {
            T tmp = head->data;
            delete head;
            head = nullptr;
            size--;
            return tmp;
        }
        T tmp = head->data;
        BiLNode<T> *afhead = head->next;
        delete head;
        head = afhead;
        head->prev = nullptr;
        size--;
        return tmp;
    }

    void clear() {
        while(size>0) this->pop_back();
    }

    // TODO 1: overload operator==

    // TODO 2: overload operator=

    // TODO 3: overload operator+

    // TODO 4: overload operator<<

};

#endif