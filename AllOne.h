//
// Created by 刘汉乙 on 2021/11/16.
//

#ifndef A1_ALLONE_H
#define A1_ALLONE_H
#include<string>
#include<unordered_map>
using namespace std;

struct Node{
    Node* prev;
    Node* next;
    string key;
    int count;
    Node(){prev = NULL; next = NULL; count = 0;}
    Node(string _key, int _count){prev = NULL; next = NULL; count = 0; key = _key; count = _count;}
};

class AllOne {
public:
    unordered_map<string,Node*> verticalMap;
    Node* head;
    Node* tail;

    AllOne() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    void inc(string key) {
        if (verticalMap.find(key) == verticalMap.end()){
            Node* newNode = new Node(key, 1);
            Node* prev = tail->prev;
            prev->next = newNode; newNode->prev = prev;
            tail->prev = newNode; newNode->next = tail;
            verticalMap[key] = newNode;
        }else{
            Node* node = verticalMap[key];
            node->count++;
            while(node->prev->count < node->count && node->prev != head){
                Node* secondPrev = node->prev->prev;
                Node* prev = node->prev;
                secondPrev->next = node; node->prev = secondPrev;
                node->next->prev = prev; prev->next = node->next;
                node->next = prev; prev->prev = node;
            }
        }
    }

    void dec(string key) {
        Node* node = verticalMap[key];
        node->count--;
        if (node->count == 0){
            Node* prev = node->prev;
            Node* next = node->next;
            prev->next = next; next->prev = prev;
        }else {
            while (node->count < node->next->count && node->next != tail) {
                Node *firstNode = node->next;
                Node *secondNode = firstNode->next;
                node->prev->next = firstNode; firstNode->prev = node->prev;
                firstNode->next = node; node->prev = firstNode;
                secondNode->prev = node; node->next = secondNode;
            }
        }
    }

    string getMaxKey() {
        if (head->next == tail) return "";
        else return head->next->key;
    }

    string getMinKey() {
        if (tail->prev == head) return "";
        else return tail->prev->key;
    }
};


#endif //A1_ALLONE_H
