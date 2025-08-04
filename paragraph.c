#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

struct WordCount {
    char word[MAX_WORD_LEN];
    int count;
};

int isSeparator(char c) {
    return c == ' ' || c == '\n' || c == '\t' || c == '.' || c == ',' || c == '?' || c == '!' || c == ';' || c == ':';
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

int main() {
    char paragraph[1000];
    struct WordCount wordCounts[MAX_WORDS];
    int wordCount = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    char *token = strtok(paragraph, " \n\t.,!?;:");

    while (token != NULL) {
        toLowerCase(token);

        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(wordCounts[i].word, token) == 0) {
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }

        if (!found && wordCount < MAX_WORDS) {
            strcpy(wordCounts[wordCount].word, token);
            wordCounts[wordCount].count = 1;
            wordCount++;
        }

        token = strtok(NULL, " \n\t.,!?;:");
    }

    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}