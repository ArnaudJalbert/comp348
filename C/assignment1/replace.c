#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "replace.h"
#include "traversal.h"

int main(int argc, char *argv[])
{
    int status = 0;
    if (argc == 2)
    {
        printf("----------STARTING TRAVERSAL------------\n");
        char *word = malloc(strlen(argv[1]) * sizeof(char));
        word = argv[1];

        status = traversal(".", word);
        printf("----------TRAVERSAL FINISHED------------\n");
    }
    else if (argc == 1)
    {
        printf("No arguments were supplied, please supply a word to identify.\n");
    }
    else
    {
        printf("Too much arguments were supplied, please supply ONE word to identify.\n");
    }

    return status;
}
