#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#include<limits.h>
void initialmerge(int src1[],int src2[],int dst[],int n);
int main()
{
    int a[30001];
    int b[30001];
    int ans1[60001]= {0};
    int n=30000;
    int count;
    a[0]=0;
    b[0]=1;
    for(count=1; count<30000; count++) {
        a[count]=a[count-1]+2;
        b[count]=b[count-1]+2;
    }
        initialmerge(a,b,ans1,n);
}
void initialmerge(int src1[], int src2[], int dst[], int n)
{
    int i1 = 0, i2 = 0, id = 0;
    while (i1 < n && i2 < n) {
        if (src1[i1] < src2[i2])
            dst[id++] = src1[i1++];
        else
            dst[id++] = src2[i2++];
    }
    while (i1 < n)
        dst[id++] = src1[i1++];
    while (i2 < n)
        dst[id++] = src2[i2++];
}

