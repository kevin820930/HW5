#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>

void initialmerge(int src1[],int src2[],int dst[],int n);
void improvemerge(int src1[],int src2[],int dst[],int n);
int main()
{
    int a[1000];
    int b[1000];
    int ans1[2000]= {0};
    int n=1000;
    int count;
    a[0]=0;b[0]=1;
    for(count=1;count<1000;count++){
	a[count]=a[count-1]+2;
	b[count]=b[count-1]+2;
	}
    unsigned long start1 = clock();
    initialmerge(a,b,ans1,n);
    unsigned long end1 = clock();
    printf("initialmerge time=%1.3f seconds\n",(end1-start1)/100.0);
    /*printf("ans of initial:");
    for(n=0; n<2000; n++) {
        printf("%d ",ans1[n]);
    }
    printf("\n");*/
    n=1000;
    unsigned long start2 = clock();
    improvemerge(a,b,ans1,n);
    unsigned long end2 = clock();
    printf("improvemerge time=%1.3f seconds\n",(end2-start2)/100.0);
    /*printf("ans of initial:");
    for(n=0; n<2000; n++) {
        printf("%d ",ans1[n]);
    }*/
    printf("\n");

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

void improvemerge(int src1[], int src2[], int dst[], int n)
{
    int i1 = 0, i2 = 0, id = 0;
    while (i1 < n && i2 < n) {
        int v1 = src1[i1];
        int v2 = src2[i2];
        int take1 = v1 < v2;
        dst[id++] = take1 ? v1 : v2;
        i1 += take1;
        i2 += (1 - take1);
    }
    while (i1 < n)
        dst[id++] = src1[i1++];
    while (i2 < n)
        dst[id++] = src2[i2++];
}

