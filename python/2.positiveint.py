numbers = list(map(int, input("Enter integers: ").split()))
print(numbers)
pos_int = []

for x in numbers:
    if int(x)>0:
        pos_int.append(x)
print("the positive integers are: ",pos_int)
