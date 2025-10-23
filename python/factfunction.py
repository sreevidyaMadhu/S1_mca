def fact(n):
    factorial=1
    for i in range(1,n+1):
       factorial=factorial*i
    print("The factorial of",n,"is:",factorial)
num=int(input("enter the number:"))
fact(num)