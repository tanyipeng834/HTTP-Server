#include "io_utils.h"



char * trim_left(char * http_string){
    int i =0;
    while(http_string[i]==' '){
        http_string+=1;
        i+=1;
    }
    return http_string;
    
    
}

void split_string(char * input_string, char ** input_buffer, char delimiter ){



    char * new_string = input_string;
    size_t new_string_count =0;
    size_t str_len = strlen(input_string);
   for(unsigned int i =0;i<=str_len;i++){
    // the other or condition is for the other case for the last string split
    
    if(input_string[i]==delimiter || input_string[i] =='\0'){
        input_string[i]='\0';
        
        input_buffer[new_string_count] = strdup(new_string);
        new_string = input_string+i+1;
        new_string_count +=1;
    }


   }






}


// get 


