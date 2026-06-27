#ifndef NETWORK_H

#define NETWORK_H

// include networking libraries for POSIX/C
#define LISTENQ 1024    
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include<arpa/inet.h>
#include <stdlib.h>

// this function is used to open a listening file descriptor

int open_listenfd(char * port);

int accept_connection(int listenfd);



#endif
