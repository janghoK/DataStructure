//
//  ArrayStack.hpp
//  ArrayStack
//
//  Created by Jangho Kim on 16/01/2019.
//  Copyright © 2019 김장호. All rights reserved.
//

#ifndef ArrayStack_hpp
#define ArrayStack_hpp

#include <stdio.h>
#include <iostream>

class Node {
public:
    int Data;
};

class ArrayStack {
private:
    int Capacity;
    int Top;
    Node *Nodes;

public:
    void CreateStack(int capacity);
    void DestroyStack();
    void Push(int newData);
    int Pop();
    int getStackSize();
    bool isEmpty();
    bool isFull();
};

#endif /* ArrayStack_hpp */
