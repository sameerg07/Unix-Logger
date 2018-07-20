#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 FILE *fp;
  char path[1035];

int main( int argc, char *argv[] )
{

 
	system("xinput -test 12 >> log1.txt &");
	system("xinput -test 13 >> log1.txt &");
	while(1)
	{
		get_log("tail mouse -n 1");
		get_log("tail keyboard -n 2");
		sleep(1);
	}
  return 0;
}
	

int get_log(char* command)
{
  fp = popen(command, "r");
  if (fp == NULL) {
    printf("Failed to run command\n" );
    exit(1);
  }
  while (fgets(path, sizeof(path)-1, fp) != NULL) {
    printf("%s", path);
  }
  pclose(fp);
	fflush(stdout);
}
