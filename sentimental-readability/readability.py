# TODO

from cs50 import get_string

def main():
    text = get_string("Text: ")

letters = count_letters(text)
words = count_words(text)
sentences = count_sentences(text)
index = calculation(letters, words, sentences)
