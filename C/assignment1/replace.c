/*
    author: Arnaud Jalbert
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "replace.h"
#include "traversal.h"
#include "report.h"

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        // stores word to search for
        char *word = malloc(strlen(argv[1]) * sizeof(char));
        strcpy(word, argv[1]);
        printf("\nTarget Word: %s\n\n", word);

        // init the logger
        struct logger *head = init_logger();

        printf("----------STARTING TRAVERSAL------------\n");
        traversal(".", word, head);
        printf("----------TRAVERSAL FINISHED------------\n\n");

        // displaying the updated filess
        printf("***Search Report***\n\n");
        displaySortedLogs(head);
        printf("\n\n");

        // frees memory allocated for the word
        free(word);

        return 0;
    }
    else if (argc == 1)
    {
        printf("No arguments were supplied, please supply a word to identify.\n");
        return 1;
    }
    else
    {
        printf("Too much arguments were supplied, please supply ONE word to identify.\n");
        return 1;
    }
}
