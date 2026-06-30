#include "http_request.h"
#include "io_utils.h"




ssize_t read_http_headers(int fd, char* userbuf,size_t cap ){

    size_t bytes_processed = 0;
    


    while(bytes_processed<cap-1)
    {

        ssize_t bytes_read = read(fd,userbuf+bytes_processed,cap-bytes_processed-1);

        if(bytes_read>0){

        bytes_processed += bytes_read;

        userbuf[bytes_processed] = '\0';
        if(strstr(userbuf,"\r\n\r\n")!=NULL)
        {
            return bytes_processed;

        }
    }

        else if(bytes_read==0){
            return 0;
        }

        else {
            if(errno==EINTR){
                continue;
            }
            return -1;
        }









    
    



}
return -2;
}

http_request * create_http_request()
{
    http_request * request = malloc(sizeof(http_request));
    memset(request,0, sizeof(http_request));


    return request;




}


http_request * parse_http_request(char * http_request_string){

    // create a array of char *
    // create enough space for method uri and http version
    printf("%s",http_request_string);
    char * trimmed_http_request = trim_left(http_request_string);
    printf("%s",trimmed_http_request);
    char * string_end = strstr(trimmed_http_request,"\r\n\r\n");

    // get rid of the \r\n\r\n
    *string_end='\0';

    char ** http_request_params = malloc(sizeof(char*) *3);
    split_string(trimmed_http_request,http_request_params,' ');

    http_request * request = create_http_request();

    printf("%s\n",http_request_params[0]);

    request->method = http_request_params[0];
    request ->uri = http_request_params[1];
    request ->version = http_request_params[2];


    return request;















}

void free_http_request(http_request * http_request){



    free(http_request->method);
    free(http_request->uri);
    free(http_request->version);
    free(http_request);

}






