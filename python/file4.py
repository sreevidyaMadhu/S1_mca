import csv
dict1=[
    {"name":"ram","mark":"25"},
    {"name":"john","mark":"35"},
    {"name":"anu","mark":"30"},
    ]
with open("dict1.csv","w") as file:
    writer=csv.DictWriter(file,fieldnames=["name","mark"])
    writer.writeheader()
    writer.writerows(dict1)
    
with open("dict1.csv","r")as csvfile:
    file=csv.DictReader(csvfile)
    for row in file:
        print(row)