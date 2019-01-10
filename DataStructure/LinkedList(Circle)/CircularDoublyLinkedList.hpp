//
//  CircularDoublyLinkedList.hpp
//  LinkedList(Circle_Doubly)
//
//  Created by Jangho Kim on 10/01/2019.
//  Copyright © 2019 김장호. All rights reserved.
//

#ifndef CircularDoublyLinkedList_hpp
#define CircularDoublyLinkedList_hpp

#include <stdio.h>
#include <iostream>

class Node {
public:
    int Data;
    Node* nextNode;
    Node* prevNode;
};

class CircularDoublyLinkedList {
private:
    Node* head = NULL;
    int nodeCount = 0;
public:
    Node* CreateNode(int newData);
    void DestroyNode(Node* current);
    void RemoveNode(Node* remove);
    void AppendNode(Node* newNode);
    void InsertNode(Node* current, Node* newNode, char mode='b');
    Node* GetNodeAt_next(int location);
    Node* GetNodeAt_prev(int location);
    void PrintNode(Node* current);
    void PrintAllNode();
    int GetNodeCount();
};
#endif /* CircularDoublyLinkedList_hpp */
