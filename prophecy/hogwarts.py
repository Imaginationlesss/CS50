import csv

def filter_house(house, houses):
    for 

students = []
houses = []
house_assaigment = []

with open("students.csv", "r") as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        name = row["student_name"]
        house = row["house"]
        head = row["head"]

