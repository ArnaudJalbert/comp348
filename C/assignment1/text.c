#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "text.h"

int readFile(char *pathPtr, char *wordPtr)
{
    /*
        Openning the file for both reading.
        If the file does not exist, fopen() returns NULL.
    */
    FILE *currentFile = fopen(pathPtr, "r");

    // Checking if file has successfully opened, else we return false and stop.
    if (!currentFile)
    {
        printf("Path %s does not exist.\n", pathPtr);
        return 0;
    }

    /*
       Temp file in which we will copy the content of the original file.
       When we spot a line with the target words, we will make a new string
       with the right update and write that line instead of the original line.
   */
    char tempPath[MAX_FILENAME] = "";
    strcat(tempPath, pathPtr);
    strcat(tempPath, "____TEMP");
    char *tempPathPtr = tempPath;
    FILE *replaceFile = fopen(tempPathPtr, "w");

    // buffer to store each line of the file
    char line[MAX_LINE];
    char *linePtr = line;

    // counting how many times we update the file
    int nbUpdates = 0;

    while (1)
    {
        // extract current line from file and store it in buffer
        fgets(linePtr, MAX_LINE, currentFile);

        if (findWord(replaceFile, linePtr, wordPtr))
        {
            nbUpdates++;
        }

        if (feof(currentFile))
        {
            break;
        }
    }

    // closing both files
    fclose(currentFile);
    fclose(replaceFile);

    // removing original file
    remove(pathPtr);
    // renaming the temp file with the original fileName
    rename(tempPathPtr, pathPtr);

    return 1;
}

int findWord(FILE *replaceFile, char *linePtr, char *wordPtr)
{
    char *ref = strstr(linePtr, wordPtr);
    if (ref != NULL)
    {
        updateWord(replaceFile, linePtr, wordPtr, ref);
        fputs(linePtr, replaceFile);
        // we're not deallocating ref since it's pointing to a character in our line string
        // we will deallocate the memory at this address it when we deallicate linePtr
        return 1;
    }

    fputs(linePtr, replaceFile);
    return 0;
}

void updateWord(FILE *replaceFile, char *linePtr, char *wordPtr, char *ref)
{
    for (int i = 0; i < strlen(wordPtr); i++)
    {
        char to_replace = toupper(*ref);
        *ref = to_replace;
        ref++;
    }
}