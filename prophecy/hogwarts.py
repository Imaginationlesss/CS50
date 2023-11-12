import csv

def filter_house(house, houses):
    count = 0
    for x in houses:
        if x == house:
            count += 1
    if count == 0:
        houses.append(house)

def filter_students(student_name, name):



students = []
houses = []
house_assaigment = []

with open("students.csv", "r") as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        name = row["student_name"]
        house = row["house"]
        head = row["head"]

        filter_house(house,houses)
