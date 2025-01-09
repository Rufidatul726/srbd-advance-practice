#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_N 50
#define MAX_M 50

int n, m;
int pipe[MAX_N][MAX_M];
int visited[MAX_N][MAX_M];

int solve(int start_i, int start_j, int k){
    if(pipe[start_i][start_j]==0 || (start_i>=n && start_j>=m))return 0;

	return 0;
}

int main(void){
    int t;

    scanf("%d",&t);

    while(t>0){
        int k, c,r;
        scanf("%d %d %d %d %d", &n, &m, &r, &c, &k);

        int i, j;

        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                visited[i][j]=0;
                scanf("%d", &pipe[i][j]);
            }
        }
        int x= solve(r, c, k);
        t--;
    }
}
