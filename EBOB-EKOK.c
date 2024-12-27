#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,i,ebob,ekok;
    while(1){
        printf("Enter two positive numbers (1-999) for finding EBOB and EKOK:");
        scanf("%d %d",&x,&y);
        if(x>=1 && x<=999 && y>=1 && y<=999){
            break;
        }else{
            printf("I said TWO POSITIVE NUMBERS (1-999)\n");
        }
    }
    for(i=1;i<=x && i<=y;i++){
    if(x%i==0 && y%i==0){
       ebob=i;
     }
   }
     ekok=(x*y)/ebob;
    printf("EBOB: %d\n",ebob);
    printf("EKOK: %d\n",ekok);

    return 0;
}
