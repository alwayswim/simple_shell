#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUF_SIZE 64
extern char **environ;

/*Function for handling strings*/

char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(const char *src);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, int n);
void _puts(char *str);
int _putchar(char c);
char *_strdup(char *str);

/*Function to create a shell*/

void set_prompt(void);
char **tokenize(char *line);
int execute(char **argv, char **envp, int status);
char *get_line(void);
void signal_handling(int __attribute__((__unused__))signal);

/*Function to search environment*/

char **search_env();
char **get_dir(char *path);
int env(void);
int get_stat(char **argv, char **path);

#endif
