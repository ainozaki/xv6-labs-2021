#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
	if (argc < 2){
		printf("usage: %s <time>\n", argv[0]);
		exit(1);
	}

	int time = atoi(argv[1]);
	if (sleep(time) != 0){
		exit(1);
	}
  exit(0);
}
