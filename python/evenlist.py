numbers = list(map(int, input("Enter integers: ").split()))
result=[]
for i in numbers:
    if(i%2!=0):
        result.append(i)
        
print(result)
        
        
