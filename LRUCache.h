#ifndef LRUCACHE_H
#define LRUCACHE_H
#include <unordered_map>

class Node{
    public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v);
};

class LRUCache {
    private:
    int capacity;
    std::unordered_map<int, Node*> cache;

    Node* head;
    Node* tail;

    void addNode(Node* node);
    void removeNode(Node* node);

    public:
    LRUCache(int cap);

    int get(int key);
    void put(int key, int value);
};

#endif