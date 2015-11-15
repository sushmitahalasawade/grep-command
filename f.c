#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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

