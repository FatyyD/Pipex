#ifndef pipex_h
#define pipex_h 
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
// rajouter un BUFFERSIZE

/* void  child_f(int f1, char *cmd1);
void  child_s(int f2, char *cmd2);
void pipex(int f1, int f2, char *cmd1, char *cmd2);*/
int main(int ac, char **ag, char **envp);

#endif 