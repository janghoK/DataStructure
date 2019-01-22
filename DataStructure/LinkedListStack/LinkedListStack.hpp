//
//  LinkedListStack.hpp
//  LinkedListStack
//
//  Created by Jangho Kim on 22/01/2019.
//  Copyright © 2019 김장호. All rights reserved.
//

#ifndef LinkedListStack_hpp
#define LinkedListStack_hpp

#include <stdio.h>
#include <stdlib.h>

class Node {
public:
    int Data;
    Node *nextNode;
};

class LinkedListStack {
private:
    Node *head;
    Node *tail;
public:
    LinkedListStack();
    Node* CreateNode(int newData);
    void DestroyStack();
    void DestroyNode(Node *current);
    void Push(Node *newNode);
    Node* Pop();
    int GetSize();
};


#endif /* LinkedListStack_hpp */
