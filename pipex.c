#include "pipex.h"

char **line_paths(char **envp)
{
    char **paths_envp;
    int i;

    i = 0;
    while(!ft_strnstr(envp[i],"PATH", 4))
            i++;
    paths_envp = ft_split((envp[i] + 5), ':' );       
    return (paths_envp);
}
char    *path(char *cmd, char **envp)
{
    char **paths_envp;
    char  *mypaths;
    char  *mycmdargs;
    int i;

    i = 0;
   if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
        return(cmd);
   paths_envp = line_paths(envp);  
   //mypaths = ft_split(paths_envp, ':');
  // mycmdargs = ft_split(av[2], ' ');
   i = -1;

    while(mypaths[++i])
    {
        mypaths = ft_strjoin(paths_envp[i], "/"); 
        mycmdargs = ft_strjoin(mypaths, cmd);
        free(paths_envp);
        if(!access(path, F_OK))
        {
        free(paths_envp);
         return(mycmdargs);
        }
    }
        exit(EXIT_FAILURE);
}

void    child_f(int *fd, char **av, char **envp)
{
    char **cmd;

    dup2(fd[1], STDIN_FILENO);
    dup2(fd[0], STDOUT_FILENO);
    close(fd[1]);
    close(fd[0]);
    cmd = ft_split(av[2], ' ');
    if (cmd && path(cmd[0], envp))
    {
        execve(path(cmd[0], envp), cmd, envp);
        perror("Error");
        free(cmd);
    }
    exit(EXIT_FAILURE);
}

void  child_s(int *fd, char **av, char **envp)
{
    char **cmd;

    dup2(fd[0], STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    close(fd[1]);
     cmd = ft_split(av[3], ' ');
    if (cmd && path(cmd[0], envp))
    {
        execve(path(cmd[0], envp), cmd, envp);
        perror("Error");
        free(cmd);
    }
    exit(EXIT_FAILURE);
    /*if (cmd )
        cmd = ft_strjoin(mypaths[i], ag[2]);
        execve(cmd, path, envp);
        free(cmd);
    }
    exit(EXIT_FAILURE);*/
}

int  main(int ac, char **av,  char **envp)
{
    int fd[2];
    int status;
    pid_t c1;
    pid_t c2;

    pipe(fd);
    c1 = fork();
    if (c1 < 0)
        return (0);
    if (c1 == 0)
        child_f(fd, av, envp);
    c2 = fork();
    if (c2 < 0)
        return (0);
    if(c2 == 0)
    child_s(fd, av, envp);
    close(fd[0]);
    close(fd[1]);
    waitpid(c1, &status, 0);
    waitpid(c2, &status, 0);
 return (0);
}

/*int main(int ac, char **ag, char **envp)
{
    int f1;
    int f2;
    
     if (ag != 5)
           return ();
    f1 = open(ag[1], O_RDONLY);
    f2 = open(ag[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (f1 < 0 || f2 < 0)
        return (-1);
    pipex(f1, f2, ag, envp);
    return(0);
}*/
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