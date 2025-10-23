str=input("enter a string:")
str1=input("enter another string:")
mid=""
for i in range(1,len(str)):
        mid+=str[i]
mid1=""
for i in range(1,len(str1)):
        mid1+=str1[i]
print(str1[0]+mid+str[0]+mid1)