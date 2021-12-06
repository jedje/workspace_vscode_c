#include <stdio.h>

typedef struct {
    int row;
    int col;
    int value;
} term;

// 
void smTranspose(term a[], term b[]) {
    int i, j, p;

    b[0].col = a[0].row;                 // ��ġ��� b�� �� �� = ������ a�� �� ��
    b[0].row = a[0].col;                 // ��ġ��� b�� �� �� = ������ a�� �� ��
    b[0].value = a[0].value;             // ��ġ��� b�� ���� �� = ������ a���� 0�� �ƴ� ���Ҽ�

    //0�� �ƴ� ���Ұ� �ִ� ��쿡�� ��ġ ���� ����
    if (a[0].value > 0) {                  
        // (0.0)�� ���� ���� ������ ����Ǿ���
        p = 1;
        
        //������ a�� ������ ��ġ �ݺ� ����
        for(i = 0; i < a[0].col; i++ ) {
            //0�� �ƴ� ���� ���� ���ؼ��� �ݺ� ����
            for(j = 1; j < a[0].value ; j++) {
                //������ ���� ���ϴ� ���Ұ� ������ b[]�� ����
                if(a[j].col == i){
                    b[p].col = a[j].row;
                    b[p].row = a[j].col;
                    b[p].value = a[j].value;
                    p++;

                }

            }
        }
        
    }
}


int main(void){
    int i, j;
    term A[11] = { {8,7,10}, {0,2,2}, {0,6,12}, {1,4,7}, {2,0,23}, {3,3,31}, {4,1,14}, {4,5,25}, {5,6,6}, {6,0,52}, {7,4,11} };
    term B[11];

    smTranspose(A, B);

    printf("Transpose processing has been finished.\n");
    printf("\n\n");

    printf("���� ��: %d, ���� ��: %d, 0�� �ƴ� ���� ��: %d\n", B[0].row, B[0].col, B[0].value);

    for (i = 0; i < 10; i++)
        printf("��: %d, ��: %d, ��: %d\n", B[i].row, B[i].col, B[i].value);
    printf("\n\n");

 

   return 0;
}

 