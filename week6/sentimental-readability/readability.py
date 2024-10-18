# TODD
from cs50 import get_float, get_int, get_string
def  count_letters(text):
    sum=0
    for c in text:
        if(c.isalpha()):
            sum+=1
    return sum

def count_words( text):
    sum=0
    for c in text :
        if(c==' ') :
            sum+=1
    return sum+1

def count_sentences(text) :
    sum=0
    for c in text :
         if(c=='.'   or c=='?' or c=='!' ):
             sum+=1
    return sum

s=get_string("Text: ")
st=count_sentences(s)
le=count_letters(s)
wo=count_words(s)
index= (0.0588 * (le/wo)*100)-(0.296 * (st/wo)*100)-15.8

if(index>=16):
    print("Grade 16+\n")
elif(index>=1):
    print(f"Grade {round(index)}\n")
else:
    print("Before Grade 1\n")


