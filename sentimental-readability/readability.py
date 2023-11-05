# TODO

from cs50 import get_string

def main():
    text = get_string("Text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)
    (round)index = calculation(letters, words, sentences)

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
    sentence_ending = (".", "!", "?")
    return sum(1 for char in text if char in sentence_ending)

def calculation(letters, words, sentences):
    L = (letters / words) * 100
    S = (sentences / words) * 100
    return sum(0.0588 * L - 0.296 * S - 15.8)



