#include "server.h"


//服务器初始化
int server_Init(const char *addr, const int port)
{
    int sockfd;
    struct sockaddr_in sin;
    socklen_t len = sizeof(struct sockaddr_in);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    if(inet_aton(addr, &sin.sin_addr)<0)
    {
        perror("inet_aton");
        exit(EXIT_FAILURE);
    }

    if(bind(sockfd, (struct sockaddr*)&sin, len)<0)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if(listen(sockfd, 10) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}