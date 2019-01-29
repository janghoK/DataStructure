//
//  main.cpp
//  LinkedListStack
//
//  Created by Jangho Kim on 22/01/2019.
//  Copyright © 2019 김장호. All rights reserved.
//

#include <iostream>
#include "LinkedListStack.hpp"

int main(int argc, const char * argv[]) {
    int count = 0;
    Node *popNode = NULL;
    
    LinkedListStack stack;
    
    stack.Push(stack.CreateNode(1));
    stack.Push(stack.CreateNode(2));
    stack.Push(stack.CreateNode(3));
    stack.Push(stack.CreateNode(4));
    stack.Push(stack.CreateNode(5));
    
    count = stack.GetSize();
    
    for(int i=0;i<count;i++) {
        popNode = stack.Pop();
        std::cout << "pop: " << i << "  Data: " << popNode->Data << std::endl;
        stack.DestroyNode(popNode);
    }
    
    stack.DestroyStack();
}
