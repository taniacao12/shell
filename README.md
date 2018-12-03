# shell
by Tania Cao and Garvey Zhou

## Feature
  Forks and reaps the fruits of child command processes
     Works even if there are multiple chilren
  Works for selective special commands (exit,cd)
  FREE
  No correction allowed through arrowkeys
  
## Attempted
  Redirection and piping
  
## Bugs
  Not really a bug but you can only run multiple commands in the format of "ls -al;echo hi"
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
