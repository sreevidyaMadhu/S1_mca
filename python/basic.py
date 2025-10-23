"""print("Hello, World!")
a=int(input("enter a number: "))
b=int(input("enter another number: "))
sum=a+b
print("The sum is: ",sum)
fname=input("enter your first name: ")
lname=input("enter your last name: ")
print("Your full name is: ",fname+" "+lname)
num=int(input("enter a number: "))
if num%2==0:
    print("the number is even")
else:
    print("the number is odd")

year=int(input("enter a year: "))
if (year%4==0 and year%100!=0) or (year%400==0):
    print("the year is a leap year")
else:
    print("the year is not a leap year")
    """ 


from datetime import datetime
current_year= datetime.now().year
last_year=int(input("enter the range upto which you want to find leap year"))
for i in range(current_year,last_year+1):
     if(i%4==0 and i%100!=0)or(i%400==0):
         print(i,"is leap year")
 