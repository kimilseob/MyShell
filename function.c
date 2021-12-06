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
		tokens[count] = malloc(strlne(token)+1);
		strncpy(tokens[count],token,strlen(token)+1);
		token = strtok(null, " ");
		count++;
	}
	
	tokens[count] = null;
	return tokens;

}


//////////////execute command//////////////////

void execute_command(char **commands)
{
	int child_process;
	int status;
	int i=0;
	char *dir;

	if(!strcmp(commands[0], "cd")){

		if(commands[1] == NULL){
			printf("USAGE : cd directory\n");
		}
		chdir(commands[1]);
	}
	else if(!strcmp(commands[0], "pwd")){
		printf("Working Directory : %s\n" , getcwd(dir,MAX));
	}

	else {
		if((child_process = fork())==0){
			//
		}



	}



}
