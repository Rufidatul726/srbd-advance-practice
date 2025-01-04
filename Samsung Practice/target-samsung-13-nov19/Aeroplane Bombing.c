#include<stdio.h>
#include<stdlib.h>

int max_num(int a, int b){
    if(a>b)return a;
    return b;
}

void remove_bomb(int matrix[][5], int rows){
    if(rows<0)return;
    int i, j;

    int end_row= max_num(0, rows-4);

    for(i=rows; i>=end_row; i--){
        for(j=0; j<5; j++){
            if(matrix[i][j]==2){
                matrix[i][j]=0;
            }
        }
    }
}



int maximum_coin(int matrix[][5], int rows, int cols, int bomb){
    int answer=0;
    if(rows<=0 || cols<0 || cols>4){
        return 0;
    }

    if(rows>0){
        if(matrix[rows-1][cols]!=2){
            answer= max_num(answer, matrix[rows-1][cols]+ maximum_coin(matrix, rows-1, cols, bomb));
        }
        if(cols>0){
            if(matrix[rows-1][cols-1]!=2){
                answer= max_num(answer, matrix[rows-1][cols-1]+ maximum_coin(matrix, rows-1, cols-1, bomb));
            }
        }if(cols<4){
            if(matrix[rows-1][cols+1]!=2){
                answer= max_num(answer, matrix[rows-1][cols+1]+ maximum_coin(matrix, rows-1, cols+1, bomb));
            }
        }
    }

    if(answer==0 && bomb>0){
        remove_bomb(matrix, rows-1);
        answer= maximum_coin(matrix, rows, cols, bomb-1);
    }

    return answer;
}

int main(void){
    int test_case;
    int t=0;

    scanf("%d", &test_case);

    while(test_case>0){
        if(test_case<=0)break;
        int i, j, rows;
        scanf("%d", &rows);
        int matrix[rows][5];

        for(i=0; i<rows; i++){
            for(j=0; j<5; j++){
                scanf("%d", &matrix[i][j]);
            }
        }

        t++;
        printf("#%d %d\n", t, maximum_coin(matrix, rows, 2, 1));

        test_case--;
    }
}
