#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long x=0;
    int count=1;
    int a=0;
    int b=0;
    int type=0;
    int type2=0;
    x=get_long("Number:");

    while(x!=0){
        int temp=x%10;
        x=x/10;
        if(x<100&&x>10){
            type=x;
        }
        if(x>0&&x<10){
            type2=x;
        }
        if((count&1)==0){
            temp=temp*2;
            int temp1=temp%10;
            int temp2=temp/10;
            temp=temp1+temp2;
            a=a+temp;
        }else{
            b=b+temp;
        }
        count++;
    }

    count=count-1;


    if((a+b)%10==0){
        if((type==34 ||type==37) && count==15){
            printf("AMEX\n");
            return 0;
            }
        if((type==51 ||type==52||type==53||type==54||type==55)&&(count==16)) {
            printf(" MASTERCARD\n");
            return 0;
            }
        if((count == 13 || count==16)&&type2==4){
            printf("VISA\n");
            return 0;
        }
        printf("INVALID\n");
    }else{
        printf("INVALID\n");
    }
}
