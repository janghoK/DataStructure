//
//  Calculator.cpp
//  StackCalculator
//
//  Created by Jangho Kim on 28/01/2019.
//  Copyright © 2019 김장호. All rights reserved.
//

#include "Calculator.hpp"
#include "LinkedListStack.hpp"

double Calculator::Calculate(char *postfixExpression) {
    LinkedListStack stack;
    
    char *value = (char*)malloc(strlen(postfixExpression)+1);
    unsigned int position = 0;
    unsigned int length = (unsigned int)strlen(postfixExpression)+1;
    int type = -1;
    
    double result = 0;
    char strResult[32];
    
    while(length > position) {
        position += GetNextValue(&postfixExpression[position], value, &type);
        if(type == SPACE || type == -1 || type == '\0') continue;
        if(type == OPERAND || type == NEGATIVE) {
            stack.Push(stack.CreateNode(value));
        } else {
            Node *op2 = stack.Pop();
            Node *op1 = stack.Pop();
            
            double tempResult = 0;
            memset(strResult, 0, 32);
            
            switch(type) {
                case MULTIPLY:
                    tempResult = atof(op1->Data) * atof(op2->Data);
                    break;
                case DIVIDE:
                    tempResult = atof(op1->Data) / atof(op2->Data);
                    break;
                case PLUS:
                    tempResult = atof(op1->Data) + atof(op2->Data);
                    break;
                case MINUS:
                    tempResult = atof(op1->Data) - atof(op2->Data);
                    break;
            }
            
            gcvt(tempResult, 10, strResult);
            stack.Push(stack.CreateNode(strResult));
            
            stack.DestroyNode(op1);
            stack.DestroyNode(op2);
        }
        
        memset(value, ' ', strlen(postfixExpression) + 1);
        type = -1;
    }
    
    result = atof(stack.Pop()->Data);
    
    free(value);
    stack.DestroyStack();
    
    return result;
}

void Calculator::GetPostfix(char *infixExpression, char *postfixExpression) {
    LinkedListStack stack;
    Node *popNode = NULL;
    
    char *value = (char*)malloc(strlen(infixExpression)+1);
    unsigned int length = (unsigned int)strlen(infixExpression)+1;
    unsigned int position = 0;
    int type = -1;
    int flag = 1;
    
    while(length > position) {
        position += GetNextValue(&infixExpression[position], value, &type);
        if(type == SPACE || type == -1 || type == '\0') continue;
        if(type == OPERAND) {
            strcat(postfixExpression, value);
            strcat(postfixExpression, " ");
            
            flag = 0;
        } else if(type == NEGATIVE) {
            /***
             * 이전 입력이 연산자일 경우
             * ex) 1 + -2 일 경우 '-' 앞에 '+' 이므로 '1 + (-2)' 로 변환 (음수는 괄호로 묶는것을 권장)
             * ex) (-1 + 2) 일 경우 '-' 앞에 '(' 이므로 '(-1 + 2)' 로 변환
             * ex) -1 -1 일 경우 '-' 앞에 값이 없으므로 '(-1) + (-1)' 로 변환
             *
             * 스택이 비어있지 않거나 이전 입력이 피연산자 or ')'인 경우 '+' 연산자를 추가로 삽입
             * ex) 1 + 2 - 3 * 2 의 경우 '-' 앞에 '2' 이므로 '1 + 2 + (-3) * 2' 로 변환
             * ex) (1 + 2) - 3 의 경우 '-' 앞에 ')' 이므로 '(1 + 2) + (-3)' 로 변환
             ***/
            if(!flag) {
                while(!stack.isEmpty() && isPrior(stack.GetTop()->Data[0], '+')) {
                    popNode = stack.Pop();
                    strcat(postfixExpression, popNode->Data);
                    strcat(postfixExpression, " ");
                    stack.DestroyNode(popNode);
                }
                stack.Push(stack.CreateNode((char*)"+"));
                popNode = NULL;
            }
            
            strcat(postfixExpression, value);
            strcat(postfixExpression, " ");
            
            flag = 0;
        } else if(type == RIGHT_PARENTHESES) {
            while(stack.GetTop()->Data[0] != LEFT_PARENTHESES) {
                popNode = stack.Pop();
                strcat(postfixExpression, popNode->Data);
                strcat(postfixExpression, " ");
                stack.DestroyNode(popNode);
            }
            // '(' 삭제
            popNode = stack.Pop();
            stack.DestroyNode(popNode);
            
            popNode = NULL;
        } else{
            while(!stack.isEmpty() && isPrior(stack.GetTop()->Data[0], value[0])) {
                popNode = stack.Pop();
                strcat(postfixExpression, popNode->Data);
                strcat(postfixExpression, " ");
                stack.DestroyNode(popNode);
            }
            stack.Push(stack.CreateNode(value));
            popNode = NULL;
            
            flag = 1;
        }
        
        memset(value, 0, strlen(infixExpression)+1);
        type = -1;
    }
    
    while(!stack.isEmpty()) {
        popNode = stack.Pop();
        strcat(postfixExpression, popNode->Data);
        strcat(postfixExpression, " ");
        stack.DestroyNode(popNode);
    }
    
    stack.DestroyStack();
    free(value);
}

unsigned int Calculator::GetNextValue(char *expression, char *value, int *type) {
    unsigned int index = 0;
    int temp = 0;
    for(index=0;expression[index] != 0;index++) {
        if(isNum(expression[index])) {
            *type = OPERAND;
            value[index] = expression[index];
            if(!isNum(expression[index+1])) break;
        } else {
            *type = expression[index];
            value[index] = expression[index];
            if(*type == MINUS) {
                
                /***
                 * '-' 다음 숫자가 아닌 연산자가 올 경우
                 * ex) 1 - (3 + 2) 의 경우 '-' 다음 '(' 이므로 음수가 아님
                 * '-' 다음 숫자가 올 경우
                 * ex) 1 - 123 의 경우 '-' 다음 '123' 이므로 1 + (-123) 처럼 음수
                 ***/
                for(int i=index+1;expression[i] != 0; i++) {
                    if(expression[i] == SPACE) continue;
                    if(isNum(expression[i])) {
                        *type = NEGATIVE;
                        
                    }
                    break;
                }
                
                if(*type == NEGATIVE) {
                    temp = index;
                    for(index+=1;expression[index] != 0;index++) {
                        if(expression[index] == SPACE) continue;
                        value[++temp] = expression[index];
                        
                        if(!isNum(expression[index+1])) break;
                    }
                }
            }
            
            break;
        }
    }
    
    value[++index] = '\0';
    return index;
}

unsigned int Calculator::GetPriority(char op, int inStack) {
    unsigned int priority = -1;
    switch(op) {
        case LEFT_PARENTHESES:
            if(inStack) priority = 3;
            else priority = 0;
            break;
        case MULTIPLY:
        case DIVIDE:
            priority = 1;
            break;
        case PLUS:
        case MINUS:
            priority = 2;
            break;
    }
    
    return priority;
}

bool Calculator::isPrior(char op1, char op2) {
    return (GetPriority(op1, 1) < GetPriority(op2, 0));
}

bool Calculator::isNum(char c) {
    for(int i=0;i<11;i++) {
        if(NUM[i] == c) return true;
    }
    return false;
}
