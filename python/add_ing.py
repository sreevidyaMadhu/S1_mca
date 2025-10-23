word=input("enter a word:")
if word.endswith("ing"):
    word=word+"ly"
    print(word)
else:
    word=word+"ing"
    print(word)