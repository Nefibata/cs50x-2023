#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, string argv[])
{
    if(argc==1||argc>2){
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if(strlen(argv[1])!=26){
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    string s=argv[1];
    int boolean[26]={0};
    int j=0;
    while(s[j]){
        if(!isalpha(s[j])) {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        s[j]=tolower(s[j]);
        if(boolean[s[j]-'a']==0){
boolean[s[j]-'a']=1;
        }else{
                        printf("Key must contain 26 characters.\n");
            return 1;
        }

        j++;
    }

    string s2=get_string("plaintext:");
    int i=0;
    while(s2[i]){
        if(isalpha(s2[i])){
            int temp=(int)s2[i];
            if(temp>=(int)'a'){//小写
                temp=temp-(int)'a';
                s2[i]=s[temp];

            }else{//大写
                temp=temp-(int)'A';
                s2[i]=(char)((int)s[temp]-32);
            }
        }
        i++;
    }
    printf("ciphertext:%s\n",s2);



}
