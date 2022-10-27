#ifndef REPORT_H_
#define REPORT_H_

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

struct logger *init_logger();
struct logger *log_update(struct logger *current, char *filename, int updates);
void storeInArray(struct logger *head, struct logger *array);
int countNodes(struct logger *head);
int nodesComparator(const void *v1, const void *v2);
void sortNodesArray(struct logger *arrayPtr, int arraySize);
void displayUpdates(struct logger *arrayPtr, int arraySize);
void displaySortedLogs(struct logger *head);
void freeLoggers(struct logger *head);
int test();

#define MAX_LINE 4096
#define MAX_FILENAME 1024

#endif /* REPORT_H_ */