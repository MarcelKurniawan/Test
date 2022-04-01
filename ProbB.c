#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef struct
{
    char short_word[10];
    char original_word[20];
} NODE;

int get_index(char *str, char search_char)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {

        if (str[i] == search_char)
            return i;
    }

    return 0;
}

void search(NODE array[], int len, char *search_word)
{
    int i;
    for (i = 0; i < len; i++)
    {

        if (strcmp(array[i].short_word, search_word) == 0)
        {
            printf("%s", array[i].original_word);
            return;
        }
    }

    printf("%s", search_word);
}

int main()
{
    int i;
    FILE *fp = fopen("testdata.txt", "r");

    char *line = (char *)malloc(MAX * sizeof(char));
    fgets(line, sizeof(line), fp);
    int len = atoi(line);

    NODE array[100];

    for (i = 0; i < len; i++)
    {

        fgets(line, MAX, fp);
        line[strlen(line) - 1] = '\0';
        int index = get_index(line, '#');
        strcpy(array[i].original_word, line + index + 1);
        line[index] = '\0';
        strcpy(array[i].short_word, line);
    }

    fgets(line, sizeof(line), fp);
    int n = atoi(line);

    for (i = 0; i < n; i++)
    {

        printf("Case #%d: ", i + 1);

        fgets(line, MAX, fp);
        line[strlen(line) - 1] = '\0';

        while (1)
        {

            int index = get_index(line, ' ');

            char search_word[100];

            if (index != 0)
                line[index] = '\0';

            strcpy(search_word, line);

            search(array, len, search_word);

            if (index == 0)
                break;

            line = line + index + 1;
        }
        printf("\n");
    }

    fclose(fp);

    return 0;
}
