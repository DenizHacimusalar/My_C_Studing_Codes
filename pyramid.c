#include <stdio.h>
#include <stdlib.h>

//triangle area

int main()
{
    int area,i,j;
    printf("enter a area number:");
    scanf("%d",&area);
    for(i=1;i<=area;i++){
        for(j=1;j<=area-i;j++){
            printf("  ");
        }
        for(j=1;j<=i*2-1;j++){
            printf("* ");
        }
    printf("\n");
    }
    for(i=1;i<=area;i++){
        for(j=1;j<=i;j++){
            printf("  ");
        }
        for(j=1;j<=area*2-1-(i*2);j++){
            printf("* ");
        }
    printf("\n");
    }
    return 0;
}
