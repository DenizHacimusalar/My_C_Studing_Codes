#include <stdio.h>
#include <stdlib.h>

int main()
{
    double value,array[10];
    int choice,index;
    do{
        printf("Enter a number (tap to exit for -1):");
        printf("\n\t1) Write to array");
        printf("\n\t2) Read from array\n");
        printf("Entering ");
        scanf("%d",&choice);
        if(choice==-1)break;
        if(choice!=1 && choice!=2){
            printf("Wrong progress\n\n");
            continue;
        }
        printf("Enter arrey number (1-9):");
        scanf("%d",&index);
        if(index<=0 && index>=9){
            printf("You should enter number 0 to 9");
            continue;
        }
        switch(choice){
            case 1:printf("Enter the value:");
                   scanf("%lf",&value);
                   array[index]=value;
                   printf("Your write ooperation is succesfull \n\n");
                   break;
            case 2:printf("\nArray number %d is include \"%.2f\" \n\n",index,array[index]);
                   break;
        }
    }while(choice !=-1);
    return 0;
}
