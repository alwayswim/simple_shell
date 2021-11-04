#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>

extern char **environ;

/*Function for handling strings*/

char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(const char *src);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, int n);
void _puts(char *str);
int _putchar(char c);

/*Function to create a shell*/

void set_prompt(void);
char **tokenize(char *line);
int execute(char **argv, char **envp);
/*Function to search environment*/

char **search_env(const char *name);
char *get_dir(char **av);
int env(void);

#endif
