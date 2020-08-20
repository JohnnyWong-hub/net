#include "client.h"
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

    int sockfd;
    struct sockaddr_in sin;
    socklen_t len = sizeof(struct sockaddr_in);
    sockfd = client_Init();

    sin.sin_family = AF_INET;
    sin.sin_port = htons(atoi(argv[2]));
    if(inet_aton(argv[1], &sin.sin_addr) < 0)
    {
        perror("inet_aton");
        exit(EXIT_FAILURE);
    }

    if(connect(sockfd, (struct sockaddr*)&sin, len)<0)
    {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    puts("-----------------------");
    puts("--- connect success ---");
    puts("-----------------------");

    usage_Print(&sin);

    return 0;
}


void usage_Print(struct sockaddr_in *sin)
{
    printf("From Server:%s  Port:%d\n", inet_ntoa(sin->sin_addr), ntohs(sin->sin_port));
}