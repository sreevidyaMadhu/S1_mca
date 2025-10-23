string = input("Enter a string: ")

print("Character frequencies:")

for ch in string:
    count = 0
    for i in string:
        if ch == i:
            count += 1
    print(ch, ":", count)
