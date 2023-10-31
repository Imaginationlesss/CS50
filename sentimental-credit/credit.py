# TODO

from cs50 import get_int

while true:
    credit_card_number = get_int("Enter credit card number:")

    if not card_number:
        break

    if valid_card(credit_card_number):
        card_type = get_card_type(credit_card_number)
        print()
