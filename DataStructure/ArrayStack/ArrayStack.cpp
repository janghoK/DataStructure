//
//  ArrayStack.cpp
//  ArrayStack
//
//  Created by Jangho Kim on 16/01/2019.
//  Copyright © 2019 김장호. All rights reserved.
//

#include "ArrayStack.hpp"

void ArrayStack::CreateStack(int capacity) {
    // 입력된 용량만큼 노드를 자유저장소에 생성
    Nodes = (Node*)malloc(sizeof(Node) * capacity);
    
    // capacity 및 top 초기화
    Capacity = capacity;
    Top = 0; // index는 0부터 시작
}

void ArrayStack::DestroyStack() {
    free(Nodes);
}

void ArrayStack::Push(int newData) {
    Nodes[Top++].Data = newData;
}

int ArrayStack::Pop() {
    return Nodes[--Top].Data;
}

int ArrayStack::getStackSize() {
    return Top;
}

bool ArrayStack::isEmpty() {
    return (Top == 0);
}

bool ArrayStack::isFull() {
    return (Top == Capacity);
}
