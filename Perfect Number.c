#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,i,sum=0;
    printf("Enter a number for finding is this number a perfect number or not:");
    scanf("%d",&a);
    printf("divisors=");
    for(i=1;i<a;i++){
        if(a%i==0){
            printf("%d+",i);
            sum+=i;
        }else{
        }
    }
        printf("\b=%d\n",sum);
        if(sum==a)
            printf("This is a perfect number\n");
        else
        printf("This is not a perfect number\n");
    return 0;
}
