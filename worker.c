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
   int p_to_c = open("first", O_RDONLY);
   int c_to_p = open("two", O_WRONLY);

   while (1) {
     char parentInput[100];
     //reads input and modifies
     read(p_to_c, parentInput, sizeof(parentInput));
     //closes off
     parentInput[strlen(parentInput)-1] = '\0';
     //modifies
     strcat(parentInput, "manipulated");
     //closes off
     parentInput[strlen(parentInput)] = '\0';

     //writes input and sends back to parent
     write(c_to_p, parentInput, strlen(parentInput)+1);
  }
}
