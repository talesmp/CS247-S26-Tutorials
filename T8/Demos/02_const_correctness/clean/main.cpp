#include <iostream>
#include <string>

class List {
    struct Node { std::string data; Node* next; };
    Node* head = nullptr;
public:
    ~List() { while (head) { Node* n = head->next; delete head; head = n; } }
    void push_front(std::string s) { head = new Node{std::move(s), head}; }

    class Iterator {
        Node* cur;
    public:
        explicit Iterator(Node* cur) : cur{cur} {}
        Iterator& operator++()                    { cur = cur->next; return *this; }
        bool operator!=(const Iterator& o) const  { return cur != o.cur; }
        std::string& operator*() const            { return cur->data; }
    };
    class CIterator {
        const Node* cur;
    public:
        explicit CIterator(const Node* cur) : cur{cur} {}
        CIterator& operator++()                   { cur = cur->next; return *this; }
        bool operator!=(const CIterator& o) const { return cur != o.cur; }
        const std::string& operator*() const      { return cur->data; }
    };
    Iterator  begin()       { return Iterator{head}; }
    Iterator  end()         { return Iterator{nullptr}; }
    CIterator begin() const { return CIterator{head}; }
    CIterator end()   const { return CIterator{nullptr}; }
};

void shout(const List& list) {
    for (auto& word : list)
        word += "!";
}

int main() {
    List list;
    list.push_front("world");
    list.push_front("hello");
    shout(list);
}
