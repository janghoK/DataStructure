//
//  DoubleLinkedList.cpp
//  LinkedList(Double)
//
//  Created by Jangho Kim on 07/12/2018.
//  Copyright © 2018 김장호. All rights reserved.
//

#include "DoublyLinkedList.hpp"
Node* DoublyLinkedList::CreateNode(int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    newNode->Data = newData;
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;
    return newNode;
}

void DoublyLinkedList::DestroyNode(Node *node) {
    free(node);
}

void DoublyLinkedList::AppendNode(Node *newNode) {
    if((head) == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        Node* temp = head;
        while(temp->nextNode != NULL) {
            temp = temp->nextNode;
        }
        temp->nextNode = newNode;
        newNode->prevNode = temp;
        tail = newNode;
    }
}

void DoublyLinkedList::InsertNode(Node *current, Node *newNode, char mode) {
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        switch(mode) {
            case 'b':
            case 'B':
                newNode->nextNode = current;
                newNode->prevNode = current->prevNode;
                
                if(current->prevNode != NULL) current->prevNode->nextNode = newNode;
                current->prevNode = newNode;
                
                if(head == current) head = newNode;
                break;
            case 'a':
            case 'A':
                newNode->nextNode = current->nextNode;
                newNode->prevNode = current;
                
                if(current->nextNode != NULL) current->nextNode->prevNode = newNode;
                current->nextNode = newNode;
                
                if(tail == current) tail = newNode;
                break;
        }
    }
}

void DoublyLinkedList::RemoveNode(Node *remove) {
    if(head == remove) head = remove->nextNode;
    if(tail == remove) tail = remove->prevNode;

    if(remove->prevNode != NULL) remove->prevNode->nextNode = remove->nextNode;
    if(remove->nextNode != NULL) remove->nextNode->prevNode = remove->prevNode;
    
    remove->nextNode = NULL;
    remove->prevNode = NULL;
}

Node* DoublyLinkedList::GetNodeAt_next(int location) {
    Node* current = head;
    
    while(current->nextNode != NULL && location-- > 0) {
        current = current->nextNode;
    }
    
    return current;
}

Node* DoublyLinkedList::GetNodeAt_prev(int location) {
    Node* current = tail;
    
    while(current->prevNode != NULL && location-- > 0) {
        current = current->prevNode;
    }
    
    return current;
}

int DoublyLinkedList::GetNodeCount() {
    int count = 0;
    Node* current = head;
    
    while(current != NULL) {
        current = current->nextNode;
        count++;
    }
    
    return count;
}

void DoublyLinkedList::PrintNode(Node *node) {
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Node Data : " << node->Data << std::endl;
    std::cout << "Node nextNode : " << node->nextNode << std::endl;
    std::cout << "Node prevNode : " << node->prevNode << std::endl;
    std::cout << "Node head : " << head << std::endl;
    std::cout << "Node tail : " << tail << std::endl;
    std::cout << "----------------------------------" << std::endl;
}

void DoublyLinkedList::PrintAllNode() {
    Node* node = head;
    while(node != NULL) {
        std::cout << "----------------------------------" << std::endl;
        std::cout << "Node Data : " << node->Data << std::endl;
        std::cout << "Node nextNode : " << node->nextNode << std::endl;
        std::cout << "Node prevNode : " << node->prevNode << std::endl;
        std::cout << "Node head : " << head << std::endl;
        std::cout << "Node tail : " << tail << std::endl;
        std::cout << "----------------------------------" << std::endl;
        node = node->nextNode;
    }
}
