#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

// structure to store friend name and plant name
typedef struct
{
    char short_word[10];
    char original_word[20];
} NODE;

// fucntion that returns index of "#" in given string str
int get_index(char *str, char search_char)
{
    // traverse from i=0 till end of string
    for (int i = 0; str[i] != '\0'; i++)
    {
        // if any character matches with search_char, then return i
        if (str[i] == search_char)
            return i;
    }
    // atlast return 0, indicating required character is not present in string
    return 0;
}

// function that searches for a word in array and print its original word if found, else it print the word itself
void search(NODE array[], int len, char *search_word)
{
    // traverse from i=0 to len
    for (int i = 0; i < len; i++)
    {
        // if any shortword matches with given search_word, then print its original word and return
        if (strcmp(array[i].short_word, search_word) == 0)
        {
            printf("%s ", array[i].original_word);
            return;
        }
    }

    // if we have reached here, it means given search word is not found in array, so print word itself
    printf("%s ", search_word);
}

// testing main function
int main()
{
    // open the file named "testdata.in" in read mode and assign a pointer
    FILE *fp = fopen("testdata.txt", "r");

    // if file is not found, then print following message and return
    if (fp == NULL)
    {
        printf("File not found\n");
        return 0;
    }

    // get no.of lines to read
    char *line = (char *)malloc(MAX * sizeof(char));
    fgets(line, sizeof(line), fp);
    int len = atoi(line);

    // create an array of NODES of length "len"
    NODE array[len];

    // traverse from i=0 to len-1
    for (int i = 0; i < len; i++)
    {
        // read a line of ata
        fgets(line, MAX, fp);

        // assign '\0' at end of line
        line[strlen(line) - 1] = '\0';

        // gte index of '#' in given line
        int index = get_index(line, '#');

        // copy from line+index+1 to array[i].plant
        strcpy(array[i].original_word, line + index + 1);

        // make line[index] to '\0'
        line[index] = '\0';

        // copy line to array[i].name
        strcpy(array[i].short_word, line);
    }

    // read no.of names to search
    fgets(line, sizeof(line), fp);
    int n = atoi(line);

    // traverse from i=0 to n
    for (int i = 0; i < n; i++)
    {
        // print header
        printf("Case #%d: ", i + 1);

        // get name from file to search
        fgets(line, MAX, fp);
        line[strlen(line) - 1] = '\0';

        while (1)
        {
            // get the index of ' '(empty space)
            int index = get_index(line, ' ');

            // create a temporary string
            char search_word[100];

            // if index!=0, then make line[index] to '\0'
            if (index != 0)
                line[index] = '\0';

            // copy the substring into search_word
            strcpy(search_word, line);

            // call search_word() function
            search(array, len, search_word);

            // if index=0, then break the loop
            if (index == 0)
                break;

            // else update line pointer
            line = line + index + 1;
        }
        printf("\n");
    }

    // close the file
    fclose(fp);

    return 0;
}