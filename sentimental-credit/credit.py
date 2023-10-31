# TODO

from cs50 import get_string


def is_valid_credit_card(credit_card_number):
    credit_card_number = credit_card_number.replace(" ", "")

    if not credit_card_number.isdigit():
        return False

    total, double = 0, False

    for i in range(len(credit_card_number) - 1, -1, -1):
        digit = int(credit_card_number[i])
        if double:
            digit *= 2
            digit = digit - 9 if digit > 9 else digit
        total += digit
        double = not double

    return total % 10 == 0


def get_credit_card_number():
    while True:
        credit_card_number = get_string("Enter credit card number:")

        if not credit_card_number:
            break

        if is_valid_credit_card(credit_card_number):
            card_type = get_card_type(credit_card_number)
            print(f"Card Type: {card_type}")
        else:
            print("Invalid credit card number")


def get_card_type(credit_card_number):
     credit_card_number = credit_card_number.replace(" ", "")

    if not credit_card_number.isdigit():
        return "INVALID"

    if len(credit_card_number) == 15 and credit_card_number.startswith(("34", "37")):
        return "AMEX"
    elif len(credit_card_number) == 16:
        if credit_card_number[0] == "4":
            return "VISA"
        elif "51" <= credit_card_number[0:2] <= "55":
            return "MASTERCARD"

    return "INVALID"


get_credit_card_number()
