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
