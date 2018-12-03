#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include "shell.h"

char ** parse_args (char * line) {
  char ** ret = calloc(100, sizeof(char *));
  for (int i = 0; line; i++)
    ret[i] = strsep(&line, " ");
  return ret;
}

char ** parse_coms(char * line){
  char ** ret = calloc(100, sizeof(char *));
  for (int i = 0; line; i++)
    ret[i] = strsep(&line, ";");
  return ret;  
}

void commands(char ** arg){
  if(!strcmp(arg[0],"exit")){
    exit(0);
  }
  if(!strcmp(arg[0],"cd")){
    if(chdir(arg[1]) < 0){
      printf("Directory does not exist \n");
    }
    else{
      chdir(arg[1]);
    }
  }
  if(!strcmp(arg[1],">") < 0){
      printf("hi");
  }
}

void run(char ** arg){
  pid_t child = fork();
  int status;
  if(!child){
    if(execvp(arg[0], arg) < 0){
    	exit(0);
	}
  }
  else{  
    wait(&status);
  }
}

