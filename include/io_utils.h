#ifndef IO_UTILS

#define IO_UTILS

#include <stddef.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>   
#include <string.h>
#define MAX_HTTP_REQUEST_SIZE 8192


ssize_t read_http_headers(int fd, char* userbuf,size_t cap );






#endif

