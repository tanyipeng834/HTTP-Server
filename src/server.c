#include <stdio.h>
#include "network.h"
#include "io_utils.h"



int main(int argc, char* argv[]){

    if(argc!=2){
        printf("Usage: ./server <port_number>");
        exit(1);

    }
    // take the first argument as the port number
    char * port_num = argv[1];
    
    int listen_fd =open_listenfd(port_num);
    printf("listeining ...\n");
    if(listen_fd<1){
        perror("Failed to listen to port");
        exit(1);
    }
    char clientbuf[MAX_HTTP_REQUEST_SIZE];
    while(1){

        int connfd = accept_connection(listen_fd);
        
        if(connfd<0){
            exit(1);
        }
        // memset the client buf to prevent garbage values
        memset(clientbuf,0,sizeof(clientbuf));

        read_http_headers(connfd,clientbuf,MAX_HTTP_REQUEST_SIZE);
        printf("%s",clientbuf);
        fflush(stdout);



        






    }




}
