sentence = input("Enter a sentence: ")
words = sentence.split()
count = {}
for word in words:
    if word in count:
        count[word] += 1
    else:
        count[word] = 1

for word, count in count.items():
    print(f"{word}: {count}")