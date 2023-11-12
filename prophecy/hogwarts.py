import csv

def filter_house(house, houses, head):
    count = 0
    for x in houses:
        if x == house:
            count += 1
    if count == 0:
        houses.append({"house": house, "head": head})

def filter_students(name, students):
    students.append()



students = []
houses = []
house_assaigment = []

with open("students.csv", "r") as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        name = row["student_name"]
        house = row["house"]
        head = row["head"]

        filter_house(house, houses, head)
