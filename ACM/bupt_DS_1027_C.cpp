//
//  bupt_DS_1027_C.cpp
//  ACM
//
//  Created by 王子豪 on 2017/11/1.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>

using namespace std;

typedef struct Stack{
    char *data;
    int top;
    int capacity;
}Stack;

char top(Stack * A){
    return (A->data[A->top - 1]);
}

Stack * create_stack(){
    Stack * new_stack;
    new_stack = (Stack*)malloc(sizeof(Stack));
    new_stack->capacity = 500;
    new_stack->top = 0;
    new_stack->data = (char*)malloc(sizeof(char) * new_stack->capacity);
    
    return new_stack;
}

bool isFull(Stack * A){
    return (A->top == A->capacity);
}
bool isEmpty(Stack * A){
    return (A->top == 0);
}

bool push(Stack * A, char target){
    if( isFull(A) ){
        char *temp;
        temp = (char *)realloc(A->data,sizeof(char) * A->capacity * 2);
        if( temp == NULL) return false;
        A->data = temp;
        A->capacity *= 2;
    }
    A->data[A->top++] = target;
    return true;
}

bool pop(Stack * A){
    if( isEmpty(A) == true) return false;
    A->top--;
    return true;
}

bool check(Stack * A,char target){
    if( A->data[A->top-1] == '{' && target == '}') return true;
    else if( A->data[A->top-1] == '[' && target == ']') return true;
    else if( A->data[A->top-1] == '(' && target == ')') return true;
    return false;
}

int main(void){
    char x;
    char temp;
    Stack *myStack;
    myStack = create_stack();
    bool marka = false;
    bool markb = false;
    bool markc = false;
    x = getchar();
    while(x != '\n'){
        if(x == '{' || x == '[' || x == '(') push(myStack, x);
        else if(x == '}' || x == ']' || x == ')'){
            if(check(myStack, x)) pop(myStack);
            else{
                //                if(isEmpty(myStack)) break;
                //                temp = top(myStack);
                if(x == ')' ) marka = true;
                else if(x == ']') markb = true;
                else if(x == '}') markc = true;
                //                if(temp == '(' ) marka = true;
                //                else if(temp == '[') markb = true;
                //                else if(temp == '{') markc = true;
                //                pop(myStack);
                //                continue;
            }
        }
        x = getchar();
    }
    while(!isEmpty(myStack)){
        if(top(myStack) == '(')   marka = true;
        else if(top(myStack) == '[')  markb = true;
        else if(top(myStack) == '{')  markc = true;
        pop(myStack);
    }
    if(marka == false && markb == false && markc == false) printf("0\n");
    else{
        if(marka == true){
            printf("1,");
            //            if(markb == true || markc == true) printf(",");
        }
        if(markb == true){
            printf("2,");
            //            if(markc == true) printf(",");
        }
        if(markc == true){
            printf("3,");
        }
        printf("\n");
    }
    return 0;
}
