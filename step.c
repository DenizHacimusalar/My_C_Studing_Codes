#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mynumber,onlar,birler,yuzler,binler;
    float a,b,c,d,aritmatik;
    printf("enter a number:");
    scanf("%d", &mynumber);
    binler=(mynumber%10000)/1000;
    yuzler=(mynumber%1000)/100;
    onlar=(mynumber%100)/10;
    birler=mynumber%10;
    a=binler;
    b=yuzler;
    c=onlar;
    d=birler;
    aritmatik=(a+b+c+d)/4;
    printf("binler  basamagi %d\n",binler);
    printf("yuzler  basamagi %d\n",yuzler);
    printf("onlar  basamagi %d\n",onlar);
    printf("birler basamagi:%d\n",birler);
    printf("aritmatik ortalamasi %f\n",aritmatik);
    printf("\n\n");
    return 0;
}
