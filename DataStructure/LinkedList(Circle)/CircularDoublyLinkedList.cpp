//
//  CircularDoublyLinkedList.cpp
//  LinkedList(Circle_Doubly)
//
//  Created by Jangho Kim on 10/01/2019.
//  Copyright © 2019 김장호. All rights reserved.
//

#include "CircularDoublyLinkedList.hpp"

Node* CircularDoublyLinkedList::CreateNode(int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    newNode->Data = newData;
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;
    
    return newNode;
}

void CircularDoublyLinkedList::DestroyNode(Node *current) {
    free(current);
}

void CircularDoublyLinkedList::RemoveNode(Node* remove) {
    if(head == remove) head = (nodeCount > 1) ? remove->nextNode : NULL;
    
    remove->nextNode->prevNode = remove->prevNode;
    remove->prevNode->nextNode = remove->nextNode;
    
    remove->nextNode = NULL;
    remove->prevNode = NULL;
    
    DestroyNode(remove);
    
    nodeCount--;
}

void CircularDoublyLinkedList::AppendNode(Node *newNode) {
    if(head == NULL) {
        head = newNode;
        head->nextNode = head;
        head->prevNode = head;
    } else {
        Node* tail = head->prevNode;
        
        head->prevNode = newNode;
        tail->nextNode = newNode;
        
        newNode->nextNode = head;
        newNode->prevNode = tail;
    }
    
    nodeCount++;
}

void CircularDoublyLinkedList::InsertNode(Node *current, Node *newNode, char mode) {
    switch(mode) {
        case 'b':
        case 'B':
            newNode->nextNode = current;
            newNode->prevNode = current->prevNode;
            
            current->prevNode->nextNode = newNode;
            current->prevNode = newNode;
            break;
        case 'a':
        case 'A':
            newNode->nextNode = current->nextNode;
            newNode->prevNode = current;
            
            current->nextNode->prevNode = newNode;
            current->nextNode = newNode;
            break;
    }
    
    nodeCount++;
}

Node* CircularDoublyLinkedList::GetNodeAt_next(int location) {
    Node* current = head;
    while(location-- > 0) {
        current = current->nextNode;
    }
    
    return current;
}

Node* CircularDoublyLinkedList::GetNodeAt_prev(int location) {
    Node* current = head->prevNode;
    while(location-- > 0) {
        current = current->prevNode;
    }
    
    return current;
}

void CircularDoublyLinkedList::PrintNode(Node *current) {
    std::cout << "Data : " << current->Data << std::endl;
    std::cout << "self : " << current << std::endl;
    std::cout << "nextNode : " << current->nextNode << std::endl;
    std::cout << "prevNode : " << current->prevNode << std::endl;
    std::cout << "head : " << head << std::endl << std::endl;
}

void CircularDoublyLinkedList::PrintAllNode() {
    Node* current = head;
    for(int i=0;i<nodeCount;i++) {
        std::cout << "List[" << i << "]" << std::endl;
        std::cout << "Data : " << current->Data << std::endl;
        std::cout << "self : " << current << std::endl;
        std::cout << "nextNode : " << current->nextNode << std::endl;
        std::cout << "prevNode : " << current->prevNode << std::endl;
        std::cout << "head : " << head << std::endl << std::endl;
        
        current = current->nextNode;
    }
}

int CircularDoublyLinkedList::GetNodeCount() {
    return nodeCount;
}
