# TODO

from cs50 import get_string


def get_credit_card_number(credit_card_number):
    credit_card_number = credit_card_number.replace(" ", "")

    if not credit_card_number.isdigit():
        return "Invalid! Please type in only digits!"


def get_card_type():
    while True:
        credit_card_number = get_string("Enter credit card number:")

        if not credit_card_number:
            break

        card_type = get_card_type(credit_card_number)
        if card_type != "Invalid":
            print(f"Card Type: {card_type}")
        else:
            print("Invalid credit card number")

    if len(credit_card_number) == 15 and credit_card_number[0:2] in ["34", "37"]:
        return "AMEX"
    if len(credit_card_number) == 16:
        if credit_card_number[0] == "4":
            return "VISA"
        if "51" <= credit_card_number[0:2] <= "55":
            return "MASTERCARD"

    return "INVALID"
