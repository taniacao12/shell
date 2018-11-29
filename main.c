#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>

char ** parse_args (char * line) {
  char ** ret = calloc(100, sizeof(char *));
  for (int i = 0; line; i++)
    ret[i] = strsep(&line, " ");
  return ret;
}

char ** parse_coms(char * line){
  char ** ret = calloc(6,sizeof(char *));
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
    int i = 0;
    char ** args = parse_args(command);
    if(!strcmp(args[0],"exit")){
      exit(0);
    }
    if(!strcmp(args[0],"cd")){
      chdir(args[1]);
    }
    pid_t child = fork();
    int status;
    if(!child){
      execvp(args[0], args); 
    }
    else{  
      wait(&status);
    }
    free(args);
    i++;
  }
  return 0;
}
