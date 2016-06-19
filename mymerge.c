#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#include<limits.h>
int main()
{
    int a[10001];
    int b[10001];
    int ans2[20001]= {0};
    int n=10000;
    int count;
    a[0]=0;
    b[0]=1;
    for(count=1; count<10000; count++) {
        a[count]=a[count-1]+2;
        b[count]=b[count-1]+2;
    }
}

