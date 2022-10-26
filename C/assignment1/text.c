#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "text.h"

/*
    This function will take a file path, read the file and if
    it finds a matching word to the given word then it puts it
    in all cap, but keeps the rest same as originial content.
*/
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
        return 1;
    }

    /*
       Temp file in which we will copy the content of the original file.
       When we spot a line with the target words, we will make a new string
       with the right update and write that line instead of the original line.
   */
    char tempPath[MAX_FILENAME] = "";
    strcat(tempPath, pathPtr);
    strcat(tempPath, "____TEMP");
    FILE *replaceFile = fopen(tempPath, "w");

    // buffer to store each line of the file
    char *linePtr = malloc(MAX_LINE * sizeof(char));

    // counting how many times we update the file
    int nbUpdates = 0;

    while (1)
    {
        // extract current line from file and store it in buffer
        fgets(linePtr, MAX_LINE, currentFile);

        // getting the number of updates made
        nbUpdates += findWord(replaceFile, linePtr, wordPtr);

        if (feof(currentFile))
        {
            break;
        }
    }

    // closing both files, also de-allocates memory
    fclose(currentFile);
    fclose(replaceFile);

    // removing original file
    remove(pathPtr);
    // renaming the temp file with the original fileName
    rename(tempPath, pathPtr);

    // de-allocating the line pointer
    free(linePtr);

    return nbUpdates;
}

/*
    Checks if there is the target word in a certain line, appends modified line if there is.
*/
int findWord(FILE *replaceFile, char *linePtr, char *wordPtr)
{
    // keep track of number of changes
    int count = 0;
    // to lower case all string to ignore the case
    char *linePtrLower = toLowerCase(linePtr);
    char *wordPtrLower = toLowerCase(wordPtr);
    // keeps track of where the word is
    char *ref = strstr(linePtrLower, wordPtrLower);

    // looping until there are no more words to replace
    while (1)
    {
        // checks if the word is in the line
        if (ref != NULL)
        {
            // updates the word
            updateWord(replaceFile, linePtr, wordPtr, ref);

            // keeps track of how many times we modify each file
            count++;

            // skipping the current word
            ref = ref + strlen(wordPtr);
            // checking if there are other occurences of the word
            ref = strstr(ref, wordPtr);
        }
        else
        {
            // we break if there are no more occurences of the word
            break;
        }
    }

    // writes the updated line in the new file
    fputs(linePtr, replaceFile);

    // freeing the memory
    free(linePtrLower);
    free(wordPtrLower);

    return count;
}

/*
    Will update the word to all caps.
*/
void updateWord(FILE *replaceFile, char *linePtr, char *wordPtr, char *ref)
{
    // getting the length of each line to find which position to modify in the line
    int small_len = strlen(ref);
    int big_len = strlen(linePtr);
    int word_len = strlen(wordPtr);
    // going over each character and changing it to upper case
    for (int i = 0; i < word_len; i++)
    {
        char to_replace = toupper(linePtr[big_len - small_len + i]);
        linePtr[big_len - small_len + i] = to_replace;
    }
}

/*
    Simply return a pointer to a lower case instance of a given string
*/
char *toLowerCase(char *strPtr)
{
    char *toReturn = malloc((strlen(strPtr) + 1) * sizeof(char) + 1);
    int i;

    for (i = 0; strPtr[i] != '\0'; i++)
    {
        toReturn[i] = tolower(strPtr[i]);
    }
    toReturn[i] = '\0';

    return toReturn;
}