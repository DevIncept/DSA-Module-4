# What is Open Addressing?
**Open addressing** The open addressing is another technique for collision resolution. Unlike chaining, it does not insert elements to some other data-structures. It inserts the data into the hash table itself. The size of the hash table should be larger than the number of keys.
There are three different popular methods for open addressing techniques. These methods are −
***Linear Probing***
***Quadratic Probing***
***Double Hashing***
In this technique, we use a hash function like other hash techniques. If the place is free, then insert the element into that location. Now if that place is not free, we will find another free element by using some equations. For the linear probing, we will use some linear equations, for quadratic probing, we will use some quadratic equations.
In the double hashing, when a collision occurs, we will use another hash function, then put into that location. That hash function is called the secondary hash function. That will not be used directly, if there is no collision.
## Why Open Addressing?
Open addressing is used when the frequency and number of keys is known. 5. Cache performance of chaining is not good as keys are stored using linked list. Open addressing provides better cache performance as everything is stored in the same table.

# What is Chaining?
The Chaining is one collision resolution technique. We cannot avoid collision, but we can try to reduce the collision, and try to store multiple elements for same hash value.
this technique suppose our hash function h(x) ranging from 0 to 6. So for more than 7 elements, there must be some elements, that will be places inside the same room. For that we will create a list to store them accordingly. In each time we will add at the beginning of the list to perform insertion in O(1) time.
## Why Chaining?
Chaining is a technique used for avoiding collisions in hash tables. A collision occurs when two keys are hashed to the same index in a hash table. Collisions are a problem because every slot in a hash table is supposed to store a single element.
# How to implement Chaining?
### Program:
#include<stdio.h>\
#include<stdlib.h>\
#define size 7\
struct node\
{\
    int data;\
    struct node *next;\
};\
struct node *chain[size];\
void init()\
{\
    int i;\
    for(i = 0; i < size; i++)\
        chain[i] = NULL;\
}\
void insert(int value)\
{\
    struct node *newNode = malloc(sizeof(struct node));\
    newNode->data = value;\
    newNode->next = NULL;\
    int key = value % size;\
    if(chain[key] == NULL)\
        chain[key] = newNode;\
    else\
    {\
        struct node *temp = chain[key];\
        while(temp->next)\
        {\
            temp = temp->next;\
        }\
        temp->next = newNode;\
    }\
}\
int search(int value)\
{\
    int key = value % size;\
    struct node *temp = chain[key];\
    while(temp)\
    {\
        if(temp->data == value)\
            return 1;\
        temp = temp->next;\
    }\
    return 0;\
}\
void print()\
{\
    int i;\
    for(i = 0; i < size; i++)\
    {\
        struct node *temp = chain[i];\
        printf("chain[%d]-->",i);\
        while(temp)\
        {\
            printf("%d -->",temp->data);\
            temp = temp->next;\
        }\
        printf("NULL\n");\
    }\
}\
int main()\
{\
    init();\
    insert(7);\
    insert(0);\
    insert(3);\
    insert(10);\
    insert(4);\
    insert(5);\
    print();\
    printf("Searching element 10\n");\
    if(search(10))\
        printf("Search Found\n");\
    else\
        printf("Search Not Found\n");\
    return 0;\
}\

#### Output :
<img src="https://github.com/NihalSuresh007/DSA/blob/main/dsa-cp-1/Open%20Addressing%20%26%20Chaining/Chaining.png" alternate="input">\
**Explanation:** Let's assume table size as 3.
Then the array of linked list will be,

-------------         -------------
|           |         |           |
| chain[0]  |-------> |    NULL   |
|           |         |           |
-------------         -------------
-------------         -------------
|           |         |           |
| chain[1]  |-------> |    NULL   |
|           |         |           |
-------------         -------------
-------------         -------------
|           |         |           |
| chain[2]  |-------> |    NULL   |
|           |         |           |
-------------         -------------

Initialize each list to NULL.
Insert 6
Hash key = 6 % 3 = 0.
Hence add the node with data 6 in the chain[0].

 -------------         ----------------
 |           |         |     |        |
 | chain[0]  |-------> |  6  | NULL   |
 |           |         |     |        |
 -------------         ----------------
 -------------         -------------
 |           |         |           |
 | chain[1]  |-------> |    NULL   |
 |           |         |           |
 -------------         -------------
 -------------         -------------
 |           |         |           |
 | chain[2]  |-------> |    NULL   |
 |           |         |           |
 -------------         -------------

# How to implement Open Addressing?
### Program:
#include<bits/stdc++.h>   
using namespace std;   
template<typename K, typename V>     
class HashNode   
{   
    public:   
    V value;  
    K key;   
    HashNode(K key, V value)   
    {   
        this->value = value;   
        this->key = key;   
    }   
};   
template<typename K, typename V>     
class HashMap   
{   
    HashNode<K,V> \*\*arr;     
    int capacity;     
    int size;      
    HashNode<K,V> \*dummy;     
    public:   
    HashMap()   
    {   
        capacity = 20;   
        size=0;   
        arr = new HashNode<K,V>\*\[capacity\];   
        for(int i=0 ; i < capacity ; i++)   
            arr\[i\] = NULL;   
        dummy = new HashNode<K,V>(-1, -1);   
    }  
    int hashCode(K key)   
    {   
        return key % capacity;   
    }   
    void insertNode(K key, V value)   
    {   
        HashNode<K,V> \*temp = new HashNode<K,V>(key, value);   
        int hashIndex = hashCode(key);   
        while(arr\[hashIndex\] != NULL && arr\[hashIndex\]->key != key   
               && arr\[hashIndex\]->key != -1)   
        {   
            hashIndex++;   
            hashIndex %= capacity;   
        }   
        if(arr\[hashIndex\] == NULL || arr\[hashIndex\]->key == -1)   
            size++;   
        arr\[hashIndex\] = temp;   
    }   
    V deleteNode(int key)   
    {   
        int hashIndex = hashCode(key);   
        while(arr\[hashIndex\] != NULL)    
        {   
            if(arr\[hashIndex\]->key == key)   
            {   
                HashNode<K,V> \*temp = arr\[hashIndex\];   
                arr\[hashIndex\] = dummy;     
                size--;   
                return temp->value;   
            }   
            hashIndex++;   
            hashIndex %= capacity;   
        }   
        return NULL;   
    }   
    V get(int key)   
    {   
        int hashIndex = hashCode(key);   
        int counter=0;   
        while(arr\[hashIndex\] != NULL)   
        {    int counter =0;   
             if(counter++>capacity)     
                return NULL;           
             if(arr\[hashIndex\]->key == key)   
                return arr\[hashIndex\]->value;   
            hashIndex++;   
            hashIndex %= capacity;   
        }   
        return NULL;   
    }   
    int sizeofMap()   
    {   
        return size;   
    }   
    bool isEmpty()   
    {   
        return size == 0;   
    }   
    void display()   
    {   
        for(int i=0 ; i<capacity ; i++)   
        {   
            if(arr\[i\] != NULL && arr\[i\]->key != -1)   
                cout << "key = " << arr\[i\]->key                    
                     <<"  value = "<< arr\[i\]->value << endl;   
        }   
    }   
};   
int main()   
{   
    HashMap<int, int> \*h = new HashMap<int, int>;   
    h->insertNode(1,1);   
    h->insertNode(2,2);   
    h->insertNode(2,3);   
    h->display();   
    cout << h->sizeofMap() <<endl;   
    cout << h->deleteNode(2) << endl;   
    cout << h->sizeofMap() <<endl;   
    cout << h->isEmpty() << endl;   
    cout << h->get(2);   
    return 0;   
}   
#### Output:
<img src="https://github.com/NihalSuresh007/DSA/blob/main/dsa-cp-1/Open%20Addressing%20%26%20Chaining/Addressing.png" alternate="input">\
**Explanation:** In Open Addressing, all elements are stored in the hash table itself. So at any point, size of table must be greater than or equal to total number of keys (Note that we can increase table size by copying old data if needed).
Insert(k) – Keep probing until an empty slot is found. Once an empty slot is found, insert k.
Search(k) – Keep probing until slot’s key doesn’t become equal to k or an empty slot is reached.
Delete(k) – Delete operation is interesting. If we simply delete a key, then search may fail. So slots of deleted keys are marked specially as “deleted”.
Here, to mark a node deleted we have used dummy node with key and value -1.
Insert can insert an item in a deleted slot, but search doesn’t stop at a deleted slot.
The entire process ensures that for any key, we get an integer position within the size of the Hash Table to insert the corresponding value.
So the process is simple, user gives a (key, value) pair set as input and based on the value generated by hash function an index is generated to where the value corresponding to the particular key is stored. So whenever we need to fetch a value corresponding to a key that is just O(1).


Contributed by [NihalSuresh](https://github.com/NihalSuresh007) , If you find it helpful , don't forget to drop a like 💖	Contributed by [NihalSuresh](https://github.com/NihalSuresh007) 😊 , If you find it helpful , don't forget to drop a like 💖
##### connect with NihalSuresh 😊	
[Linkedin](https://www.linkedin.com/in/nihal-s-b0535a191)
