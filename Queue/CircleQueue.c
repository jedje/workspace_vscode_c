#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 4

// 큐원소의 자료형 char
typedef char element; 

typedef struct {
    element queue[QUEUE_SIZE]; // 1차원 배열 큐
    int front, rear;
} Queue;

// 비어있는 큐 만들기
Queue* createQueue() {
    Queue *CQ;
    CQ =(Queue*)malloc(sizeof(Queue)); 
    CQ -> front = 0;
    CQ -> rear = 0;
    return CQ;
}

// 원형 큐가 공백 상태인지 검사
int isEmpty(Queue *CQ) {
    if(CQ -> front == CQ -> rear) {
        printf("\n\n Queue Empty ! ! ! \n");
        return 1 ;
    }
    else return 0; 
}

// 원형 큐가 포화 상태인지 검사
int isFull(Queue *CQ) {
    if(((CQ -> rear + 1) % QUEUE_SIZE) == CQ -> front ) {
        printf("\n\n Queue Full ! ! ! \n");
        return 1;
    }
    else return 0;
}

// 원형 큐 rear 삽입
void enQueue(Queue *CQ, element item) {
    if(isFull(CQ)) return;
    else {
        CQ -> rear = (CQ -> rear + 1) % QUEUE_SIZE; // rear 위치 증가
        CQ -> queue[CQ->rear] = item; //증가시킨 rear 위치에 삽입
    }
}

// 원형 큐 출력
void printQueue(Queue *CQ) {
    int i, first, last;
    first = (CQ -> front + 1) % QUEUE_SIZE;
    last = (CQ -> rear + 1) % QUEUE_SIZE;
    i = first;
    printf("Circle Queue : [");
    while(i != last) {
        printf("%c", CQ->queue[i]);
        i = (i + 1) % QUEUE_SIZE;
        if( i != last ) {
            printf(", ");
        }
    }
    printf("]");

}

void main() {
    Queue *CQ = createQueue();
    enQueue(CQ, 'A');
    enQueue(CQ, 'C');
    printQueue(CQ);

}