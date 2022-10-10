#ifndef WORD_SEARCEHR_H_
#define WORD_SEARCEHR_H_

int search();
int readFile(char *pathPtr, char *wordPtr);
int findWord(FILE *replaceFile, char *linePtr, char *wordPtr);
void updateWord(FILE *replaceFile, char *linePtr, char *wordPtr, char *ref);

#endif /* WORD_SEARCEHR_H_ */