#pragma once

class HashTable {
protected:
    int capacity;

    int hash(int);
public:
    // HashTable();
    HashTable(int capacity);
};

class HashTableChaining : public HashTable {
private:
    class Node {
    public:
        int data;
        Node* pNext;

        Node() {
            this->data = 0;
            this->pNext = nullptr;
        }

        Node(int data) {
            this->data = data;
            this->pNext = nullptr;
        }
    };

    Node** HT;

    void insert(int, int);
    bool find(int, int);
    void showLinkedList(Node*);
    void deleteList(Node*);

public: 
    HashTableChaining(int capacity);
    ~HashTableChaining();

    void add(int);
    void showTable();
    bool find(int);
};

class HashTableOpenAddressing : public HashTable {
};