#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#include<limits.h>
void initialmerge(int src1[],int src2[],int dst[],int n);
void improvemerge(int src1[],int src2[],int dst[],int n);
void teachermerge(int src1[],int src2[],int dst[],int n);
int main()
{
    int a[10001];
    int b[10001];
    int ans1[20001]= {0};
    int ans2[20001]= {0};
    int ans3[20001]= {0};
    int n=10000;
    int count;
    a[0]=0;b[0]=1;
    for(count=1;count<10000;count++){
	a[count]=a[count-1]+2;
	b[count]=b[count-1]+2;
	}
    unsigned long start1 = clock();
    for(count=0;count<1000;count++)
    initialmerge(a,b,ans1,n);
    unsigned long end1 = clock();
    printf("initialmerge time(repeat 1000)=%1.3f ms\n",(double)(end1-start1)/CLOCKS_PER_SEC*1000);
    /*printf("ans of initial:");
    for(n=0; n<20000; n++) {
        printf("%d ",ans1[n]);
    }
    printf("\n");*/
    n=10000;
    unsigned long start2 = clock();
    for(count=0;count<1000;count++)
    improvemerge(a,b,ans2,n);
    unsigned long end2 = clock();
    printf("improvemerge time(repeat 1000)=%1.3lf ms\n",(double)(end2-start2)/CLOCKS_PER_SEC*1000);
    /*printf("ans of initial:");
    for(n=0; n<20000; n++) {
        printf("%d ",ans2[n]);
    }*/
    n=10000;
    unsigned long start3 = clock();
    for(count=0;count<1000;count++)
    teachermerge(a,b,ans3,n);
    unsigned long end3 = clock();
    printf("teachermerge time(repeat 1000)=%1.3lf ms\n",(double)(end3-start3)/CLOCKS_PER_SEC*1000);
    /*printf("ans of initial:");
    for(n=0; n<20000; n++) {
        printf("%d ",ans3[n]);
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
    src1[10000]=INT_MAX;
    src2[10000]=INT_MAX;
    n=2*n;
    int i1 = 0, i2 = 0, id = 0;
    while (i1+i2 < n )
    dst[id++] = (src1[i1] < src2[i2]) ? src1[i1++] : src2[i2++];
}

void teachermerge(int src1[], int src2[], int dst[], int n)
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
