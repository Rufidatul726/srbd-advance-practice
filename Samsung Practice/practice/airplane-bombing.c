#include<stdio.h>

int n;
int matrix[20][5];

int max(int a, int b){
    if(a>b)return a;
    return b;
}

int removeBomb(int row){
    int temp=0;
    if(row-5>0)temp=row-5;

    for(int i=temp; i<row; i++){
        for(int j=0; j<5; j++){
            if(matrix[i][j]==2)
                matrix[i][j]=0;
        }
    }
}

int solve(int row, int col, int bomb){
    if(col<0 || row<=0 || col>4)return 0;

    int ans=0;
    if(row>0){
        if(matrix[row-1][col]!=2){
            ans = max(ans, matrix[row-1][col] + solve(row-1, col, bomb));
        }
        if(col>0){
            if(matrix[row-1][col-1]!=2){
                ans = max(ans, matrix[row-1][col-1] + solve(row-1, col-1, bomb));
            }
        }
        if(col<4){
            if(matrix[row-1][col+1]!=2){
                ans = max(ans, matrix[row-1][col+1] + solve(row-1, col+1, bomb));
            }
        }
    }

    if(ans==0 && bomb==1){
        bomb=0;
        removeBomb(row);
        ans= solve(row, col, bomb);
    }

    return ans;
}

int main(void){
    int t, tt=1;

    scanf("%d", &t);

    while(t>0){
        scanf("%d",&n);

        for(int i=0; i<n; i++){
            for(int j=0; j<5; j++){
                scanf("%d", &matrix[i][j]);
            }
        }

        printf("#%d %d\n",tt++, solve(n, 2, 1));
        t--;
    }
}
