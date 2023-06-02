#pragma once

class HashTable {
protected:
    int capacity;

    int hash(int);
public:
    HashTable(int capacity);

    virtual void add(int) = 0;
    virtual void showTable() = 0;
    virtual bool find(int) = 0;
    virtual void remove(int) = 0;
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
    HashTableChaining(int);
    ~HashTableChaining();

    void add(int);
    void showTable();
    bool find(int);
    void remove(int);
};

class HashTableOpenAddressing : public HashTable {
protected:
    int *HT;

public:
    HashTableOpenAddressing(int);
    ~HashTableOpenAddressing();

    virtual int probing(int) = 0;

    void showTable();
    void add(int);
};

class LinearProbing : public HashTableOpenAddressing {
public:
    LinearProbing(int);

    bool find(int);
    void remove(int);
    int probing(int);
};

class QuadraticProbing : public HashTableOpenAddressing {
public:
    QuadraticProbing(int);

    bool find(int);
    void remove(int);
    int probing(int);
};

class DoubleHashing : public HashTableOpenAddressing {
private:
    int hash2(int);

public:
    DoubleHashing(int);

    bool find(int);
    void remove(int);
    int probing(int);
};