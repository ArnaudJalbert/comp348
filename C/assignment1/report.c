#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "report.h"

// returns head of linked list of loggers
struct logger *init_logger()
{
    struct logger *headPtr = malloc(sizeof(struct logger));
    headPtr->size = 1;
    headPtr->previous = NULL;
    return headPtr;
};

/*
    logs the update in the current struct and returns a reference to the next node
*/
struct logger *log_update(struct logger *current, char *filename, int updates)
{
    struct logger *nextLog = malloc(sizeof(struct logger));

    current->next = nextLog;
    nextLog->previous = current;
    nextLog->size = current->size + 1;
    nextLog->next = NULL;

    current->filename = malloc(strlen(filename) * sizeof(char));
    strcpy(current->filename, filename);
    current->updates = updates;

    return nextLog;
};

/*
    Start from head and traverses all logs until the end of the list
    Stores everything in an array while doing it
*/
void storeInArray(struct logger *head, struct logger *array)
{
    struct logger *node = head;
    int counter = 0;
    while (node->next != NULL)
    {
        array[counter] = *node;
        node = node->next;
        counter++;
    }
}

/*
    Returns number of structs from the head
*/
int countNodes(struct logger *head)
{
    struct logger *node = head;
    int counter = 0;
    while (node->next != NULL)
    {
        node = node->next;
        counter++;
    }

    return counter;
}

/*
    Comparator of nodes, sorting is made so that the highest number
    of updates is put first
*/
int nodesComparator(const void *v1, const void *v2)
{
    const struct logger *p1 = (struct logger *)v1;
    const struct logger *p2 = (struct logger *)v2;
    if (p1->updates > p2->updates)
        return -1;
    else if (p1->updates < p2->updates)
        return +1;
    else
        return 0;
}

/*
    Sorts an array of nodes given the head of the array and the size
*/
void sortNodesArray(struct logger *arrayPtr, int arraySize)
{
    qsort(arrayPtr, arraySize, sizeof(struct logger), nodesComparator);
}

/*
    Prints all updates and filenames from array of struct loggers
*/
void displayUpdates(struct logger *arrayPtr, int arraySize)
{
    printf("Updates       Filename\n");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%i             %s\n", arrayPtr[i].updates, arrayPtr[i].filename);
    }
}

/*
    Displays all logs, sorted, from the head of loggers
    Frees the memory for all logs as well
*/
void displaySortedLogs(struct logger *head)
{
    // transform the linked list in array
    int arraySize = countNodes(head);
    struct logger nodesArray[arraySize];
    struct logger *nodesArrayPtr = nodesArray;
    storeInArray(head, nodesArrayPtr);

    // sorts the array
    sortNodesArray(nodesArrayPtr, arraySize);

    // displays the sorted updates
    displayUpdates(nodesArrayPtr, arraySize);

    // frees memory
    freeLoggers(head);
}

/*
    Simply frees the memory for all loggers
*/
void freeLoggers(struct logger *head)
{

    struct logger *node = head;
    while (node != NULL)
    {
        struct logger *toFree = node;
        node = node->next;
        free(toFree);
    }
}
/*
    Used to test that linked list is working properly
*/
int test()
{
    // create the logs
    struct logger *head = init_logger();
    struct logger *ex1 = log_update(head, "head", 2);
    struct logger *ex2 = log_update(ex1, "ex1", -5);
    log_update(ex2, "ex2", 3);

    displaySortedLogs(head);

    return 1;
}