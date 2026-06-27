#include <stdio.h>
#include "network.h"




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

    while(1){

        int accept_status = accept_connection(listen_fd);
        
        if(accept_status<0){
            exit(1);
        }




    }




}
