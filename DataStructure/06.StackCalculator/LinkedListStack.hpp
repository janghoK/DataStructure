//
//  LinkedListStack.hpp
//  StackCalculator
//
//  Created by Jangho Kim on 28/01/2019.
//  Copyright © 2019 김장호. All rights reserved.
//

#ifndef LinkedListStack_hpp
#define LinkedListStack_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Node {
public:
    char *Data;
    Node *nextNode;
};

class LinkedListStack {
private:
    Node *head;
    Node *tail;
public:
    LinkedListStack();
    Node* CreateNode(char *newData);
    void DestroyStack();
    void DestroyNode(Node *current);
    void Push(Node *newNode);
    Node* Pop();
    Node* GetTop();
    bool isEmpty();
};
#endif /* LinkedListStack_hpp */
