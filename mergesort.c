#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#include <limits.h>
void improvemerge(int src1[],int src2[],int dst[],int n);
void mergesort(int initial[],int lengh);
int main()
{
    FILE *output;
    output = fopen("opt.txt", "w");
    int n,count;
    int input[20001]= {0}; //last number is for judge not data
    for(n=0;n<20000;n++){
    input[n]=(rand() % 50000);
    }
    input[20000]=INT_MAX;
    int lengh=sizeof(input)/4;
    fprintf(output,"initial:");
    for(n=0; n<20000; n++) {
        fprintf(output,"%d ",input[n]);
        fprintf(output,"\n");
    }
    fprintf(output,"\n");
    unsigned long start = clock();
    for(count=0; count<1000; count++)
        mergesort(input,lengh);
    unsigned long end = clock();
    fprintf(output,"after mergesort:");
    for(n=0; n<20000; n++) {
        fprintf(output,"%d ",input[n]);
    fprintf(output,"\n");
    }
    fprintf(output,"\n");
    printf("Time(repeat 1000)=%1.3lf ms\n",(double)(end-start)/CLOCKS_PER_SEC*1000);
    fclose(output);
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
