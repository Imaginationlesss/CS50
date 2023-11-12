import csv
from cs50 import SQL

def filter_house(house, houses, head):
    count = 0
    for x in houses:
        if x == house:
            count += 1
    if count == 0:
        houses.append({"house": house, "head": head})

def filter_students(name, students):
    students.append({"student_name": name})

def relations(name, house, house_assaigment):
    house_assaigment.append({"sutdent_name": name, "house": house})

db = SQL("sqlite:///roaster.db")

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
        filter_students(name, students)
        relations(name, house, house_assaigment)

print(house_assaigment)
