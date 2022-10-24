#ifndef REPORT_H_
#define REPORT_H_

struct logger *init_logger();
struct logger *log_update(struct logger *current, char *filename, int updates);

#define MAX_LINE 2048
#define MAX_FILENAME 1024

#endif /* REPORT_H_ */