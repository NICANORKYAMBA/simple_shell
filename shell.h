<<<<<<< HEAD
#ifndef _SHELL_H_
#define _SHELL_H_

/**environ var */

extern char **environ;

/** MACROS */

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

/** string function */
char *_strtok(char *str, const char *tok);
unsigned int check_delim(char c, const char *str);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);

/** memory management */
void free_env(char **env);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **input, char *line);

/** input function */
void prompt(void);
void signal_to_handel(int sig);
char *_getline(void);

/** command parser and extractor */
int path_cmd(char **line);
char *_getenv(char *name);
char **parse_cmd(char *cmd);
int handle_builtin(char **cmd, int er);
void read_file(char *filename, char **argv);
char *build(char *token, char *value);
int check_builtin(char **cmd);
void creat_envi(char **envi);
int check_cmd(char **tokens, char *line, int count, char **argv);
void treat_file(char *line, int counter, FILE *fd, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);

/** bul func */
void hashtag_handle(char *buff);
int history(char *input);
int history_dis(char **cmd, int er);
int dis_env(char **cmd, int er);
int change_dir(char **cmd, int er);
int display_help(char **cmd, int er);
int echo_bul(char **cmd, int er);
void  exit_bul(char **cmd, char *input, char **argv, int c);
int print_echo(char **cmd);

/** error handle and Printer */
void print_number(unsigned int n);
void print_number_in(int n);
void print_error(char *line, int c, char **argv);
void _prerror(char **argv, int c, char **cmd);


/**
 * struct bulltin - contain bultin to handle and function to excute
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 */

typedef struct  bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;
=======
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
>>>>>>> a2161ae5dc1e2a09a828b7f7ea2363141f1a8904

#endif /* _SHELL_H_ */
