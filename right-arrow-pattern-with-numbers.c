#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=0,row,i,j;
    char letter;
    while(1){
        printf("Enter a big letter:");
        scanf("%c",&letter);
        if(letter>='A' && letter<='Z'){
            break;
        }else{
            printf("I said BIG LETTER(A-Z)\n");
        }
    }
    while(1){
        printf("enter a number of number(odd number):");
        scanf("%d",&row);
        if(row%2!=0){
            break;
        }else{
            printf("I said ODD NUMBER\n");
    }
    }
        for(i=0;i<row;i++){
            if(i<=row/2)
            a++;
            else
            a--;
            for(j=1;j<a;j++)
            printf(" ");
        printf("%c\n",letter);
    }
    return 0;
}

/*
A
 A
  A
 A
A
*/
