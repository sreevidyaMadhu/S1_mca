import csv

with open("csvfile.csv",newline="") as file:
    reader=csv.reader(file)
    
    header=next(reader)
    
    name_ind=header.index("name")
    age_ind=header.index("age")
    
    for row in reader:
        print(row[name_ind],row[age_ind])
        