#include "network.h"


int open_listenfd(char* port){
    // create an addinfo struct hints
    struct addrinfo hints ,*list_p , *p;
    int listenfd,optvalue=1;
    memset(&hints,0,sizeof(struct addrinfo));
    // open a tcp stream
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_family=AF_INET;
    //
    hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG | AI_NUMERICSERV;

    getaddrinfo(NULL,port,&hints,&list_p);

    // iterate through the sa structs to create a socket() sockfd then bind() to associate the ai_addr with it then listen to get
    // a listen fd
    // use a for loop to go through the sock structs
    for(p=list_p;p!=NULL;p=p->ai_next){

        // create the socket fd

        if((listenfd=socket(p->ai_family,p->ai_socktype,p->ai_protocol))<0)continue;


        // prevents the socket already in use error when binding the socket later

        setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,(const void * )&optvalue,sizeof(int));
        // p->ai_addr is the socketaddr struct
        if(bind(listenfd,p->ai_addr,p->ai_addrlen)==0)break;

        

        

        // close the listening fd and try the other other socket ips
        close(listenfd);


    }
     if(!p)return -1;
    
    struct sockaddr_in* sock_addr = (struct sockaddr_in*) p->ai_addr;
    
    
    char strbuf [INET_ADDRSTRLEN];
    inet_ntop(AF_INET,&sock_addr->sin_addr,strbuf,sizeof(strbuf));
    printf("%s\n",strbuf);


    freeaddrinfo(list_p);
    // there is no address that worked
   

    
    if(listen(listenfd,LISTENQ)<0){
        // close listen fd as it failed to convert the active socket fd to listen fd.
        close(listenfd);
        return -1;
    }


    return listenfd;




}

int accept_connection(int listenfd){
char strbuf[INET_ADDRSTRLEN];
struct sockaddr_in client_connection;

socklen_t client_len = sizeof(struct sockaddr_in);
memset(&client_connection,0,sizeof(struct sockaddr_in));
int connfd = accept(listenfd,(struct sockaddr *) &client_connection,&client_len);




if(connfd<0){
    perror("Accept() has failed");
    return -1;
}




inet_ntop(AF_INET,&(client_connection.sin_addr),strbuf,sizeof(strbuf));

printf("Client Ip Addr: %s\n",strbuf);




return connfd;
    



}



