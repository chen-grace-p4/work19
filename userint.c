#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/shm.h>

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>

#include <sys/stat.h>

#define READ 0
#define WRITE 1

int main() {
   mkfifo("first", 0644);
   mkfifo("second", 0644);

   int p_to_c = open("first", O_WRONLY);
   int c_to_p = open("two", O_RDONLY);

   while (1) {
     printf("enter an input: ");
     char input[100];
     fgets(input, 100, stdin);
     //writes input
     write(p_to_c, input, sizeof(input));

     //reads response from child
     char line[100];
     read(c_to_p, line, sizeof(line));

     printf("response from child: %s\n", line);
  }
}
