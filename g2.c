#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_RESET "\x1b[0m"
char *read_line(FILE *fp);

main(int argc, char *argv[]) 
{
	char *line;
	FILE *fp;
	int i;
	if(argc == 4)
		fp = fopen(argv[3],"r");
	if(fp) 
	{
	 	int count;
	 	count = 0;
	 	int i;
		char*state;
		state = argv[1];
		switch(*state) {
			case'o' :
				while(line = read_line(fp)) 
				{
				        char *psh = strtok(line," ");
				        int flag = 0;
				        while(psh != NULL)
				        {			    
				    		int s = strcmp(psh,argv[2]);
				    		if(flag == 1)
				    			printf("%s ",psh);
				    		if (s == 0)
				    		{
				    			flag = 1;
				    			printf(ANSI_COLOR_BLUE "%s ",psh);
				    			printf(ANSI_COLOR_RESET);
				    		}
				    		psh = strtok(NULL," ");
				    	
				       }
				}
				break;
			
			case'v' :
				while( line = read_line(fp)) 
				{
					if (strstr(line,argv[2]) == NULL) 
					{
						printf("%s\n",line);	
					}
				}
				break;
			
			case'c' :
				while( line = read_line(fp)) 
				{
					char *psh = strtok(line," ");
				        int flag = 0;
				        while(psh != NULL)
				        {			    
				    		int s = strcmp(psh,argv[2]);
				    		if(flag == 1)
				    			printf("%s ",psh);
				    		if (s == 0)
				    		{
				    			flag = 1;
				    			//printf("%s\n",line);
				    			printf(ANSI_COLOR_BLUE "%s ",psh );
				    			printf(ANSI_COLOR_RESET);
				    			count++;
				    		
				    		}
				    		psh = strtok(NULL," ");
				        }
				}
				printf("count:%d\n",count);
				break;
			
			case'f' :
				printf("%d\n",argc);
				for (i = 3; i < argc; i++) 
				{
					fp = fopen(argv[i],"r");
					while(line = read_line(fp)) 
					{
						char *psh = strtok(line," ");
				    		int flag = 0;
				    		while(psh != NULL)
				    		{			    
				    			int s = strcmp(psh,argv[2]);
				    			if(flag == 1)
				    				printf("%s ",psh);
				    			if (s == 0)
				    			{
				    				flag = 1;
				    				//printf("%s\n",line);
				    				printf(ANSI_COLOR_BLUE "%s ",psh );
				    				printf(ANSI_COLOR_RESET);
				    			}
				    			psh = strtok(NULL," ");
				        	}	
					}
					printf("next file:");
					fclose(fp);
				}
				break;
				
			case'i' :
				while(line = read_line(fp)) 
				{
					char *psh = strtok(line," ");
				        int flag = 0;
				        while(psh != NULL)
				        {			    
				    		int s = strcasecmp(psh,argv[2]);
				    		if(flag == 1)
				    			printf("%s ",psh);
				    		if (s == 0)
				    		{
				    			flag = 1;
				    			printf(ANSI_COLOR_BLUE "%s ",psh);
				    			printf(ANSI_COLOR_RESET);
				    		}
				    		psh = strtok(NULL," ");
				    	}
				}
				break;
				
			case'l' :
				printf("%d\n",argc);
				for (i = 3; i < argc; i++) 
				{
					fp = fopen(argv[i],"r");
					while(line = read_line(fp)) 
					{
						if (strstr(line,argv[2]))
						{
							printf(ANSI_COLOR_MAGENTA "%s ",argv[i]);
				    			printf(ANSI_COLOR_RESET);
						}
					}
					fclose(fp);
				}
				break;
				
			case'q' :
				printf("Quiet\n");
				break;				
			
			default :
			        break;
			}	        
	//fclose(fp);
	return 0;

}
}

char * read_line(FILE *fp)
{
    char *buffer, *t;
    int chars = 0, buffer_size = 256;
    char *line = malloc(buffer_size);
    buffer = line;
    while(fgets(buffer, buffer_size - chars, fp))
    {
	chars = strlen(line);
	if(line[chars - 1] == '\n')
	{
		line[chars - 1] = '\0';
		return line;
	}
	else
	{
		buffer_size = 2 * buffer_size;
		t = realloc(line, buffer_size);
		if(t)
		{
			line = t;
			buffer = line + chars;
		}
		else
		{
			free(line);
			return NULL;
		}

	}	
    }
    return NULL;
}  
