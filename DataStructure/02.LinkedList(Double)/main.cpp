//
//  main.cpp
//  LinkedList(Double)
//
//  Created by Jangho Kim on 07/12/2018.
//  Copyright © 2018 김장호. All rights reserved.
//

#include <iostream>
#include "DoublyLinkedList.hpp"

int main(int argc, const char * argv[]) {
    DoublyLinkedList DLL;

    Node* current;
    
    int count = 0;
    
    // 노드 5개 추가
    for(int i=0;i<5;i++) DLL.AppendNode(DLL.CreateNode(i));
    
    // 리스트 출력
    std::cout << "Print List" << std::endl;
    DLL.PrintAllNode();
    
    // 리스트 헤드부터 3번째 노드 뒤에 노드 삽입
    current = DLL.GetNodeAt_next(2);
    DLL.InsertNode(current, DLL.CreateNode(1000), 'a');
    
    // 리스트 출력
    std::cout << "Print List" << std::endl;
    DLL.PrintAllNode();

    // 모든 노드를 메모리에서 제거
    std::cout << "Destroy All Node" << std::endl;
    
    // 헤드부터 지우기
    count = DLL.GetNodeCount();
    for(int i=0;i<count;i++) {
        current = DLL.GetNodeAt_next(0);
        if(current != NULL) {
            DLL.RemoveNode(current);
            DLL.DestroyNode(current);
        }
        std::cout << std::endl << "phase : " << i << std::endl;
        DLL.PrintAllNode();
    }
    
    // 테일부터 지우기
    /*
    count = DLL.GetNodeCount();
    for(int i=0;i<count;i++) {
        current = DLL.GetNodeAt_prev(0);
        if(current != NULL) {
            DLL.RemoveNode(current);
            DLL.DestroyNode(current);
        }
        std::cout << std::endl << "phase : " << i << std::endl;
        DLL.PrintAllNode();
    }
    */
}
