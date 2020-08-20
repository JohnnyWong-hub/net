#include "server.h"
#include <string.h>
#include <strings.h>

void usage_Print(struct sockaddr_in *sin);

int main(int argc, char const *argv[])
{
    if(argc < 3)
    {
        printf("Error Usage\n");
        exit(EXIT_FAILURE);
    }

    int sockfd,newfd;
    struct sockaddr_in cin;
    socklen_t len = sizeof(struct sockaddr_in);
    sockfd = server_Init(argv[1], atoi(argv[2])); 
    puts("----------------------");
    puts("---- 网络初始化成功 ----");
    puts("----------------------");
    
    newfd = accept(sockfd, (struct sockaddr*)&cin, &len);
    if(accept < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    usage_Print(&cin);

    return 0;
}

void usage_Print(struct sockaddr_in *sin)
{
    printf("From client:%s  Port:%d\n", inet_ntoa(sin->sin_addr), ntohs(sin->sin_port));
}