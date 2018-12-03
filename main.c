#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "shell.h"

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
    char ** coms = parse_coms(command);
    for(int i = 0; coms[i];i++){
      char ** args = parse_args(coms[i]);
      redirecc(args);
      commands(args);
      run(args);
    }
  }
  return 0;
}
