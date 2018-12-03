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
// seperate one command into seperate parts
char ** parse_args (char * line) {
  char ** ret = calloc(100, sizeof(char *));
  for (int i = 0; line; i++)
    ret[i] = strsep(&line, " ");
  return ret;
}
// seperate a line into multiple commands based on :
char ** parse_coms(char * line){
  char ** ret = calloc(100, sizeof(char *));
  for (int i = 0; line; i++)
    ret[i] = strsep(&line, ";");
  return ret;  
}
// 18+ special commands that should be ran by the parent
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
}
// redirection
void redirecc(char ** line){
  int stdout_backup = dup(STDOUT_FILENO);
  int stdin_backup = dup(STDIN_FILENO);
  int mode = O_CREAT | O_WRONLY;
  char * stdout_new;
  char * stdin_new;
  int stdout_fd = stdout_backup;
  int stdin_fd = stdin_backup;
  char * args[256];
  for(int i = 0;line[i];i++){
    if(!strcmp(line[i],">")){
	stdout_new = line[i+1];
	mode |= O_TRUNC;
	stdout_fd = open(stdout_new,mode,0644);
	dup2(stdout_fd,STDOUT_FILENO);
	run(args);
	dup2(stdout_backup,STDOUT_FILENO);
	close(stdout_fd);
    }
    else if(!strcmp(line[i],">>")){
	stdout_new = line[i+1];
	mode = O_APPEND;
	stdout_fd = open(stdout_new,mode,0644);
	dup2(stdout_fd,STDOUT_FILENO);
        run(args);
        dup2(stdout_backup,STDOUT_FILENO);
	close(stdout_fd);
    }
    else if(!strcmp(line[i],"<")){
	stdin_new = line[i+1];
	stdin_fd = open(stdin_new,O_RDONLY);
	dup2(stdin_fd,STDOUT_FILENO);
	run(args);
	dup2(stdin_backup,STDIN_FILENO);
	close(stdin_fd);
    }
    else{
	    args[i+1] = line[i];
    }
  }
}

// run the command
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

