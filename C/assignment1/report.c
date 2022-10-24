#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/*
    basic struct
*/
struct logger
{
    char *filename;
    int updates;
    int size;
    struct logger *next;
    struct logger *previous;
};

// returns head of linked list of loggers
struct logger *init_logger()
{
    struct logger *headPtr = malloc(sizeof(struct logger));
    headPtr->size = 1;
    headPtr->previous = NULL;
    return headPtr;
};

/*
    logs the update in the current struct and returns the next one
*/
struct logger *log_update(struct logger *current, char *filename, int updates)
{
    struct logger *nextLog = malloc(sizeof(struct logger));

    current->next = nextLog;
    nextLog->previous = current;
    nextLog->size = current->size + 1;

    current->filename = malloc(strlen(filename) * sizeof(char));
    current->filename = filename;
    current->updates = updates;

    return nextLog;
};

/*
    Start from head and traverses all logs until the end of the list
*/
void traverseFromHead()
{
}

int main()
{
    struct logger *head = init_logger();
    char *file = "placeholder";
    int updates = 5;
    struct logger *currentLog = log_update(head, file, updates);
}