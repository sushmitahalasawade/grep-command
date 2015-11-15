#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"
char *read_line(FILE *fp);
int line_count = 0;
main(int argc, char *argv[]) 
{
	char *line;
	int linecount = 1;
	FILE *fp;
	int i;
	int count;
	count = 0;
	char state = argv[1][1];
		switch(state) {
			case'o' :
				if(argc == 4)
					fp = fopen(argv[3],"r");
				while(line = read_line(fp)) 
				{
				        char *psh = strtok(line," ");
				        int flag = 0;
				        while(psh != NULL)
				        {			    
				    		int s = strcmp(psh,argv[2]);
				    		if (s == 0)
				    		{
				    			flag = 1;
				    			printf(ANSI_COLOR_RED "%s \n",psh);
				    			printf(ANSI_COLOR_RESET);
				    		}
				    		psh = strtok(NULL," ");
				    	
				       }
				}
				break;
			case 'e' :
				if(argc == 4)
					fp = fopen(argv[3],"r");
				while(line = read_line(fp)) 
				{
					char *psh[100];
					char *string;
				        int flag = 0;
				        int i = 0, j;
				        psh[i] = strtok(line," ");
				        while(psh[i] != NULL)
				        {			    
				    		if (strcmp(psh[i],argv[2]) == 0)
				    		{
				    			flag = 1;
				    			string = psh[i];
				    		}
				    		i++;
				    		psh[i] = strtok(NULL," ");			    	
				       }
				       if(flag == 1)
				       {	
				       		for(j = 0; j < i; j++)
				       		{
				       			if(strcmp(string, psh[j]) == 0)
				       			{
				       		     		printf(ANSI_COLOR_RED "%s ",psh[j]);
				    		     		printf(ANSI_COLOR_RESET);
				    			}
				    			else
				    		     		printf("%s ",psh[j]);
				       		}
				       		printf("\n");
				       }
	
				}
				break;
				
			case 'b' :
				if(argc == 4)
					fp = fopen(argv[3],"r");
				
				while(line = read_line(fp)) 
				{
					int c = 0;
					c = strlen(line) + 1;
					char *psh[100];
					char *string;
				        int flag = 0;
				        int i = 0, j;
				        psh[i] = strtok(line," ");
				        while(psh[i] != NULL)
				        {			    
				    		if (strcmp(psh[i],argv[2]) == 0)
				    		{
				    			flag = 1;
				    			string = psh[i];
				    		}
				    		i++;
				    		psh[i] = strtok(NULL," ");			    	
				       }
				       if(flag == 1)
				       {	
				       		printf(ANSI_COLOR_GREEN "%d",line_count);
				    		printf(ANSI_COLOR_RESET);
				    		printf(ANSI_COLOR_BLUE ":");
				    		printf(ANSI_COLOR_RESET);
				    		line_count = line_count + c;
				       		for(j = 0; j < i; j++)
				       		{
				       			
				       			if(strcmp(string, psh[j]) == 0)
				       			{
				       		     		printf(ANSI_COLOR_RED "%s ",psh[j]);
				    		     		printf(ANSI_COLOR_RESET);
				    			}
				    			else
				    		     		printf("%s ",psh[j]);
				       		}
				       		printf("\n");
				       }
	
				}
				break;
				
			case 'm' :
				if(argc == 5)
					fp = fopen(argv[4],"r");
				int MAX_count;
				MAX_count = strtol(argv[2], NULL, 0);
				while(line = read_line(fp)) 
				{
					char *psh[100];
					char *string;
				        int flag = 0;
				        int i = 0, j;
				        psh[i] = strtok(line," ");
				        while(psh[i] != NULL)
				        {			    
				    		if (strcmp(psh[i],argv[3]) == 0)
				    		{
				    			flag = 1;
				    			string = psh[i];
				    		}
				    		i++;
				    		psh[i] = strtok(NULL," ");			    	
				       }
				       if(flag == 1 && MAX_count > 0)
				       {	
				       		for(j = 0; j < i; j++)
				       		{
				       			if(strcmp(string, psh[j]) == 0)
				       			{
				       		     		printf(ANSI_COLOR_RED "%s ",psh[j]);
				    		     		printf(ANSI_COLOR_RESET);
				    			}
				    			else
				    		     		printf("%s ",psh[j]);
				       		}
				       		MAX_count--;
				       		printf("\n");
				       }
	
				}
				break;
				
			case'v' :
				if(argc == 4)
					fp = fopen(argv[3],"r");
				while( line = read_line(fp)) 
				{
					if (strstr(line,argv[2]) == NULL) 
					{
						printf("%s\n",line);	
					}
				}
				break;
			
			case'c' :
				if(argc == 4)
					fp = fopen(argv[3],"r");
				while( line = read_line(fp)) 
				{
					char *psh = strtok(line," ");
				        int flag = 0;
				        while(psh != NULL)
				        {			    
				    		int s = strcmp(psh,argv[2]);
				    		if (s == 0)
				    		{
				    			flag = 1;
				    			count++;
				    		
				    		}
				    		psh = strtok(NULL," ");
				        }
				}
				printf("%d\n",count);
				break;
			
			case'h' :
				for (i = 3; i < argc; i++) 
				{
					fp = fopen(argv[i],"r");
					while(line = read_line(fp)) 
					{
						char *psh[100];
						char *string;
				        	int flag = 0;
				        	int i = 0, j;
				        	psh[i] = strtok(line," ");
				        	while(psh[i] != NULL)
				        	{			    
				    			if (strcmp(psh[i],argv[2]) == 0)
				    			{
				    				flag = 1;
				    				string = psh[i];
				    			}
				    			i++;
				    			psh[i] = strtok(NULL," ");			    	
				       		}
				      	if(flag == 1)
				        {	
				       		for(j = 0; j < i; j++)
				       		{
				       			if(strcmp(string, psh[j]) == 0)
				       			{
				       		     		printf(ANSI_COLOR_RED "%s ",psh[j]);
				    		     		printf(ANSI_COLOR_RESET);
				    			}
				    			else
				    		     		printf("%s ",psh[j]);
				       		}
						
						printf("\n");
					}
				}
				fclose(fp);
				}
				break;
			
			case'H' :
				for (i = 3; i < argc; i++) 
				{
					fp = fopen(argv[i],"r");
					while(line = read_line(fp)) 
					{
						if (strstr(line,argv[2]))
						{
							printf(ANSI_COLOR_MAGENTA "%s",argv[i]);
				    			printf(ANSI_COLOR_RESET);
				    			printf(ANSI_COLOR_BLUE ":");
				    			printf(ANSI_COLOR_RESET);
						}
						char *psh[100];
						char *string;
				        	int flag = 0;
				        	int i = 0, j;
				        	psh[i] = strtok(line," ");
				        	while(psh[i] != NULL)
				        	{			    
				    			if (strcmp(psh[i],argv[2]) == 0)
				    			{
				    				flag = 1;
				    				string = psh[i];
				    			}
				    			i++;
				    			psh[i] = strtok(NULL," ");			    	
				       		}
				      		if(flag == 1)
				        	{	
				       			for(j = 0; j < i; j++)
				       			{
				       				if(strcmp(string, psh[j]) == 0)
				       				{
				       		     			printf(ANSI_COLOR_RED "%s ",psh[j]);
				    		     			printf(ANSI_COLOR_RESET);
				    				}
				    				else
				    		     			printf("%s ",psh[j]);
				       			}
			
							printf("\n");
						}
					}
					fclose(fp);
				}
				break;
				
			case'i' :
				for (i = 3; i < argc; i++) 
				{
					fp = fopen(argv[i],"r");
					while(line = read_line(fp)) 
					{
						char *psh[100];
						char *string;
				        	int flag = 0;
				        	int i = 0, j;
				        	psh[i] = strtok(line," ");	
				        	while(psh[i] != NULL)
				        	{	
				        		int s = strcasecmp(psh[i],argv[2]);		    
				    			if (s == 0)
				    			{
				    				flag = 1;
				    				string = psh[i];
				    			}
				    			i++;
				    			psh[i] = strtok(NULL," ");
				    					    	
				       		}
				       		
				       		
				      		if(flag == 1)
				        	{
				        		for(j = 0; j < i; j++)
				       			{	
				       				
				       				if(strcmp(string, psh[j]) == 0)
				       				{
				       		     			printf(ANSI_COLOR_RED "%s ",psh[j]);
				    		     			printf(ANSI_COLOR_RESET);
				    				}
				    				else
				    		     			printf("%s ",psh[j]);
				       			}
			
							printf("\n");
						}
					}
					fclose(fp);
				}
				break;
				
			case'l' :
				for (i = 3; i < argc; i++) 
				{
					fp = fopen(argv[i],"r");
					while(line = read_line(fp)) 
					{
						if (strstr(line,argv[2]))
						{
							printf(ANSI_COLOR_MAGENTA "%s\n",argv[i]);
				    			printf(ANSI_COLOR_RESET);
						}
					}
					fclose(fp);
				}
				break;
				
			case'L' :
				for (i = 3; i < argc; i++) 
				{
					int flag = 0;
					fp = fopen(argv[i],"r");
					while(line = read_line(fp)) 
					{
						if (strstr(line,argv[2]))
						{
							flag = 1;
						}
					}
					if(flag == 0)
					{
						printf(ANSI_COLOR_MAGENTA "%s\n",argv[i]);
				    		printf(ANSI_COLOR_RESET);
					}
					fclose(fp);
				}
				break;
				
				
			case'n' :
				if(argc == 4)
					fp = fopen(argv[3],"r");
				while(line = read_line(fp)) 
				{
					char *psh[100];
					char *string;
				        int flag = 0;
				        int i = 0, j;
				        psh[i] = strtok(line," ");
				        while(psh[i] != NULL)
				        {			    
				    		if (strcmp(psh[i],argv[2]) == 0)
				    		{
				    			flag = 1;
				    			string = psh[i];
				    		}
				    		i++;
				    		psh[i] = strtok(NULL," ");			    	
				       }
				       if(flag == 1)
				       {	
				       		printf(ANSI_COLOR_GREEN "%d:",linecount);
				       		printf(ANSI_COLOR_RESET);
				       		for(j = 0; j < i; j++)
				       		{
				       			if(strcmp(string, psh[j]) == 0)
				       			{
				       		     		printf(ANSI_COLOR_RED "%s ",psh[j]);
				    		     		printf(ANSI_COLOR_RESET);
				    			}
				    			else
				    		     		printf("%s ",psh[j]);
				       		}
				       		printf("\n");
				       }
	
				       linecount++;
				}
				fclose(fp);
				break;
			
			case'T' :
				for (i = 3; i < argc; i++) 
				{
					fp = fopen(argv[i],"r");
					while(line = read_line(fp)) 
					{
						if (strstr(line,argv[2]))
						{
							printf(ANSI_COLOR_MAGENTA "%s\t",argv[i]);
				    			printf(ANSI_COLOR_RESET);
				    			printf(ANSI_COLOR_BLUE ":");
				    			printf(ANSI_COLOR_RESET);
						}
						char *psh[100];
						char *string;
				        	int flag = 0;
				        	int i = 0, j;
				        	psh[i] = strtok(line," ");
				        	while(psh[i] != NULL)
				        	{			    
				    			if (strcmp(psh[i],argv[2]) == 0)
				    			{
				    				flag = 1;
				    				string = psh[i];
				    			}
				    			i++;
				    			psh[i] = strtok(NULL," ");			    	
				       		}
				      		if(flag == 1)
				        	{	
				       			for(j = 0; j < i; j++)
				       			{
				       				if(strcmp(string, psh[j]) == 0)
				       				{
				       		     			printf(ANSI_COLOR_RED "%s ",psh[j]);
				    		     			printf(ANSI_COLOR_RESET);
				    				}
				    				else
				    		     			printf("%s ",psh[j]);
				       			}
			
							printf("\n");
						}
					}
					fclose(fp);
				}
				break;
			case'q' :
				printf("Quiet\n");
				break;				
			
			default :
				printf("Match not found");
			        break;
			}	       
	return 0;


}


