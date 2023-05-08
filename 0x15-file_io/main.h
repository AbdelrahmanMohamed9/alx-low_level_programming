#ifndef MAIN_H
#define MAIN_H


#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int append_text_to_file(const char *fn, char *tx_con);
ssize_t read_textfile(const char *fn, size_t let);
int create_file(const char *fn, char *tx_con);

#endif
