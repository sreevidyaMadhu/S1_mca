import csv
#path="csvfile.csv"

with open("csvfile.csv",newline="") as file: 
    reader=csv.reader(file)
    
    for row in reader:
        print(row)