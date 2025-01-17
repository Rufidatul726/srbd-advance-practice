#include<stdio.h>
#include<string.h>

#define MAX_N 10

int n;
int b[MAX_N + 2];
int score[MAX_N+2][MAX_N+2];

int solve(int start, int end){
    if(start>end)return 0;
    if(score[start][end]!=-1)return score[start][end];

    int temp=-1;

    for(int i=start; i<=end; i++){
        int newscore= b[start-1] * b[end+1];
        if(start-1==0 && end==n){
            newscore=b[i];
        }
        newscore+= solve(start, i-1) + solve(i+1, end);
        if(temp<newscore || temp==-1)temp=newscore;
    }

    score[start][end]=temp;
    return score[start][end];
}

int main(void){
    scanf("%d",&n);

    b[0]=1;
    b[n+1]=1;
    for(int i=1; i<=n; i++){
        scanf("%d", &b[i]);
    }

    memset(score, -1, sizeof(score));
    printf("%d", solve(1, n));
}
