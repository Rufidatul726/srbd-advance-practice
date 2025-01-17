#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>

#define MAX 10

int graph[10][10];
int visited[10][10];
int n,m;
int ans;

void dfs(int i, int j, int height){
    if(i<0 || i>=n || j<0 || j>=m) return;

    if(visited[i][j]!=0)return;

    visited[i][j]=1;
    if(graph[i][j]==3){
        ans=1;
        return;
    }

    if(j>0){
        if(graph[i][j-1]!=0){
            dfs(i,j-1,height);
        }
    }
    if(j<m-1){
        if(graph[i][j+1]!=0){
            dfs(i, j+1, height);
        }
    }

    for(int h=1; h<=height; h++){
        if(i-h>=0){
            if(graph[i-h][j]!=0){
                dfs(i-h,j,height);
            }
        }
        if(i+h<=n){
            if(graph[i+h][j]!=0){
                dfs(i+h, j, height);
            }
        }
    }
}

int main(void){
    scanf("%d %d",&n, &m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    for(int h=0; h<n; h++){
        ans=0;
        memset(visited, 0, sizeof(visited));
        dfs(n-1, 0, h);
        if(ans!=0){
            printf("%d\n", h);
            break;

        }
    }
}
