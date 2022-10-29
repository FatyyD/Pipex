#include <pipex.h>

char    *path(char *cmd, char **envp)
{
    char **paths_envp;
    char  *mypaths;
    char  **mycmdargs;
    int i;

    i = 0;
if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
        return(cmd);
  m
}
void    child_1(int f1, char *cmd1)
{
    int i;
    char *cmd;

    i = -1;
    dup2(f1, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    close(f1);
    while(mypaths[++i])
    {
        cmd = ft_strjoin(mypaths[i], ag[2]);
        execve(cmd, mycmddargs, envp);
        free(cmd);
    }
    exit(EXIT_FAILURE);
}

void  child_2(int f2, char *cmd2)
{
    int i;
    char *cmd;

    i = -1;
    dup2(f2, STDIN_FILENO);
    dup2(fd[0], STDOUT_FILENO);
    close(fd[1]);
    close(f2);

    while(mypaths[++i])
    {
        cmd = ft_strjoin(mypaths[i], ag[2]);
        execve(cmd, mycmddargs, envp);
        free(cmd);
    }
    exit(EXIT_FAILURE);
}

void pipex(int f1, int f2, char *cmd1, char *cmd 2)
{
    int fd[2];
    int status;
    pid_t c1;
    pid_t c2;

    pipe(fd);
    c1 = fork();
    if (c1 < 0)
        return (perror("fork: "));
    if (c1 == 0)
        child_1(f1, cmd1);
        c2 = fork();
    if (c2 < 0)
        return (perror("fork: "));
    if(c2 == 0)
    child_2(f2, cmd2);
    close(fd[0]);
    close(fd[1]);
    waitpid(c1, &status, 0);
    waitpid(c2, &status, 0);

}

int main(int ac, char **av, char **envp)
{
    int f1;
    int f2;

    f1 = open(ag[1], O_RDONLY);
    f2 = open(ag[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (f1 < 0 || f2 < 0)
        return (-1);
        pipex(f1, f2, ag, envp);
        return(0);
}
/*int main(int a, int *argv, char **argc)
{
    int fd[2];
    pid_t c1;
    pid_t c2;
    int status;
    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    c1 = fork();
     if (c1 == 0)
     {
        close(fd[1]);
     }
     else
     {
        close(fd[0]);
     }
     waitpid(c1, status, 0);
     waitpid(c2, &status, 0);
    
}*/