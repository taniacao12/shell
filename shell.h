#ifndef SHELL_H
#define SHELL_H
char ** parse_args(char * line);
char ** parse_coms(char * line);
void commands(char ** arg);
void redirecc(char ** arg);
void run(char ** arg);
#endif
