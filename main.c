#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>

char ** parse_args (char * line) {
  char *s1 = calloc(strlen(line), 1);
  char ** ret = calloc(6, sizeof(char *));
  strcpy(s1, line);
  for (int i = 0; s1; i++)
    ret[i] = strsep(&s1, " ");
  return ret;
}

int main(){
  char command[50];
  while (1) {
    printf("Enter command:");
    fgets(command,50,stdin);
    int len = strlen(command);
    if (len > 0 && command[len - 1] == '\n')
      command[len - 1] = '\0';

    while(strlen(command) < 1) {
      printf("Enter command:");
      fgets(command,50,stdin);
      len = strlen(command);
      if (len > 0 && command[len - 1] == '\n')
	command[len - 1] = '\0';
    }

    char ** args = parse_args(command);
    pid_t child = fork();
    int status;
    if(!child){
      execvp(args[0], args); 
   }
    else{  
      wait(&status);
    } 
  }
  return 0;
}
