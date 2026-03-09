# LRU Cache Implementation in C++

## Overview
This project implements a Least Recently Used (LRU) Cache using C++, demonstrating an efficient caching mechanism.

The cache supports O(1) time complexity for both get and put operations by combining:
- Hash Map (unordered_map)
- Doubly Linked List

This project demonstrates the use of data structures and pointer manipulation to achieve optimal performance.

## Problem Statement
Design a data structure that follows the constraints of an LRU Cache.

The cache should support two operations:

**1. get(key)**
- Return the value if the key exists.
- Otherwise return -1.
- Accessing the key makes it most recently used.
  
**2. put(key, value)**
- Insert or update the value.
- If the cache exceeds capacity:
- Remove the least recently used element.

## Why LRU Cache?
When cache capacity is limited, we need a policy to decide which item to remove.

LRU removes:
- Least Recently Used Item.

This ensures frequently accessed items remain in the cache.

## Data Structures Used
To achieve O(1) operations we combine two data structures.

**1. Hash Map**
unordered_map<int, Node*>

*Purpose:*
- Quickly locate nodes in the linked list.
- Provides constant time lookup.

*Example mapping:*

1 → Node(1,10)

2 → Node(2,20)
  
**2. Doubly Linked List**
Stores the actual cache entries.

*Structure:*

HEAD <-> Node <-> Node <-> Node <-> TAIL

*Where:*

HEAD → Most Recently Used

TAIL → Least Recently Used

This allows:
- Fast insertion
- Fast deletion
- Efficient reordering

## System Design
***Operations:***

**GET**
1. Locate node using hashmap
2. Move node to front
3. Return value

**PUT**
1. If key exists → update and move to front
2. If cache full → remove tail node
3. Insert new node at front

## Project Structure
lru-cache-cpp

│

├── main.cpp           # Program entry point

├── LRUCache.h         # Class declarations

├── LRUCache.cpp       # Implementation of cache logic

└── README.md          # Project documentation

## Time Complexity

- get:	O(1)
- put:	O(1)
  
*Reason:*
- Hash map provides constant lookup
- Doubly linked list provides constant insertion and deletion

## Space Complexity
O(capacity)
- We store at most capacity nodes in the cache.

## How to Run
*Compile:* g++ main.cpp LRUCache.cpp -o lru

*Run:* ./lru

*Expected Output:(according to input my code has)*

10

-1

## Real World Applications
LRU caching is widely used in:
- Web Browsers
- Stores recently visited pages for faster loading.
- Databases
- Caches frequently accessed queries.
- Operating Systems
- Used in page replacement algorithms.
- Content Delivery Networks (CDN)
- Stores frequently accessed web resources.

## Possible Improvements
Future enhancements could include:
- Thread-safe cache using mutex: This code only works for single threaded, but in practical multiple threads will be accessing so we can add mutex so prevent race condition.
- Generic template cache: Now we can only use int, but we can add the function for other datatypes like string, float etc.
- Persistent caching using files: we can upgrade it, so that this cache is saved even if our code is stopped or reloaded.
- Cache statistics: Like no of hits, miss or hit ratio.
- time to live: Expiration of cache.

## Skills Demonstrated
This project demonstrates knowledge of:
- Data Structures
- Hash Maps
- Doubly Linked Lists
- Pointer manipulation
- Cache design
- Time complexity optimization
