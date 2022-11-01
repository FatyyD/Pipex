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
    while(paths_envp[++i])
    {
        mypaths = ft_strjoin(paths_envp[i], "/"); 
        mycmdargs = ft_strjoin(mypaths, cmd);
        free(mypaths);
        if(!access(mycmdargs, F_OK))
        {
            free_s(paths_envp);
           return(mycmdargs);
        }
        free (mycmdargs);
    }
        //free_s(mypaths);
        return(0);
}

void    child_f(int *fd, char **av, char **envp)
{
    char **cmd;
    int f1;
    char *p;
    f1 = open(av[1], O_RDONLY);
        if(fd[0] < 0)
            msg_erreur(av[1]);
    dup2(f1, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    close(f1);
    cmd = ft_split(av[2], ' ');
    p = path(cmd[0], envp);
    if (!cmd)
    {
        free_s(cmd);
        erreur();
        exit(1);
    }
    execve(p, cmd, envp);
    /*if (cmd && path(cmd[0], envp))
    {
        execve(path(cmd[0], envp), cmd, envp);
        free_s(cmd);
    }
    exit(EXIT_FAILURE);*/
}

void  child_s(int *fd, char **av, char **envp)
{
    char **cmd;
     int f2;
    char *p;
    f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
       if (fd[1] < 0)
            msg_erreur(av[4]);
    dup2(f2, STDIN_FILENO);
    dup2(fd[0], STDOUT_FILENO);
    close(fd[1]);
    close(f2);
     cmd = ft_split(av[3], ' ');
      p = path(cmd[0], envp);
    if (!cmd)
    {
        free_s(cmd);
        erreur();
        exit(1);
    }
    execve(p, cmd, envp);
   /* f (cmd && path(cmd[0], envp))
    {
        execve(path(cmd[0], envp), cmd, envp);
        free_s(cmd);
    }
    exit(EXIT_FAILURE);
    if (cmd )
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
    
    if (ac != 5)
        erreur();
    if (pipe(fd) < 0)
           msg_erreur(NULL);
    c1 = fork();
    if (c1 < 0)
        msg_erreur("fork");
    if (c1 == 0)
        child_f(fd, av, envp);
    c2 = fork();
    if (c2 < 0)
         msg_erreur("fork");
    if(c2 == 0)
    child_s(fd, av, envp);
    close(fd[0]);
    close(fd[1]);
    waitpid(-1, &status, 0);
    waitpid(-1, &status, 0);
    //free parent;
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