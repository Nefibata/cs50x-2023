# TODO
from cs50 import get_float, get_int, get_string


x = get_int("Number: ")
count=1
a=0
b=0
type=0
type2=0
while(x is not 0):
    temp=x%10
    x=x//10
    if(x<100 and x>10):
        type=x
    if(x>0 and x<10):
        type2=x
    if((count%2)==0):
        temp=temp*2
        temp1=temp%10
        temp2=temp//10
        temp=temp1+temp2
        a=a+temp
    else:
        b=b+temp
    count+=1
count=count-1

if((a+b)%10==0):
    if((type==34 or type==37) and count==15):
        print("AMEX\n")
    elif((type==51 or type==52 or type==53 or type==54 or type==55)  and (count==16)) :
        print(" MASTERCARD\n")
    elif((count == 13 or count==16) and type2==4):
        print("VISA\n")
    else:
        print("INVALID\n")
else:
    print("INVALID\n")

