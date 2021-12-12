#include "mysh.h"

/////////////String Parsing/////////////////
////////////////////////////////////////////

char** parsing_string(char* commandLine)
{
	char **tokens;
	char *token;

	int count=0;
	commandLine[strlen(commandLine) -1] = '\0';
	tokens = malloc((sizeof(char*))*MAX);
	token = strtok(commandLine, " ");
	while(token != NULL)
	{
		tokens[count] = malloc(strlen(token)+1);
		strncpy(tokens[count],token,strlen(token)+1);
		token = strtok(NULL, " ");
		count++;
	}
	
	tokens[count] = NULL;
	return tokens;

}


//////////////execute command//////////////////

void exec_cmd(char **commands)
{
	int child_process;
	int status;
	int i=0;
	char dir[256];

	if(!strcmp(commands[0], "cd")){

		if(commands[1] == NULL){
			printf("USAGE : cd directory\n");
		}
		chdir(commands[1]);
	}
	else if(!strcmp(commands[0], "pwd")){
		getcwd(dir,MAX);
		printf("Working Directory : %s\n" ,dir);
	}

	else {
		if((child_process = fork())==0){
			while(commands[i]){
				if(!strcmp(commands[i],">")){
					redirection_cmd(commands, i);
				}
				else if(!strcmp(commands[i],"&")){
					background_cmd(commands, i);
				}
				else if(!strcmp(commands[i],"|")){
					pipe_cmd(commands,i );
				}
				i++;
			}
			if(execvp(commands[0],commands)==-1){
				printf("%s : command not found\n",commands[0]);
				exit(1);
			}
		}
		else if(child_process < 0){
			printf("fork error\n");
			exit(1);
		}

	}

}

void redirection_cmd(char** commands , int i)
{
}
void background_cmd(char** commands , int i)
{
}
void pipe_cmd(char** commands , int i)
{
}

