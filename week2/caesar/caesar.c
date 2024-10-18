#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
int string_to_int(string s);
int main(int argc, string argv[])
{

    if(argc>2){
        printf("Usage: ./caesar key");
        return 1;
    }
    if(argc==1){
        printf("Usage: ./caesar key");
        return 1;
    }
    int n=string_to_int(argv[1])%26;
    if(n<0){
        printf("Usage: ./caesar key");
        return 1;
    }
    string s=get_string("plaintext:");

    printf("x:%i\n",n);
    int i=0;
    while(s[i]){
        if(isalpha(s[i])){
            int temp=(int)s[i]+n;
            if(temp>(int)'Z'&&temp<(int)'a'){
                temp=temp-26;
            }else if (temp>(int)'z'){
                temp=temp-26;
            }
            s[i]=(char)temp;
        }

        i++;
    }
    printf("ciphertext:%s\n",s);

}
int string_to_int(string s){
    int re=0;
    int count=0;
    while(s[count]){
        int temp=(char)s[count]-(char)'0';
        if(temp>9||temp<0)return -1;
        re=re*10+temp;
        count++;
    }
    return re;
}
