#include "utils.h"
#include "msg_response.h"



void get_dateStamp(char *date_stamp){

    time_t sys_time_;
    struct tm * timeinfo;

    time(&sys_time_);
    timeinfo = localtime(&sys_time_);
    strftime(date_stamp, DATE_STAMP_SIZE, "%a, %d %b %Y %H:%M:%S %Z", timeinfo);

}

void get_contentLength(char* content_length, const char* filePath){
    struct stat state;
    stat(filePath, &state);
    sprintf(content_length, "%lld", state.st_size);

}

void get_contentType(char* content_type, const char* filePath){
    char fileExtension[FILE_EXTENSION_SIZE];
    get_fileExtension(fileExtension, filePath);

    if (!strcmp(fileExtension, "html")) strcpy(content_type, "text/html");
    else if (!strcmp(fileExtension, "gif")) strcpy(content_type, "image/gif");
    else if (!strcmp(fileExtension, "jpeg")) strcpy(content_type, "image/jpeg");
    else if (!strcmp(fileExtension, "css")) strcpy(content_type, "text/css");
    else if (!strcmp(fileExtension, "png")) strcpy(content_type, "image/png");
    else strcpy(content_type, "application/octet-stream");

}

void get_fileExtension(char* fileExtention, const char *filePath){
    int filePathLen = strlen(filePath);
    int cnt = filePathLen - 1;

    while(cnt + 1){
        int tmp_index = filePathLen - 1;
        if(filePath[cnt] == '.'){
            strncpy(fileExtention, filePath + (filePathLen - tmp_index) + 1, tmp_index - 1);
            return;
        }
        cnt --;
    }
}

void get_lastModified(char* last_modified, const char* filePath){
    struct stat st;
    struct tm *curr_gmt_time = NULL;
    stat(filePath, &st);
    curr_gmt_time = gmtime(&st.st_mtime);
    strftime(last_modified, LAST_MODIFIED_SIZE, "%a, %d %b %Y %H:%M:%S %Z", curr_gmt_time);
    
}

void get_connectionType(char* connection_type, Request * request){
    char header[HEADER_SIZE];
    strcpy(header, "Connection");
    for (int i = 0; i < request->header_count; i++)
        if (!strcmp(request->headers[i].header_name, header))
        {
            strcpy(connection_type, request->headers[i].header_value);
            return;
        }
}