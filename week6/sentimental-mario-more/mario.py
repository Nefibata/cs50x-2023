# TODO
from cs50 import get_float, get_int, get_string


height = get_int("Height: ")
while(height<=0 or height>8):
    height = get_int("Height: ")


i=0
while(i<height):
    j=0
    s=""
    while(j<height-i-1):
        s=s+" "
        j+=1
    j=0
    while(j<i+1):
        s=s+"#"
        j+=1
    s=s+"  "
    j=0
    while(j<i+1):
        s=s+"#"
        j+=1
    print(s)
    i+=1
