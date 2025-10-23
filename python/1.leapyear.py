from datetime import datetime
current_year= datetime.now().year
last_year=int(input("enter the range upto which you want to find leap year:"))
for i in range(current_year,last_year+1):
     if(i%4==0 and i%100!=0)or(i%400==0):
         print(i,"is leap year")
 