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
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *big, const char *little, size_t len);

#endif 