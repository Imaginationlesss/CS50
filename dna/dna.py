import csv
import sys


def main():
    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Incorect number of command-line arguments")
        sys.exit(1)

    # TODO: Read database file into a variable
    with open(sys.argv[1], "r") as csvfile:
        reader = csv.DictReader(csvfile)
        data = list(reader)
        header = reader.fieldnames

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as sequencefile:
        dna = sequencefile.read()

    # TODO: Find longest match of each STR in DNA sequence
    str_match = {}
    for str in header[1:]:
        str_match[str] = longest_match(str, dna)

    # TODO: Check database for matching profiles
    for name in data:
        if all(str_match[str] == name[str] for str in str_match):
            print(name["name"])
            return
    print("No match")



def longest_match(sequence, subsequence):
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)
    for i in range(sequence_length):
        count = 0
        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length
            if sequence[start:end] == subsequence:
                count += 1
            else:
                break
        longest_run = max(longest_run, count)
    return longest_run
main()
