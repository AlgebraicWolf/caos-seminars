#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    exit(1);
  }

  long port = strtol(argv[1], NULL, 10);

  struct sockaddr_in address = {};
  address.sin_family = AF_INET;
  address.sin_port = htons(port);
  address.sin_addr.s_addr = htonl(INADDR_ANY);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  bind(sockfd, (const struct sockaddr*) &address, sizeof(address));
  listen(sockfd, SOMAXCONN);

  while(1) {
    struct sockaddr_in client_addr = {};
    socklen_t addr_len;
    int client_fd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_len);

    int has_read = 1;
    int num = 0;

    char addr_str [INET_ADDRSTRLEN] = {}; //  Buffer for string representation of address
    inet_ntop(AF_INET,
              &client_addr.sin_addr,
              addr_str,
              sizeof(addr_str)
        );

    for (int i = 0; i < 3; i++) {
      has_read = read(client_fd, &num, sizeof(num));
      if (has_read <= 0) {
        break;
      }

      printf("CLIENT: %s, RECIEVED: %d\n", addr_str, num);

      num += 1;
      write(client_fd, &num, sizeof(num));

      printf("CLIENT: %s, SENDING: %d\n\n", addr_str, num);
    }

    shutdown(client_fd, SHUT_RDWR);
    close(client_fd);
  }
}
