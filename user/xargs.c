#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/param.h"

#define BUFF_MAX 128

int main(int argc, char *argv[]) {
  int pid, status;
  char **args = malloc(sizeof(char *) * MAXARG);
  for (int i = 1; i < argc; i++) {
    args[i - 1] = argv[i];
  }

  char *buff = malloc(BUFF_MAX);
  while (1) {
		gets(buff, BUFF_MAX);
		if (strlen(buff) == 0){
			break;
		}

		buff[strlen(buff) - 1] = 0; /* remove \n */
    args[argc - 1] = buff;

    if ((pid = fork()) > 0) {
      wait(&status);
    } else if (pid == 0) {
      exec(args[0], args);
    } else {
      fprintf(2, "fork() failed\n");
      exit(1);
    }
  }

  exit(0);
}
