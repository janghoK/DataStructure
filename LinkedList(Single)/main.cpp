//
//  main.cpp
//  LinkedList
//
//  Created by Jangho Kim on 26/11/2018.
//  Copyright © 2018 김장호. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"


int main(int argc, const char * argv[]) {
    Node* list = NULL;
    Node* myNode = NULL;
    Node* newNode = NULL;
    LinkedList SSL;
    int cnt = 0;
    
    SSL.AppendNode(&list, SSL.CreateNode(98));
    SSL.AppendNode(&list, SSL.CreateNode(37));
    SSL.AppendNode(&list, SSL.CreateNode(12));
    
    cnt = SSL.GetNodeCount(list);
    for(int i=0;i<cnt;i++)
        SSL.PrintNode(SSL.GetNode(list,i));
    
    newNode = SSL.CreateNode(16);
    myNode = SSL.GetNode(list, 0);
    SSL.InsertNode(myNode, newNode);

    std::cout << std::endl;
    
    cnt = SSL.GetNodeCount(list);
    for(int i=0;i<cnt;i++)
        SSL.PrintNode(SSL.GetNode(list,i));
    
    myNode = SSL.GetNode(list, 2);
    SSL.RemoveNode(&list, myNode);
    SSL.DestroyNode(myNode);
    
    std::cout << std::endl;
    
    cnt = SSL.GetNodeCount(list);
    for(int i=0;i<cnt;i++)
        SSL.PrintNode(SSL.GetNode(list,i));
    
    return 0;
}
