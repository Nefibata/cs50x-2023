#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
int count_words(string text);
int count_letters(string text);
int count_sentences(string text);
int main(void)
{
    string s=get_string("Text: ");
    float st=count_sentences(s);
    float le=count_letters(s);
    float wo=count_words(s);
    float index= (0.0588 * (le/wo)*100)-(0.296 * (st/wo)*100)-15.8;

    if(index>=16){
        printf("Grade 16+\n");
    }else if(index>=1){
        printf("Grade %i\n",(int)round(index));

    }else{
        printf("Before Grade 1\n");
    }


}
int count_letters(string text){
    int count =0;
    int sum=0;
    while(text[count]){
        if(isalpha(text[count])){
            sum++;
        }
        count++;
    }
    return sum;
}
int count_words(string text){
    int count =0;
    int sum=0;
    while(text[count]){
        if(isspace(text[count])){
            sum++;
        }
        count++;
    }
    return sum+1;

}
int count_sentences(string text){
    int count =0;
    int sum=0;
    while(text[count]){
        if(text[count]=='.' ||text[count]=='?'||text[count]=='!' ){
            sum++;
        }
        count++;
    }
    return sum;
}
