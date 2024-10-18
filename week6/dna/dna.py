import csv
import sys


def main():

    # TODO: Check for command-line usage
    if(len(sys.argv)!=3):
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # TODO: Read database file into a variable
    file = open(sys.argv[1],'r')
    csv_r=csv.reader(file)
    # TODO: Read DNA sequence file into a variable
    dna = open(sys.argv[2],'r')
    dna_line=dna.readline()
    # TODO: Find longest match of each STR in DNA sequence
    temp1=next(csv_r)[1:]
    temp2=[]
    b=False
    for seq in temp1:
        temp2.append(longest_match(dna_line,seq))
    # TODO: Check database for matching profiles
    for row in csv_r:
        temp3=row[1:]
        a=False
        for i in range(len(temp2)):
            if(int(temp3[i])!=temp2[i]):
                a=True
                break
        if(a):
            continue
        else:
            print(row[0])
            b=True
            break
    if(not b):
        print("No match")
    file.close()
    dna.close()
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
