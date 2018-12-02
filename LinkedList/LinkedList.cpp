//
//  LinkedList.cpp
//  LinkedList
//
//  Created by Jangho Kim on 26/11/2018.
//  Copyright © 2018 김장호. All rights reserved.
//

#include "LinkedList.hpp"

#include <stdlib.h>
#include <iostream>

Node* LinkedList::CreateNode(int Data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    newNode->Data = Data;
    newNode->nextNode = NULL;
    
    return newNode;
}

void LinkedList::DestroyNode(Node* Node) {
    free(Node);
}

void LinkedList::PrintNode(Node* Node) {
    std::cout << "Data: " << Node->Data << std::endl << "nextNode: " << Node->nextNode << std::endl;
}

void LinkedList::AppendNode(Node** head, Node* newNode) {
    if((*head) == NULL) {
        *head = newNode;
    } else {
        Node* tail = (*head);
        while(tail->nextNode != NULL) {
            tail = tail->nextNode;
        }
        
        tail -> nextNode = newNode;
    }
}

Node* LinkedList::GetNode(Node *head, int location) {
    Node * current = head;
    while(current != NULL && (--location) >= 0) {
        current = current -> nextNode;
    }
    
    return current;
}

void LinkedList::RemoveNode(Node **head, Node *remove) {
    if(*head == remove) {
        *head = remove->nextNode;
    } else {
        Node* current = *head;
        while(current != NULL && current->nextNode != remove) {
            current = current->nextNode;
        }
    
        if( current != NULL) {
            current -> nextNode = remove -> nextNode;
        }
    }
}

void LinkedList::InsertNode(Node *current, Node *newNode) {
    newNode->nextNode = current->nextNode;
    current->nextNode = newNode;
}

int LinkedList::GetNodeCount(Node* head) {
    int count = 0;
    Node* current = head;
    
    while(current != NULL) {
        current = current->nextNode;
        count++;
    }
    
    return count;
}
