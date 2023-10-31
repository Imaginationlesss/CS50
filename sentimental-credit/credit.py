# TODO

from cs50 import get_int

def get_credit_card_number():
    while true:
        credit_card_number = get_int("Enter credit card number:")

        if not card_number:
            break

        if valid_card(credit_card_number):
            card_type = get_card_type(credit_card_number)
            print(f"Card Type: {card_type}")
        else:
            print("Invalid credit card number")

def get_card_type(credit_card_number):
    credit_card_number = credit_card_number.replace(" ", "")

    if not credit_card_number.isdigit():
        return "Invalid! Please type in only digits!"

    if len(credit_card_number) == 15 and credit_card_number[0:2]



