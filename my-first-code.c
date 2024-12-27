#include <stdio.h>
#include <stdlib.h>

int main()
{
    int kilowatthour,sub;
    float enflation,preenflation,sum,sum2,sum3,sum4,sum5;
    printf("using kilowatt hour cost:");
    scanf("%d",&kilowatthour);
    printf("enter sub cost:");
    scanf("%d",&sub);
    printf("what is your nation eflation:");
    scanf("%f",&preenflation);
    enflation=100/preenflation;//10--80-->
    sum=kilowatthour+sub;
    printf("first month cost:%f\n",sum);
    sum2=sum*enflation;
    printf("first second cost:%f\n",sum2);
    sum3=sum2*enflation;
    printf("first thirth cost:%f\n",sum3);
    sum4=sum3*enflation;
    printf("first fourth cost:%f\n",sum4);
    sum5=sum4*enflation;
    printf("first fifth cost:%f\n",sum5);
    printf("\n\n");
    return 0;
}
