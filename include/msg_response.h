#ifndef __MSG_RESPONSE__
#define __MSG_RESPONSE__

#include "utils.h"
#include "stdio.h"


#define GET 0
#define POST 1
#define HEAD 2
#define MALFORMED -1
#define RESPONSE_SIZE 4096
#define PATH_SIZE 1024
#define DATE_STAMP_SIZE 256
#define CONTENT_LENGTH_SIZE 16
#define CONTENT_TYPE_SIZE 64
#define FILE_EXTENSION_SIZE 16 
#define LAST_MODIFIED_SIZE 256
#define CONNECTION_TYPE_SIZE 32
#define HEADER_SIZE 32
#define BODY_SIZE 2048


int msg_resp(int client_sock, char* buf, int readRet);
int msgResp_400(int client_sock);
int msgResp_500(int client_sock);
int msgResp_501(int client_sock);
int msgResp_404(int client_sock);

int msgResp_ECHO(int client_sock, char* buf, int readRet);
int msgResp_GET(int client_sock, Request* request);
int msgResp_POST(int client_sock, Request* request);
int msgResp_HEAD(int client_sock, Request* request);

#endif