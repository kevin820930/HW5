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
void mergesort(int initial[],int lengh);
int main()
{
    int n;
    int input[9]= {20,56,31,9,42,12,49,65,INT_MAX}; //last number is for judge not data
    int lengh=sizeof(input)/4;
    printf("ans of initial:");
    for(n=0; n<8; n++) {
        printf("%d ",input[n]);
    }
    printf("\n");
    mergesort(input,lengh);
    printf("ans of initial:");
    for(n=0; n<8; n++) {
        printf("%d ",input[n]);
    }
    printf("\n");
}

void mergesort(int initial[],int lengh)
{
    lengh=lengh-1;
    int halflengh=lengh/2;
    int left[halflengh+1],right[lengh-halflengh+1];
    int n,l,r;
    for(n=0,l=0,r=0; n<lengh; n++) {
        if(n<halflengh) {
            left[l]=initial[n];
            l++;
        } else {
            right[r]=initial[n];
            r++;
        }
    }
    if(halflengh>1)
        mergesort(left,halflengh+1);
    if(lengh-halflengh>1)
        mergesort(right,lengh-halflengh+1);
    improvemerge(left,right,initial,lengh);
}
void improvemerge(int src1[], int src2[], int dst[], int n)
{
    src1[n/2]=INT_MAX;
    src2[n-n/2]=INT_MAX;
    int i1 = 0, i2 = 0, id = 0;
    while (i1+i2 < n )
        dst[id++] = (src1[i1] < src2[i2]) ? src1[i1++] : src2[i2++];
}
