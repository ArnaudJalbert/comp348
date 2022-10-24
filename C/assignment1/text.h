#ifndef TEXT_H_
#define TEXT_H_

#define MAX_LINE 2048
#define MAX_FILENAME 1024

int search();
int readFile(char *pathPtr, char *wordPtr);
int findWord(FILE *replaceFile, char *linePtr, char *wordPtr);
void updateWord(FILE *replaceFile, char *linePtr, char *wordPtr, char *ref);
char *toLowerCase(char *strPtr);

#endif /* TEXT_H_ */