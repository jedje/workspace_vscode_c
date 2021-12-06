#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//이중 연결 리스트의 노드 구조를 구조체로 정의
typedef struct listNode {
    struct listNode* llink;
    char data[4];
    struct listNode* rlink;
} listNode ;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct linkedList_h {
    listNode* head ;
} linkedList_h ;

// 공백 이중 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void) {
    linkedList_h* DL ;
    DL = (linkedList_h*)malloc(sizeof(linkedList_h));
    DL -> head = NULL;
}

// 이중 연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h(linkedList_h* DL) {
    listNode* p ;
    while(DL -> head) {
        p = DL -> head ; // 현재노드
        DL -> head = p -> llink ;
        DL -> head = p -> rlink ;
        free(p) ;
        p = NULL ;
    }
}

// 이중 연결 리스트 전체 출력
void printfList(linkedList_h* DL) {
    listNode* p;
    p = DL -> head ;
    printf(" L ("); 

    do {
        printf("%s", p -> data); 
        p = p -> rlink;
        // 다음 노드가 존재하는 경우
        if(p != DL -> head)
            printf(", "); 
    }while (p != DL -> head) ;

    printf(")\n"); 
}

// 이중연결리스트 첫번째 노드 추가
void insertFirstNode(linkedList_h *DL, char *newData) {
    listNode *newNode, *temp ;
    newNode = (listNode*)malloc(sizeof(listNode));
    temp = DL -> head; 
    strcpy(newNode -> data, newData);
    // 공백 이중연결리스트인 경우
    if ( DL -> head == NULL ) {
        // 헤드에 노드 넣기
        DL -> head = newNode;
        // 이중연결리스트인의 마지막 노드의 링크 필드는 본인의 주소 값을 가지게 됨
        newNode -> llink = newNode;
        newNode -> rlink = newNode;
    }
    // 공백 원형연결리스트가 아닌 경우
    else {
        // 마지막 노드 찾기
        while(temp -> rlink != DL -> head) {
            temp = temp -> rlink;
        }
        newNode -> rlink = temp -> rlink ;
        newNode -> llink = temp -> rlink -> llink ;
        temp -> rlink = newNode;
        temp -> llink = newNode;
        DL -> head = newNode ;
    }
}

// 이중연결리스트 중간 노드 추가
void insertMiddleNode(linkedList_h *DL, listNode *temp, char *newData) {
    listNode *newNode ;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode -> data, newData);
    // 공백 이중연결리스트인 경우
    if ( DL -> head == NULL ) {
        // 헤드에 노드 넣기
        DL -> head = newNode;
        // 이중연결리스트인의 마지막 노드의 링크 필드는 본인의 주소 값을 가지게 됨
        newNode -> llink = newNode;
        newNode -> rlink = newNode;
    }
    // 공백 원형연결리스트가 아닌 경우
    else {
        if( temp == NULL ){
            temp = DL -> head ;
            // 마지막 노드 찾기
            while(temp -> rlink != DL -> head) {
                temp = temp -> rlink;
            }
        }
        newNode -> rlink = temp -> rlink ;
        newNode -> llink = temp -> rlink -> llink ;
        temp -> rlink = newNode;
        temp -> llink = newNode;

    }
}

// 노드 검색
listNode* searchNode(linkedList_h* DL, char* findValue) {
    listNode* p ;
    p = DL -> head ;

    while( p != NULL) {
        if(strcmp(p -> data, findValue) == 0) {
            return p;
        }
        p = p -> rlink ; 
    }
    return NULL;
}

void main() {
    
    linkedList_h* L;
    L = createLinkedList_h();

    insertFirstNode(L, "화");
    insertFirstNode(L, "월");
    insertFirstNode(L, "일");
    
    listNode *node ;
    node = searchNode(L, "화");

    insertMiddleNode(L, node, "수");
    insertMiddleNode(L, NULL, "목");
    printfList(L);

}