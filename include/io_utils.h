#ifndef IO_UTILS

#define IO_UTILS

#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>   
#include <string.h>
#define MAX_HTTP_REQUEST_SIZE 8192







char * trim_left(char* http_string);


void split_string(char * input_string, char ** input_buffer, char delimiter);












#endif

