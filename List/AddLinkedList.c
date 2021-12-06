#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �ܼ� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct listNode {
    char data[4]; // �������ʵ� int ���� 4byte 
    struct listNode* link; // ��ũ�ʵ� 
} listNode ;

// ����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct {
    listNode* head ;
} linkedList_h ;

// ���� ���� ����Ʈ�� �����ϴ� ����
linkedList_h* createLinkedList_h(void) {
    linkedList_h* L ;
    L = (linkedList_h*)malloc(sizeof(linkedList_h));
    L -> head = NULL;

    return L;
}

// ���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
void freeLinkedList_h (linkedList_h* L) {
    listNode* p;
    // head ��尡 �����ϸ�
    while(L-> head != NULL) {
        p = L -> head ; 
        L -> head = L -> head -> link ;
        free(p);
        p = NULL;
    }
}

// ���� ����Ʈ�� ������� ����ϴ� ����
void printList(linkedList_h* L) {
    listNode *p ;
    printf("L = (");
    p = L -> head;
    while(p != NULL) {
        printf("%s", p->data );
        p = p -> link;
        // ���� ��嵵 ������ ���
        if (p!= NULL) {
            printf(", ");
        }
    }
    printf(") \n");
}

// ù��° ���� �����ϴ� ����
void insertFirstNode(linkedList_h *L, char *x){
    listNode* newNode;  // �����ϰ��� �ϴ� ��� ����
    newNode = (listNode*)malloc(sizeof(listNode)); // �����ϰ��� �ϴ� ��� �޸� �Ҵ�
    strcpy(newNode -> data, x); //�Է¹��� �������ʵ带 ������ ��忡 copy 
    newNode -> link = L -> head; // ������ ����� ��ũ�ʵ带 head�� ����Ű�� ���� �ּҰ����� ����
    L -> head = newNode; // head��带 ������ ���� ����
}

// ��带 pre �ڿ� �����ϴ� ����
void insertMiddleNode(linkedList_h *L, listNode *pre, char *x){
    listNode* newNode;  // �����ϰ��� �ϴ� ��� ����
    newNode = (listNode*)malloc(sizeof(listNode)); // �����ϰ��� �ϴ� ��� �޸� �Ҵ�
    strcpy(newNode -> data, x); //�Է¹��� �������ʵ带 ������ ��忡 copy 
    
    //���鸮��Ʈ�� ��� 
    if(L -> head == NULL) {
        // ����带 ù��°���� ������ ���� ����
        newNode -> link = NULL;
        L -> head = newNode;
    }
    // ���� ��ġ�� �����ϴ� pre�� NULL�� ���
    else if( pre == NULL) {
        // �� ��带 ù��° ���� ����
        newNode -> link = L -> head;
        L -> head = newNode;
    }
    // �� �� �߰� ����
    else{ 
        // ������ pre�� ��� �ڿ� �� ��� ����
        newNode -> link = pre -> link;
        pre -> link = newNode ; 
    }

}

// ������ ���� �����ϴ� ����
void insertLastNode(linkedList_h *L, char *x){
    listNode* newNode;  // �����ϰ��� �ϴ� ��� ����
    listNode* tempNode;  // ������ ��带 ã�� ���� �ӽ� ��� ����
    newNode = (listNode*)malloc(sizeof(listNode)); // �����ϰ��� �ϴ� ��� �޸� �Ҵ�
    strcpy(newNode -> data, x); //�Է¹��� �������ʵ带 ������ ��忡 copy 
    // ���� ����Ʈ�� ������ ���
    if(L -> head == NULL) {
        newNode -> link = NULL;
        L -> head = newNode;
    }
    // ���� ����Ʈ�� ������ �ƴ� ���
    else {
        //tempNode -> link = L -> head -> link;
        tempNode = L -> head;

        // ���� ����Ʈ�� ������ ��带 ã��
        while( tempNode -> link != NULL) {
            tempNode = tempNode -> link ;
        }

        // ����
        tempNode -> link = newNode ;
        newNode -> link = NULL;

        // ���� �� ����
        // newNode -> link = tempNode -> link;
        // ã�� ������ ����� ��ũ�ʵ� �ڸ��� ������ ��� ��ġ�� �ִ� �۾��� �ʿ��ߴµ�
        // �����ϰ� ã�� ���� ����� ��ũ�ڸ��� �����ع���.. 
    }
}

void deleteNode(linkedList_h *L, listNode* delNode) {
    listNode* p ;

    //���鸮��Ʈ�� ��� 
    if(L -> head == NULL) {
        return ;
    }
    else{ 
        p = L -> head;

        while (p->link != delNode) {
            p = p->link;
        }
        // �����ϰ��� �ϴ� ���� ���� ��� ã�� ������ ����� ��ũ�ʵ� �������ֱ�
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
	return NULL;	// Ž�� ����
}

int main() {

    char *data;

    printf("1. ����ִ� ���� ����Ʈ �����ϱ� \n");
    linkedList_h* L ;
    L = createLinkedList_h();
    printList(L);
    
    printf("2. ���ϸ���Ʈ ù��°�� [��] ��� �����ϱ� \n");
    insertFirstNode(L,"��");
    printList(L);
    
    printf("3. ���ϸ���Ʈ Ư�� ��� ã��\n ���� �Է� : ");
    scanf("%s", data);
    listNode* node = searchList(L, data);
    printf("found it ! address : %p data : %s \n", &node, node -> data );

    printf("4. ���ϸ���Ʈ          [��] ��� �����ϱ� \n");
    insertMiddleNode(L, node, "��");
    printList(L);

    printf("4. ���ϸ���Ʈ          [ȭ] ��� �����ϱ� \n");
    insertMiddleNode(L, node, "ȭ");
    printList(L);
    
    printf("5. ���ϸ���Ʈ �������� [��] ��� �����ϱ� \n");
    insertLastNode(L,"��");
    printList(L);

    printf("6. ���ϸ���Ʈ Ư�� ��� �����ϱ�\n ���� �Է� : ");
    scanf("%s", data);
    listNode* delNode = searchList(L, data);
    printf("delete node found it !  ddress : %p data : %s \n", &delNode, delNode -> data );
    deleteNode(L, delNode);
    printList(L);

    printf("7. ���ϸ���Ʈ ��ü �����Ͽ� ���鸮��Ʈ�� ����� \n");
    freeLinkedList_h(L);
    printList(L);

}
