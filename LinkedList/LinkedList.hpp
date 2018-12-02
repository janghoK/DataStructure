//
//  LinkedList.hpp
//  LinkedList
//
//  Created by Jangho Kim on 26/11/2018.
//  Copyright © 2018 김장호. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>

class Node {
    public:
        int Data;
        Node* nextNode;
};

class LinkedList {
    public:
    Node* CreateNode(int Data);
    void DestroyNode(Node* Node);
    void PrintNode(Node* Node);
    void AppendNode(Node** head, Node* newNode);
    Node* GetNode(Node* head, int location);
    void RemoveNode(Node** head, Node* remove);
    void InsertNode(Node* current, Node* newNode);
    int GetNodeCount(Node* head);
};

#endif /* LinkedList_hpp */
