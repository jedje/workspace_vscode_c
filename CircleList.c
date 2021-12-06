#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//원형 연결 리스트의 노드 구조를 구조체로 정의
typedef struct listNode {
    char data[4];
    struct listNode* link;
} listNode ;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct linkedList_h {
    listNode* head ;
} linkedList_h ;

// 공백 원형 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void) {
    linkedList_h* CL ;
    CL = (linkedList_h*)malloc(sizeof(linkedList_h));
    CL -> head = NULL;
}

// 연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h(linkedList_h* CL) {
    listNode* p ;
    while(CL -> head) {
        p = CL -> head ; // 현재노드
        CL -> head = p -> link ;
        free(p) ;
        p = NULL ;
    }
}

// 연결 리스트 전체 출력
void printfList(linkedList_h* CL) {
    listNode* p;
    p = CL -> head ;
    printf(" L ("); 
    // 공백이 아닌 경우
    do {
        printf("%s", p -> data); 
        p = p -> link;
        // 다음 노드가 존재하는 경우
        if(p != CL -> head)
            printf(", "); 
    }while (p != CL -> head) ;

    printf(")\n"); 
}

// 노드 검색
listNode* searchNode(linkedList_h* CL, char* findValue) {
    listNode* p ;
    p = CL -> head ;

    while( p != NULL) {
        if(strcmp(p -> data, findValue) == 0) {
            return p;
        }
        p = p -> link ; 
    }

    return NULL;

}

// 원형리스트 첫번째 노드 추가
void insertFirstNode(linkedList_h *CL, char *newData) {
    listNode *newNode, *temp ;
    newNode = (listNode*)malloc(sizeof(listNode));
    temp = CL -> head; 
    strcpy(newNode -> data, newData);
    // 공백 연결리스트인 경우
    if ( CL -> head == NULL ) {
        // 헤드에 노드 넣기
        CL -> head = newNode;
        // 원형리스트의 마지막 노드의 링크 필드는 본인의 주소 값을 가지게 됨
        newNode -> link = newNode;
    }
    // 공백 원형연결리스트가 아닌 경우
    else {
        // 마지막 노드 찾기
        while(temp -> link != CL -> head) {
            temp = temp -> link;
        }
        newNode -> link = temp -> link ;
        // 마지막 노드 링크필드를 new노드 주소로
        temp -> link = newNode;
        // 첫번째 노드 주소를 new노드 주소
        CL -> head = newNode ;
    }

}

// 원형리스트 중간 노드 추가
void insertMiddleNode(linkedList_h* CL, listNode *pre, char* newData) {
    listNode *newNode ;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode -> data, newData);
    if( CL == NULL ) {
        CL -> head = newNode;
        newNode -> link = newNode;
    } else {
        newNode -> link = pre -> link;
        pre -> link = newNode;
    }
}


// 원형리스트 노드 삭제
void deleteNode(linkedList_h* CL, listNode *old ) {
    listNode *p ;
    p = CL -> head ;
    if (CL == NULL ) return ;
    do {
        if ( p -> link== old ) {
            // old 를 주소를 링크필드로 가지고 있는 노드를 old 주소 다음 링크필드로 넣어주어야함
            p -> link = old -> link ;
            if ( old == CL -> head) {
                CL -> head = p ;
            }
        }
        p = p -> link ; 

    } while(p != CL -> head);

}


void main() {
    
    linkedList_h* L;
    L = createLinkedList_h();

    insertFirstNode(L, "화");
    insertFirstNode(L, "월");
    listNode* node = searchNode(L, "월");
    printf("found it ! address : %p data : %s \n", &node, node -> data );
    deleteNode(L, node);

    printfList(L);



}