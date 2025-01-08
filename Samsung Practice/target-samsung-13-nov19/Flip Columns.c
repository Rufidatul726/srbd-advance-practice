#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX_N 15
#define MAX_M 15
#define MAX_NUMBER 65536

long long int binary_matrix[MAX_N][MAX_M];
long long int decimal_matrix[MAX_NUMBER];
long long int num_zeros[MAX_N];
long long int power[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};

int main(void){
    int m,n, k;

    scanf("%d %d %d", &n, &m, &k);

    int i, j;
    long long int temp=0;
    int ans=0;

    for(i=0; i<power[n];i++){
        decimal_matrix[i]=0;
    }

    for(i=0; i<n; i++){
        temp=0;
        for(j=0; j<m; j++){
            scanf("%lld",&binary_matrix[i][j]);
            if(binary_matrix[i][j]==1){
                temp+=power[j];
            }else{
                num_zeros[i]++;
            }
        }
        //printf("%d %d\t", temp, decimal_matrix[temp]);
        decimal_matrix[temp]++;
        if(num_zeros[i]>k)continue;
        if((k-num_zeros[i])%2==0){
            if(ans<decimal_matrix[temp])ans=decimal_matrix[temp];
        }
    }

    printf("%d", ans);
    return 0;
}
