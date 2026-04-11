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
    struct sockaddr_in serv_addr;
    int sockfd;
    char buff[BUFFER_SIZE];

    unsigned short serv_port = 25022;
    char serv_ip[] = "127.0.0.1";

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("CLIENT ERROR: Cannot create socket");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(serv_port);
    inet_aton(serv_ip, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("CLIENT ERROR: Cannot connect to server");
        close(sockfd);
        exit(1);
    }

    printf("\nCLIENT: Connected to server at %s:%d\n", serv_ip, serv_port);

    for (;;) {
        bzero(buff, BUFFER_SIZE);
        
        // Ensure this doesn't interfere by reading before prompt
        if (read(sockfd, buff, BUFFER_SIZE) <= 0) break;

        if (strcmp(buff, "exit") == 0) {
            printf("\nCLIENT: Server requested disconnection.\n");
            break;
        }

        // Display prompt for user input
        printf("\nCLIENT: Enter a command to execute (or 'exit' to quit): ");
        fgets(buff, BUFFER_SIZE, stdin);
        buff[strcspn(buff, "\n")] = 0; // Remove newline character

        if (strcmp(buff, "exit") == 0) {
            write(sockfd, buff, strlen(buff) + 1);
            break;
        }

        // Send command to server
        write(sockfd, buff, strlen(buff) + 1);

        // Receive and display server output
        printf("\nSERVER OUTPUT:\n");
        bzero(buff, BUFFER_SIZE);
        
        // Loop to handle output
        while (1) {
            int bytesRead = read(sockfd, buff, BUFFER_SIZE - 1);
            if (bytesRead <= 0) break;
            
            buff[bytesRead] = '\0';  // Null-terminate output
            if (strcmp(buff, "[END]") == 0) break;  // End of output
            
            printf("%s", buff);  // Print server output
        }

        printf("\n");  // Ensure the next prompt starts cleanly
    }

    printf("\nCLIENT: Disconnected from server.\n");
    close(sockfd);

    return 0;
}