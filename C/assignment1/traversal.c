#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include "text.h"
#include "report.h"

/*
    This function will iterate over the current directory and if it finds
    a .txt file, it will update it with the target word.
    If it finds another directory, it will call this function recursively
    on that directory.
*/
struct logger *traversal(char *dir, char *word, struct logger *logging)
{
    // initializing directory variable
    DIR *directory;
    struct dirent *entry;
    directory = opendir(dir);

    // checks if directory exists
    if (directory == NULL)
    {
        printf("Error opening directory.\n");
        return NULL;
    }

    // iterating through directory
    while ((entry = readdir(directory)) != NULL)
    {
        // if the directoru is "." or "..", we don't traverse it.
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
        {
            continue;
        }

        // checking if the item is a directory
        if (entry->d_type == DT_DIR)
        {
            char toTraverse[MAX_FILENAME] = "";
            strcpy(toTraverse, dir);
            strcat(toTraverse, "/");
            strcat(toTraverse, entry->d_name);
            printf("Traversing %s:\n{\n", toTraverse);

            // we traverse that directory and come back when done to traverse this directory
            // we update the logger with what was logged in the other directory
            logging = traversal(toTraverse, word, logging);
            printf("}\n");
            continue;
        }

        // if the file is a .txt file, we call readFile() on it
        if (strstr(entry->d_name, ".txt") != NULL)
        {
            printf("%s\n", entry->d_name);
            char file[MAX_FILENAME] = "";
            strcpy(file, dir);
            strcat(file, "/");
            strcat(file, entry->d_name);

            // putting the path of the file in a string
            char *filePtr = file;

            // reading/updating file in readFile()
            int updates = readFile(filePtr, word);

            // logging the updates and where it was done
            logging = log_update(logging, entry->d_name, updates);
        }
    }

    // returns the logger if we called the function recursively
    return logging;
}