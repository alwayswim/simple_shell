#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
/*global variable*/

extern char **environ;

/*Function for handling strings*/

char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void _puts(char *str);
int _putchar(char c);
char *_strdup(char *str);
int _strlen(char *src);
int _strncmp(char *s1, char *s2, int n);

/*Function to create a shell*/

void set_prompt(void);
int execute(char **argv, char **envp, int status);
char *get_line(void);
void signal_handling(int __attribute__((__unused__))signal);
char **tokenize(char *line);

/*Function to search environment*/

int get_stat(char **argv, char **path);
int env_fun(void);
char **get_env(char *name);

#endif
