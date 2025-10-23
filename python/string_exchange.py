str=input("enter a string:")
if(len(str)<2):
    print(str)
else:
    mid=""
    for i in range(1,len(str)-1):
        mid+=str[i]
    print("the string after swapping is ",str[-1]+mid+str[0])