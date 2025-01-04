#include<stdio.h>
#include<stdlib.h>

int main(void){
    int test_cases;

    scanf("%d", &test_cases);

    while(test_cases--){
        int m;

        scanf("%d",&m);

        int coins[m];
        int total=0;

        for(int i=0; i<m; i++){
            scanf("%d", &coins[i]);
            total=+coins[i];
        }



        if(total%2==0)printf("0\n");
        else printf("1\n");

        if(test_cases<=0)break;
    }
}
