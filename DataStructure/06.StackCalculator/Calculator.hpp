//
//  Calculator.hpp
//  StackCalculator
//
//  Created by Jangho Kim on 28/01/2019.
//  Copyright © 2019 김장호. All rights reserved.
//

#ifndef Calculator_hpp
#define Calculator_hpp

#include <stdio.h>

class Calculator {
private:
    char NUM[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};
    enum symbol {
        LEFT_PARENTHESES = '(',
        RIGHT_PARENTHESES = ')',
        MULTIPLY = '*',
        DIVIDE = '/',
        PLUS = '+',
        MINUS = '-',
        SPACE = ' ',
        OPERAND,
        NEGATIVE
    };
    
public:
    double Calculate(char *postfixExpression);
    void GetPostfix(char *infixExpression, char *postfixExpression);
    unsigned int GetNextValue(char *expression, char *value, int *type);
    unsigned int GetPriority(char op, int inStack);
    bool isPrior(char op1, char op2);
    bool isNum(char c);
};
#endif /* Calculator_hpp */
