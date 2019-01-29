//
//  DoubleLinkedList.hpp
//  LinkedList(Double)
//
//  Created by Jangho Kim on 07/12/2018.
//  Copyright © 2018 김장호. All rights reserved.
//

#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

#include <stdio.h>
#include <iostream>

class Node {
    public:
    int Data;
    Node* prevNode;
    Node* nextNode;
};

class DoublyLinkedList {
    private:
    Node* head = NULL;
    Node* tail = NULL;
    
    public:
    Node* CreateNode(int Data);
    void DestroyNode(Node* node);
    void AppendNode(Node* newNode);
    void InsertNode(Node* current, Node* newNode, char mode='b');
    void RemoveNode(Node* remove);
    Node* GetNodeAt_next(int location);
    Node* GetNodeAt_prev(int location);
    int GetNodeCount();
    void PrintNode(Node* node);
    void PrintAllNode();
};
#endif /* DoubleLinkedList_hpp */
