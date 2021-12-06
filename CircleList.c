#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct listNode {
    char data[4];
    struct listNode* link;
} listNode ;

// ����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct linkedList_h {
    listNode* head ;
} linkedList_h ;

// ���� ���� ���� ����Ʈ�� �����ϴ� ����
linkedList_h* createLinkedList_h(void) {
    linkedList_h* CL ;
    CL = (linkedList_h*)malloc(sizeof(linkedList_h));
    CL -> head = NULL;
}

// ���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
void freeLinkedList_h(linkedList_h* CL) {
    listNode* p ;
    while(CL -> head) {
        p = CL -> head ; // ������
        CL -> head = p -> link ;
        free(p) ;
        p = NULL ;
    }
}

// ���� ����Ʈ ��ü ���
void printfList(linkedList_h* CL) {
    listNode* p;
    p = CL -> head ;
    printf(" L ("); 
    // ������ �ƴ� ���
    do {
        printf("%s", p -> data); 
        p = p -> link;
        // ���� ��尡 �����ϴ� ���
        if(p != CL -> head)
            printf(", "); 
    }while (p != CL -> head) ;

    printf(")\n"); 
}

// ��� �˻�
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

// ��������Ʈ ù��° ��� �߰�
void insertFirstNode(linkedList_h *CL, char *newData) {
    listNode *newNode, *temp ;
    newNode = (listNode*)malloc(sizeof(listNode));
    temp = CL -> head; 
    strcpy(newNode -> data, newData);
    // ���� ���Ḯ��Ʈ�� ���
    if ( CL -> head == NULL ) {
        // ��忡 ��� �ֱ�
        CL -> head = newNode;
        // ��������Ʈ�� ������ ����� ��ũ �ʵ�� ������ �ּ� ���� ������ ��
        newNode -> link = newNode;
    }
    // ���� �������Ḯ��Ʈ�� �ƴ� ���
    else {
        // ������ ��� ã��
        while(temp -> link != CL -> head) {
            temp = temp -> link;
        }
        newNode -> link = temp -> link ;
        // ������ ��� ��ũ�ʵ带 new��� �ּҷ�
        temp -> link = newNode;
        // ù��° ��� �ּҸ� new��� �ּ�
        CL -> head = newNode ;
    }

}

// ��������Ʈ �߰� ��� �߰�
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


// ��������Ʈ ��� ����
void deleteNode(linkedList_h* CL, listNode *old ) {
    listNode *p ;
    p = CL -> head ;
    if (CL == NULL ) return ;
    do {
        if ( p -> link== old ) {
            // old �� �ּҸ� ��ũ�ʵ�� ������ �ִ� ��带 old �ּ� ���� ��ũ�ʵ�� �־��־����
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

    insertFirstNode(L, "ȭ");
    insertFirstNode(L, "��");
    listNode* node = searchNode(L, "��");
    printf("found it ! address : %p data : %s \n", &node, node -> data );
    deleteNode(L, node);

    printfList(L);



}