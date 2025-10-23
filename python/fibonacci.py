r=int(input("enter the range:" ))
a=0
b=1
result=[a,b]
for i in range(2,r):
    c=a+b
    result.append(c)
    a=b
    b=c
print(result)
