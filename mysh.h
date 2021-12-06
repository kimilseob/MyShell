#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<wait.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<signal.h>
#include<errno.h>

#define MAX 256


void redirection(char** commands, int i);
void pipe(char** commands, inti);
void background(char** commands, int i);
char** parsing(char* CommandLine);
void exec_command(char** command);

#define chop(str) str[strlen(str)-1] = 0x00;
