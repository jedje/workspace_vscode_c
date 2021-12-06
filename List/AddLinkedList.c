#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 단순 연결 리스트의 노드 구조를 구조체로 정의
typedef struct listNode {
    char data[4]; // 데이터필드 int 형은 4byte 
    struct listNode* link; // 링크필드 
} listNode ;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct {
    listNode* head ;
} linkedList_h ;

// 공백 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void) {
    linkedList_h* L ;
    L = (linkedList_h*)malloc(sizeof(linkedList_h));
    L -> head = NULL;

    return L;
}

// 연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h (linkedList_h* L) {
    listNode* p;
    // head 노드가 존재하면
    while(L-> head != NULL) {
        p = L -> head ; 
        L -> head = L -> head -> link ;
        free(p);
        p = NULL;
    }
}

// 연결 리스트를 순서대로 출력하는 연산
void printList(linkedList_h* L) {
    listNode *p ;
    printf("L = (");
    p = L -> head;
    while(p != NULL) {
        printf("%s", p->data );
        p = p -> link;
        // 다음 노드도 존재할 경우
        if (p!= NULL) {
            printf(", ");
        }
    }
    printf(") \n");
}

// 첫번째 노드로 삽입하는 연산
void insertFirstNode(linkedList_h *L, char *x){
    listNode* newNode;  // 삽입하고자 하는 노드 생성
    newNode = (listNode*)malloc(sizeof(listNode)); // 삽입하고자 하는 노드 메모리 할당
    strcpy(newNode -> data, x); //입력받은 데이터필드를 생성한 노드에 copy 
    newNode -> link = L -> head; // 생성한 노드의 링크필드를 head가 가르키는 다음 주소값으로 세팅
    L -> head = newNode; // head노드를 생성한 노드로 세팅
}

// 노드를 pre 뒤에 삽입하는 연산
void insertMiddleNode(linkedList_h *L, listNode *pre, char *x){
    listNode* newNode;  // 삽입하고자 하는 노드 생성
    newNode = (listNode*)malloc(sizeof(listNode)); // 삽입하고자 하는 노드 메모리 할당
    strcpy(newNode -> data, x); //입력받은 데이터필드를 생성한 노드에 copy 
    
    //공백리스트인 경우 
    if(L -> head == NULL) {
        // 새노드를 첫번째이자 마지막 노드로 연결
        newNode -> link = NULL;
        L -> head = newNode;
    }
    // 삽입 위치를 지정하는 pre가 NULL인 경우
    else if( pre == NULL) {
        // 새 노드를 첫번째 노드로 삽입
        newNode -> link = L -> head;
        L -> head = newNode;
    }
    // 그 외 중간 삽입
    else{ 
        // 포인터 pre의 노드 뒤에 새 노드 연결
        newNode -> link = pre -> link;
        pre -> link = newNode ; 
    }

}

// 마지막 노드로 삽입하는 연산
void insertLastNode(linkedList_h *L, char *x){
    listNode* newNode;  // 삽입하고자 하는 노드 생성
    listNode* tempNode;  // 마지막 노드를 찾기 위한 임시 노드 생성
    newNode = (listNode*)malloc(sizeof(listNode)); // 삽입하고자 하는 노드 메모리 할당
    strcpy(newNode -> data, x); //입력받은 데이터필드를 생성한 노드에 copy 
    // 현재 리스트가 공백인 경우
    if(L -> head == NULL) {
        newNode -> link = NULL;
        L -> head = newNode;
    }
    // 현재 리스트가 공백이 아닌 경우
    else {
        //tempNode -> link = L -> head -> link;
        tempNode = L -> head;

        // 현재 리스트의 마지막 노드를 찾음
        while( tempNode -> link != NULL) {
            tempNode = tempNode -> link ;
        }

        // 정답
        tempNode -> link = newNode ;
        newNode -> link = NULL;

        // 내가 쓴 오답
        // newNode -> link = tempNode -> link;
        // 찾은 마지막 노드의 링크필드 자리에 생성한 노드 위치를 넣는 작업이 필요했는데
        // 무식하게 찾은 널을 뉴노드 링크자리에 연결해버림.. 
    }
}

void deleteNode(linkedList_h *L, listNode* delNode) {
    listNode* p ;

    //공백리스트인 경우 
    if(L -> head == NULL) {
        return ;
    }
    else{ 
        p = L -> head;

        while (p->link != delNode) {
            p = p->link;
        }
        // 삭제하고자 하는 값의 이전 노드 찾아 삭제될 노드의 링크필드 연결해주기
        p -> link = delNode -> link;
        free(delNode);
    }

}

listNode* searchList(linkedList_h* L, char* x)
{
	listNode* p = L -> head;

	while (p != NULL) {
		if (strcmp(p->data, x) == 0) return p;
		p = p->link;
	}
	return NULL;	// 탐색 실패
}

int main() {

    char *data;

    printf("1. 비어있는 요일 리스트 생성하기 \n");
    linkedList_h* L ;
    L = createLinkedList_h();
    printList(L);
    
    printf("2. 요일리스트 첫번째에 [월] 노드 생성하기 \n");
    insertFirstNode(L,"월");
    printList(L);
    
    printf("3. 요일리스트 특정 노드 찾기\n 요일 입력 : ");
    scanf("%s", data);
    listNode* node = searchList(L, data);
    printf("found it ! address : %p data : %s \n", &node, node -> data );

    printf("4. 요일리스트          [수] 노드 생성하기 \n");
    insertMiddleNode(L, node, "수");
    printList(L);

    printf("4. 요일리스트          [화] 노드 생성하기 \n");
    insertMiddleNode(L, node, "화");
    printList(L);
    
    printf("5. 요일리스트 마지막에 [금] 노드 생성하기 \n");
    insertLastNode(L,"금");
    printList(L);

    printf("6. 요일리스트 특정 노드 삭제하기\n 요일 입력 : ");
    scanf("%s", data);
    listNode* delNode = searchList(L, data);
    printf("delete node found it !  ddress : %p data : %s \n", &delNode, delNode -> data );
    deleteNode(L, delNode);
    printList(L);

    printf("7. 요일리스트 전체 삭제하여 공백리스트로 만들기 \n");
    freeLinkedList_h(L);
    printList(L);

}
