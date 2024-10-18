# TODO
from cs50 import get_float, get_int, get_string


con = get_float("Change owed: ")
while(con<=0):
    con = get_float("Change owed: ")

num=0
while(con>=0.25):
    num+=1
    con=con-0.25

    con=float(format(con, '.2f'))

while(con>=0.1):
    num+=1
    con=con-0.1
    con=float(format(con, '.2f'))
while(con>=0.05):
    num+=1
    con=con-0.05

    con=float(format(con, '.2f'))
while(con>=0.01):
    num+=1
    con=con-0.01

    con=float(format(con, '.2f'))
print(num)


