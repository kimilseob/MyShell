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


void redirection_cmd(char** commands, int i);
void pipe_cmd(char** commands, int i);
void background_cmd(char** commands, int i);
char** parsing_string(char* commandLine);
void exec_cmd(char** command);

#define chop(str) str[strlen(str)-1] = 0x00;
