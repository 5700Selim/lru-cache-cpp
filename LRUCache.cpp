#include "LRUCache.h"

Node::Node(int k, int v) {
    key = k;
    value = v;
    prev = nullptr;
    next = nullptr;
}

LRUCache::LRUCache(int cap) {
    capacity = cap;

    head = new Node(-1, -1);
    tail = new Node(-1, -1);

    head->next = tail;
    tail->prev = head;
}

void LRUCache::addNode(Node* node) {
    node->next = head->next;
    node->prev = head;

    head->next->prev = node;
    head->next = node;
}

void LRUCache::removeNode(Node* node) {
    Node* prevNode = node->prev;
    Node* nextNode = node->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;
}

int LRUCache::get(int key) {

    if (cache.find(key) == cache.end())
        return -1;

    Node* node = cache[key];

    removeNode(node);
    addNode(node);

    return node->value;
}

void LRUCache::put(int key, int value) {

    if (cache.find(key) != cache.end()) {
        Node* existing = cache[key];

        removeNode(existing);
        cache.erase(key);
    }

    if (cache.size() == capacity) {
        Node* lru = tail->prev;

        removeNode(lru);
        cache.erase(lru->key);
    }

    Node* newNode = new Node(key, value);

    addNode(newNode);
    cache[key] = newNode;
}