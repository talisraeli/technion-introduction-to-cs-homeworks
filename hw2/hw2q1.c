#include <stdbool.h>
#include <stdio.h>

#define SENTENCE_LENGTH 30
#define WORD_LENGTH 10
#define LETTERS_COUNT 26
#define INVALID_OFFSET (-1)

int main() {
    char sentence[SENTENCE_LENGTH] = "", word[WORD_LENGTH] = "";
    char input;
    int i;

    // getting sentence input
    for (i = 0; i < SENTENCE_LENGTH; i++) {
        if (scanf("%c", &input) != 1) {
            break;
        }

        const bool isValidInput =
            (input >= 'a' && input <= 'z') || input == ' ';

        if (!isValidInput) {
            break;
        }

        sentence[i] = input;
    }

    const int sentenceLength = i;

    // getting word input
    for (i = 0; i < WORD_LENGTH; i++) {
        if (scanf("%c", &input) != 1) {
            break;
        }

        const bool isValidInput = input >= 'a' && input <= 'z';

        if (!isValidInput) {
            break;
        }

        word[i] = input;
    }

    const int wordLength = i;

    int currentWordLength = 0, currentOffset = INVALID_OFFSET;

    // iterating the sentence and checking for a match of the word's offset
    for (i = 0; i < sentenceLength; i++) {
        // it's a valid match if the current word is the same as the input
        // and current offset is valid.
        const bool isValidMatch =
            currentOffset != INVALID_OFFSET && currentWordLength == wordLength;

        if (isValidMatch) {
            printf("%d", currentOffset);
            return 0;
        }

        const bool isSpaceChar = sentence[i] == ' ';

        if (isSpaceChar) {
            // resetting the variables and continue to the next word
            currentWordLength = 0;
            currentOffset = INVALID_OFFSET;
            continue;
        }

        const bool isValidWordLength = currentWordLength < wordLength;

        if (!isValidWordLength) {
            continue;
        }

        // calculating the offset based on the position of the letters.
        // if the sentence's letter behind the word's letter position,
        // we're shifting the offset by `LETTERS_COUNT`
        const int offset =
            sentence[i] >= word[currentWordLength]
            ? sentence[i] - word[currentWordLength]
            : sentence[i] + LETTERS_COUNT - word[currentWordLength];

        const bool isFirstLetter = currentWordLength == 0;

        // if it's the first letter on this word, assign the current offset
        if (isFirstLetter) {
            currentOffset = offset;
        }

        const bool isSameOffset = offset == currentOffset;

        // if the offset isn't the same, assign it to invalid offset.
        if (!isSameOffset) {
            currentOffset = INVALID_OFFSET;
        }

        currentWordLength++;
    }

    // print the result if it had a match on the end of the sentence
    printf("%d", currentOffset);
    return 0;
}
