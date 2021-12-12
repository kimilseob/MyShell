#include "mysh.h"

int main()
{
	printf("-----------------------------------\n");
	printf("ilseob's Shell\n");
	printf("-----------------------------------\n");
	printf("QUIT : quit\n");
	printf("-----------------------------------\n");
	
	char commandLine[MAX]={0};
        char **command;
        int errno;
	
	while(1)
	{
		printf("$ ");
		fgets(commandLine, 255, stdin);
		command = parsing_string(commandLine);
	
		if(strncmp(commandLine, "quit" , 4) == 0)
		{	
			exit(0);	
		}
		else
		{
			exec_cmd(command);
		}
	}
}
