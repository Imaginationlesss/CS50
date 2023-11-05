# TODO

from cs50 import get_string

def main():
    text = get_string("Text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)
    index = calculation(letters, words, sentences)

    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


def count_letters(text):
    return sum(1 for char in text if char.isalpha())


def count_words(text):
    return sum(text.split())

def count_sentences(text):
    return sum(1 for chat in text if )



