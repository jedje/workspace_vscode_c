#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef int element; // 스택 원소(element)의 자료형을 int로 정의

element stack[STACK_SIZE]; // 1차원 stack 배열 선언
int top = -1; // top 초기화

// 스택이 공백인지 확인
int isEmpty() {
if (top == -1) return 1; // 공백임
else return 0; // 공백아님
}

// 스택이 포화 상태인지 확인하는 연산
int isFull() {
    if (top == STACK_SIZE) return 1;
    else return 0;
}

// 스택의 top에 원소를 삽입하는 연산
void push(element item) {
    if (isFull()) {
        printf("\n\n Stack is FULL\n") ;
        return ;
    }
    else stack[++top] = item; // top을 증가시킨 후 현재 top에 원소 삽입
}

// 스택의 top 원소를 삭제하는 연산
void pop(){
    if(isEmpty()){
        printf("\n\n Stack is Empty\n");
        return;
    }
    else {
        stack[top--] = 0; 
    }
}

// 스택의 top 원소를 검색하는 연산
int findTop(){
    if(isEmpty()) {
        printf("\n\n Stack is Empty\n");
        return -1;
    }
    else {
        return stack[top];
    }
}
// 스택의 원소를 출력하는 연산
int printStack(){
    if(isEmpty()){
        printf("\n\n Stack is Empty\n");
        return -1;
    }
    else {
        printf("\n\nStack : [");
        for(int i = 0; i <= top; i++) {
            printf("%d", stack[i]);
            if(i < top){
                printf(", ");
            }
        }
        printf("]\n");
    }
}

void main() {
    element item;
    printf("\nSTACK START\n");
    printStack();
    push(30);
    push(12);
    push(93);
    push(89);
    printStack();
    pop();
    push(99);
    printStack();
}