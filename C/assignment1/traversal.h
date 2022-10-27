#include "report.h"

#ifndef TRAVERSAL_H_
#define TRAVERSAL_H_

#define MAX_LINE 4096
#define MAX_FILENAME 1024

struct logger *traversal(char *dir, char *word, struct logger *logging);

#endif /* TRAVERSAL_H_ */