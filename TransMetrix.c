#include <stdio.h>

typedef struct {
    int row;
    int col;
    int value;
} term;

// 
void smTranspose(term a[], term b[]) {
    int i, j, p;

    b[0].col = a[0].row;                 // 전치행렬 b의 행 수 = 희소행렬 a의 행 수
    b[0].row = a[0].col;                 // 전치행렬 b의 열 수 = 희소행렬 a의 열 수
    b[0].value = a[0].value;             // 전치행렬 b의 원소 수 = 희소행렬 a에서 0이 아닌 원소수

    //0이 아닌 원소가 있는 경우에만 전치 연산 수행
    if (a[0].value > 0) {                  
        // (0.0)에 대한 값은 위에서 저장되어짐
        p = 1;
        
        //희소행렬 a의 열별로 전치 반복 수행
        for(i = 0; i < a[0].col; i++ ) {
            //0이 아닌 원소 수에 대해서만 반복 수행
            for(j = 1; j < a[0].value ; j++) {
                //현재의 열에 속하는 원소가 있으면 b[]에 삽입
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

    printf("행의 수: %d, 열의 수: %d, 0이 아닌 항의 수: %d\n", B[0].row, B[0].col, B[0].value);

    for (i = 0; i < 10; i++)
        printf("행: %d, 열: %d, 값: %d\n", B[i].row, B[i].col, B[i].value);
    printf("\n\n");

 

   return 0;
}

 