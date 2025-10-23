num=int(input("Enter a number: "))
n=int(input("Enter the limit: "))
print("Multiplication table of",num,"is:")

for i in range(1,n+1):
    print(num,"*",i,"=",num*i)
