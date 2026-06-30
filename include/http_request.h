
#ifndef HTTP_REQUEST

#define HTTP_REQUEST

#include <sys/types.h>
#include <stdlib.h>

typedef struct _http_request{

    // get the method used
    char * method;

    char * uri;

    char * version;
    


} http_request;



http_request * create_http_request();


http_request * parse_http_request(char * header_str);


void free_http_request(http_request * http_request);

ssize_t read_http_headers(int fd, char* userbuf,size_t cap );


int get_http_headers(char * http_request_str,char* output_buffer);







#endif
