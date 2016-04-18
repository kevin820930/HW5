#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>

int func(unsigned int);
int main()
{
    unsigned int count=1;
    int ans;
    for(count=0; count<1000; count=count+99) {
        printf("------input number %u--------\n",count);
        ans=func(count);
        printf("------output number %d--------\n",ans);
    }
    printf("------input number %u--------\n",0xfffffff1);
    ans=func(0xfffffff1);
    printf("------output number %d--------\n",ans);
}

int func(unsigned int x)
{
    int val = 0;
    int i = 0;
    int r=0;
    int n=0;
    unsigned int q;
    unsigned int num;
    int byte[80]= {0};
    q=x;
    num=x;
    while(q!=0) {
        q=num/2;
        r=num%2;
        num=q;
        byte[n]=r;
        n++;
    }
    printf("2bit= ");
    for(n=n-1; n>=0; n--)
        printf("%d",byte[n]);
    printf("\n");
    n=0;
    for (i = 0; i < 32 ; i++) {
        val = (val << 1) | (x & 0x1);
        /*q=x;
        num=x;
        while(q!=0) {
            q=num/2;
            r=num%2;
            num=q;
            byte[n]=r;
            n++;
        }
        printf("2bit= ");
        for(n=n-1; n>=0; n--)
            printf("%d",byte[n]);
        printf("\n");
        n=0;
        q=val;
        num=val;
        while(q!=0) {
            q=num/2;
            r=num%2;
            num=q;
            byte[n]=r;
            n++;
        }
        printf("val = ");
        for(n=n-1; n>=0; n--)
            printf("%d",byte[n]);
        printf("\n");
        n=0;*/
        x>>=1;
    }
    q=val;
    num=val;
    while(q!=0) {
        q=num/2;
        r=num%2;
        num=q;
        byte[n]=r;
        n++;
    }
    printf("val = ");
    for(n=n-1; n>=0; n--)
        printf("%d",byte[n]);
    printf("\n");
    n=0;
    return val;
}
