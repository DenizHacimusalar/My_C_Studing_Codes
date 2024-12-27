#include <stdio.h>
#include <stdlib.h>

int main()
{
    int area,square,i,j;
    printf("enter a square area number:");
    scanf("%d",&area);
    for(i=1;i<=area;i++){
        for(j=1;j<=area;j++){
            if(i==1 || i==area || j==1 || j==area){
                printf("* ");
            }else{
                printf("  ");
            }

        }
        printf("\n");
    }
    return 0;
}
