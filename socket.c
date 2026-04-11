#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 256

int main() {
    struct sockaddr_in serv_addr, cli_addr;
    int listenfd, connfd;
    socklen_t cli_addr_len;
    char buff[BUFFER_SIZE];

    unsigned short serv_port = 25022;
    char serv_ip[] = "127.0.0.1";

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(serv_port);
    inet_aton(serv_ip, &serv_addr.sin_addr);

    printf("\nCOMMAND SERVER STARTED.\n");

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("SERVER ERROR: Cannot create socket");
        exit(1);
    }

    if ((bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0) {
        perror("SERVER ERROR: Cannot bind");
        close(listenfd);
        exit(1);
    }

    if ((listen(listenfd, 5)) < 0) {
        perror("SERVER ERROR: Cannot listen");
        close(listenfd);
        exit(1);
    }

    cli_addr_len = sizeof(cli_addr);
    for (;;) {
        printf("\nSERVER: Waiting for client connections...Press Ctrl+C to stop\n");

        if ((connfd = accept(listenfd, (struct sockaddr*)&cli_addr, &cli_addr_len)) < 0) {
            perror("SERVER ERROR: Cannot accept connection");
            continue;
        }
        printf("\nSERVER: Connected to client at %s.\n", inet_ntoa(cli_addr.sin_addr));

        while (1) {
            printf("\nSERVER: Enter 'exit' to disconnect client: ");
            char prompt[BUFFER_SIZE];
            fgets(prompt, BUFFER_SIZE, stdin);
            prompt[strcspn(prompt, "\n")] = 0;
            write(connfd, prompt, strlen(prompt) + 1);

            if (strcmp(prompt, "exit") == 0) {
                printf("\nSERVER: Disconnected client manually.\n");
                break;
            }

            bzero(buff, BUFFER_SIZE);
            if (read(connfd, buff, BUFFER_SIZE) <= 0) {
                printf("\nSERVER: Client disconnected.\n");
                break;
            }

            if (strcmp(buff, "exit") == 0) {
                printf("\nSERVER: Client requested disconnection.\n");
                break;
            }

            printf("\nSERVER: Client sent command: %s\n", buff);

            FILE *fp = popen(buff, "r");
            if (fp == NULL) {
                strcpy(buff, "Invalid Command\n");
                write(connfd, buff, strlen(buff) + 1);
                printf("\nSERVER: Invalid Command.\n");
            } else {
                int hasOutput = 0;
                printf("\nSERVER: Command output:\n");
                while (fgets(buff, BUFFER_SIZE - 1, fp) != NULL) {  // Prevent overflow
                    printf("%s", buff);  // Print output to server console
                    write(connfd, buff, strlen(buff));  // Send without +1 to avoid unnecessary null termination
                    hasOutput = 1;
                    usleep(1000);  // Small delay to prevent loss of packets
                }
                pclose(fp);
                
                if (!hasOutput) {
                    strcpy(buff, "Invalid Command\n");
                    write(connfd, buff, strlen(buff) + 1);
                    printf("\nSERVER: Invalid Command.\n");
                }

                strcpy(buff, "[END]");
                write(connfd, buff, strlen(buff) + 1);  // End marker
            }

            printf("\nSERVER: Sent output to client.\n");
        }

        close(connfd);
    }
}