# shell
by Tania Cao and Garvey Zhou \n

## Feature
  Forks and reaps the fruits of child command processes \n
     Works even if there are multiple chilren \n
  Works for selective special commands (exit,cd) \n
  FREE  \n
  No correction allowed through arrowkeys \n
  
## Attempted
  Redirection and piping
  
## Bugs
  Not really a bug but you can only run multiple commands in the format of "ls -al;echo hi" \n
  Redirections works a bit awkwardly
 
### Functions
  ```c
int main();
char ** parse_args(char * line);
char ** parse_commands(char * line);
void commands(char ** arg);
void redirecc(char ** arg);
void run(char ** arg);
```
