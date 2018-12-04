#ifndef SHELL_H
#define SHELL_H
char ** parse_args(char * line);
char ** parse_coms(char * line);
void commands(char ** arg);
int redirecc(char ** arg);
int piping(char ** arg);
void run(char ** arg);
#endif
