//
//  LinkedListStack.cpp
//  LinkedListStack
//
//  Created by Jangho Kim on 22/01/2019.
//  Copyright © 2019 김장호. All rights reserved.
//

#include "LinkedListStack.hpp"

LinkedListStack::LinkedListStack() {
    head = NULL;
    tail = NULL;
}

Node* LinkedListStack::CreateNode(int newData) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    
    newNode->Data = newData;
    newNode->nextNode = NULL;
    
    return newNode;
}

void LinkedListStack::DestroyStack() {
    while(head != NULL) {
        Node* popNode = Pop();
        DestroyNode(popNode);
    }
}

void LinkedListStack::DestroyNode(Node *current) {
    free(current);
}

void LinkedListStack::Push(Node *newNode) {
    if(head == NULL) {
        head = newNode;
    } else {
        tail->nextNode = newNode;
    }
    tail = newNode;
}

Node* LinkedListStack::Pop() {
    Node* popNode = tail;
    
    if(head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        Node* current = head;
        
        while(current->nextNode != popNode) {
            current = current->nextNode;
        }
        
        tail = current;
        tail->nextNode = NULL;
    }
    
    return popNode;
}

int LinkedListStack::GetSize() {
    Node* current = head;
    int count = 0;
    
    while(current != NULL) {
        current = current->nextNode;
        count++;
    }
    
    return count;
}

