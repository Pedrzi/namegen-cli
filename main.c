#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *get_word(FILE *fp);
long get_line_count(FILE *fp);

int main(int argc, char *argv[])
{
    char *adjective_file = "english-adjectives.txt";
    char *noun_file = "english-nouns.txt";
    char *spacer = NULL;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-a") == 0)
            adjective_file = argv[++i];
        else if (strcmp(argv[i], "-n") == 0)
            noun_file = argv[++i];
        else if (strcmp(argv[i], "-s") == 0)
            spacer = argv[++i];
        else
        {
            fprintf(stderr, "Usage: %s [-a adjective_file] [-n noun_file] [-s spacer]\n", argv[0]);
            return 1;
        }
    }

    srand(time(NULL));
    FILE *adjectiveptr = fopen(adjective_file, "r");
    FILE *nounptr = fopen(noun_file, "r");

    if (!adjectiveptr || !nounptr)
    {
        perror("fopen failed");
        return 1;
    }

    char *adj = get_word(adjectiveptr);
    char *noun = get_word(nounptr);

    int num = rand() % 100;

    if (spacer)
    {
        printf("%s%s%s%s%02d\n", adj, spacer, noun, spacer, num);
    }
    else
        printf("%s%s%02d\n", adj, noun, num);

    free(adj);
    free(noun);

    fclose(adjectiveptr);
    fclose(nounptr);
    return 0;
}

char *get_word(FILE *fp)
{
    long size = get_line_count(fp);
    if (size == 0)
    {
        fprintf(stderr, "Error: file is empty\n");
        exit(1);
    }
    int rand_num = rand() % size;
    char *buffer = NULL;
    size_t len = 0;
    rewind(fp);
    for (int i = 0; i <= rand_num; i++)
        if (getline(&buffer, &len, fp) == -1)
        {
            perror("getline failed");
            exit(1);
        }
    buffer[strcspn(buffer, "\n")] = '\0';
    char *word = strdup(buffer);
    free(buffer);
    if (!word)
    {
        perror("strdup failed");
        exit(1);
    }
    if (word[0])
        word[0] = toupper((unsigned char)word[0]);

    return word;
}

long get_line_count(FILE *fp)
{
    char buffer[256];
    long word_counter = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        word_counter++;
    }
    rewind(fp);

    return word_counter;
}
