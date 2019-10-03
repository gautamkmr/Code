import csv

filename = "row.csv"

fields = []
rows = []

with open(filename, 'r') as csvfile:
   csvreader = csv.reader(csvfile)
   for row in csvreader:
      rows.append(row)

total = 0.0
for i in range(len(rows)):
    total += float(rows[i][1])

# Average of 2nd column
print(total/len(rows))
