#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct listNode {
    struct listNode* llink;
    char data[4];
    struct listNode* rlink;
} listNode ;

// ����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct linkedList_h {
    listNode* head ;
} linkedList_h ;

// ���� ���� ���� ����Ʈ�� �����ϴ� ����
linkedList_h* createLinkedList_h(void) {
    linkedList_h* DL ;
    DL = (linkedList_h*)malloc(sizeof(linkedList_h));
    DL -> head = NULL;
}

// ���� ���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
void freeLinkedList_h(linkedList_h* DL) {
    listNode* p ;
    while(DL -> head) {
        p = DL -> head ; // ������
        DL -> head = p -> llink ;
        DL -> head = p -> rlink ;
        free(p) ;
        p = NULL ;
    }
}

// ���� ���� ����Ʈ ��ü ���
void printfList(linkedList_h* DL) {
    listNode* p;
    p = DL -> head ;
    printf(" L ("); 

    do {
        printf("%s", p -> data); 
        p = p -> rlink;
        // ���� ��尡 �����ϴ� ���
        if(p != DL -> head)
            printf(", "); 
    }while (p != DL -> head) ;

    printf(")\n"); 
}

// ���߿��Ḯ��Ʈ ù��° ��� �߰�
void insertFirstNode(linkedList_h *DL, char *newData) {
    listNode *newNode, *temp ;
    newNode = (listNode*)malloc(sizeof(listNode));
    temp = DL -> head; 
    strcpy(newNode -> data, newData);
    // ���� ���߿��Ḯ��Ʈ�� ���
    if ( DL -> head == NULL ) {
        // ��忡 ��� �ֱ�
        DL -> head = newNode;
        // ���߿��Ḯ��Ʈ���� ������ ����� ��ũ �ʵ�� ������ �ּ� ���� ������ ��
        newNode -> llink = newNode;
        newNode -> rlink = newNode;
    }
    // ���� �������Ḯ��Ʈ�� �ƴ� ���
    else {
        // ������ ��� ã��
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

// ���߿��Ḯ��Ʈ �߰� ��� �߰�
void insertMiddleNode(linkedList_h *DL, listNode *temp, char *newData) {
    listNode *newNode ;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode -> data, newData);
    // ���� ���߿��Ḯ��Ʈ�� ���
    if ( DL -> head == NULL ) {
        // ��忡 ��� �ֱ�
        DL -> head = newNode;
        // ���߿��Ḯ��Ʈ���� ������ ����� ��ũ �ʵ�� ������ �ּ� ���� ������ ��
        newNode -> llink = newNode;
        newNode -> rlink = newNode;
    }
    // ���� �������Ḯ��Ʈ�� �ƴ� ���
    else {
        if( temp == NULL ){
            temp = DL -> head ;
            // ������ ��� ã��
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

// ��� �˻�
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

    insertFirstNode(L, "ȭ");
    insertFirstNode(L, "��");
    insertFirstNode(L, "��");
    
    listNode *node ;
    node = searchNode(L, "ȭ");

    insertMiddleNode(L, node, "��");
    insertMiddleNode(L, NULL, "��");
    printfList(L);

}