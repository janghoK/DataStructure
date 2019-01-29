//
//  main.cpp
//  StackCalculator
//
//  Created by Jangho Kim on 28/01/2019.
//  Copyright © 2019 김장호. All rights reserved.
//

#include <iostream>
#include "Calculator.hpp"

int main(int argc, const char * argv[]) {
    
    Calculator cal;
    
    char postfix[100];
    double result;
    
    std::cout << "---------- phase 1 ----------" << std::endl;
    memset(postfix,0,100);
    
    cal.GetPostfix((char*)"1 + ( 2 - 3 ) * 4 + 5", postfix);
    std::cout << postfix << std::endl;
    
    result = cal.Calculate(postfix);
    std::cout << result << std::endl;
    
    std::cout << "---------- phase 2 ----------" << std::endl;
    memset(postfix,0,100);
    
    cal.GetPostfix((char*)"1.13 + ( 2.2 - 3.8 ) * 4.12 + 5", postfix);
    std::cout << postfix << std::endl;
    
    result = cal.Calculate(postfix);
    std::cout << result << std::endl;
    
    std::cout << "---------- phase 3 ----------" << std::endl;
    memset(postfix,0,100);
    
    cal.GetPostfix((char*)"(1*3/2-1) + ((2-1)+4*1)", postfix);
    std::cout << postfix << std::endl;
    
    result = cal.Calculate(postfix);
    std::cout << result << std::endl;
    
    std::cout << "---------- phase 4 ----------" << std::endl;
    memset(postfix,0,100);
    
    cal.GetPostfix((char*)"(-1-2*(1-2+(4/2)))", postfix);
    std::cout << postfix << std::endl;
    
    result = cal.Calculate(postfix);
    std::cout << result << std::endl;
    
    std::cout << "---------- phase 5 ----------" << std::endl;
    memset(postfix,0,100);
    
    cal.GetPostfix((char*)"(-2)*3-2*1-(-3/2)", postfix);
    std::cout << postfix << std::endl;
    
    result = cal.Calculate(postfix);
    std::cout << result << std::endl;
    
    std::cout << "---------- phase 6 ----------" << std::endl;
    memset(postfix,0,100);
    
    cal.GetPostfix((char*)"(-20+10)*(-4)+4-(10/(-5))", postfix);
    std::cout << postfix << std::endl;
    
    result = cal.Calculate(postfix);
    std::cout << result << std::endl;
}
