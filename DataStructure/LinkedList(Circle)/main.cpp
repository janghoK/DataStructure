//
//  main.cpp
//  LinkedList(Circle_Doubly)
//
//  Created by Jangho Kim on 10/01/2019.
//  Copyright © 2019 김장호. All rights reserved.
//

#include "CircularDoublyLinkedList.hpp"

int main(int argc, const char * argv[]) {
    CircularDoublyLinkedList List;
    Node* current = NULL;
    int count = 0;
    
    // 노드 5개 추가
    for(int i=0;i<5;i++)
        List.AppendNode(List.CreateNode(i));
    
    // 리스트 출력
    std::cout << "----phase 1----" << std::endl;
    List.PrintAllNode();
    
    // 리스트 앞에서 3번째 노드 뒤에 새로운 노드 삽입
    current = List.GetNodeAt_next(2);
    List.InsertNode(current, List.CreateNode(1000), 'a');
    
    // 노드 수의 2배만큼 반복하여 환형인지 확인
    std::cout << "----phase 2----" << std::endl;
    count = List.GetNodeCount();
    for(int i=0;i<count*2;i++) {
        std::cout << "List[" << i << "]" << std::endl;
        current = List.GetNodeAt_next(i);
        List.PrintNode(current);
    }
    
    // 모든 노드를 메모리에서 제거
    count = List.GetNodeCount();
    for(int i=0;i<count;i++) {
        current = List.GetNodeAt_next(0);
        List.RemoveNode(current);
    }
    
    List.PrintAllNode();
    
    return 0;
}
