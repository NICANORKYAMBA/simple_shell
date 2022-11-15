#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* dealing with strings */
char *_strncpy(char *dest, char *src, int len);
unsigned int _strlen(char *str);
int _strcmp(char *s1, char *s2);
unsigned int _conststrlen(const char *str);
char *_conststrncpy(char *dest, const char *src, int len);

/* paths and environments */
unsigned int num_dir(char *path);
char **pathptr(char *cmd1, char **env_var);
void _path(char **commands, char *buf, char **env, char **argv, int counter);
char *_cpycmd(char *dest, char *src, char *cmd, int len, int size);
char *_getenv_var(const char *name, char **env_var);
void envp_print(char **env_var);
void end_of_file(char *buf);
int _geterror(char c);
void msg(char **av, char *cmd1, int counter);
void fork_handler(void);
void ext(char **commands, char *buf, char **env, char **argv, int counter);
char **string_strtok(char *str);
unsigned int numcmd(char *str);

/* freememory */
void freebufend(char *buf, char **commands, char **env);
void prnt(char *buf, char **commands);
void freebuf(char *buf);
void free_all(char *buf, char **commands);
void freecmdbuf(char *buf, char **cmd);
void freeptr(char *buf, char **cmd);
void freeEverything(char **ptr);

#endif /* _SHELL_H_ */
