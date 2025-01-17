#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_N 15

int n;
int graph[MAX_N][5];

int max_x(int a, int b){
    return a>b?a:b;
}

int solve(int row, int col, int bomb){
    if(row<=0 || col<0 || col>4)return 0;

    int ans=0;

    if(row>0){
        if(graph[row-1][col]!=2){
            ans+=
        }
    }
}


int main(void){
    for(t=1; i<=10; t++){
        scanf("%d", &n);

        int i,j;
        for(i=0; i<n; i++){
            for(j=0; j<5; j++){
                scanf("%d", &graph[i][j]);
            }
        }

        printf("#%d %d\n",t, solve(n, 2, 1));
    }
}
