import csv
dict=[
    {"course":"bca","fees":"12000"},
    {"course":"mca","fees":"120000"},
    {"course":"mba","fees":"24000"}
]
with open("copyfile.csv","w") as csv1:
      writer=csv.DictWriter(csv1,fieldnames=["course","fees"])
      writer.writeheader()
      writer.writerows(dict)
with open("copyfile.csv","r") as csv1:
    reader=csv.DictReader(csv1)
    for row in reader:
            print(row)             