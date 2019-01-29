//
//  main.cpp
//  ArrayStack
//
//  Created by Jangho Kim on 16/01/2019.
//  Copyright © 2019 김장호. All rights reserved.
//

#include "ArrayStack.hpp"

int main(int argc, const char * argv[]) {
    ArrayStack stack;
    
    stack.CreateStack(10);
    
    for(int i=0;i<5;i++) {
        stack.Push(i);
    }
    
    std::cout << "Stack Size: " << stack.getStackSize() << std::endl;
    std::cout << "is Full? " << stack.isFull() << std::endl;
    
    for(int i=0;i<10;i++) {
        if(stack.isEmpty()) break;
        std::cout << "Stack[" << i << "] Data : " << stack.Pop() << std::endl;
    }
    
    stack.DestroyStack();
}
