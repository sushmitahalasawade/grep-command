				IMPLEMENTATION OF LINUX COMMAND - GREP
NAME: Sushmita Prafull Halasawade
MIS ID: 111408059

	The project(grep command) searches the named input files for lines containing a match to the given pattern(whole word)and When it findsa match in a line, it copies the line to standard output (by default), or produces whatever
other sort of output you have requested with options.where the input files are given as a command line arguement.

SYNOPSIS: 
	./project [OPTIONS] pattern [file...]

OPTIONS:
'-e'
	print the whole line with pattern as highlighted. 

'-o' 
	print the only matching pattern.
	
'-v'
	print lines which doesnt contain given pattern.
	
'-c'
	print the count of matching pattern in file
	 				
'-n'
	print the line no where the matching pattern exists

'-b'
	print the bytes of line where the matching pattern exists.
	
'-m'
	print the maximum no of pattern given as a command line argument and stop reading after num matching lines.
	
'-h' ,'-H'
	 search for the pattern in no of files and prit the lines. in case of H case the resp file name is also printed
	
'-i'
	search for the cpattern case insensitivly and print matching lines
	
'-T'
	it printsthe lines in proper alignment

'-l'
	print the file name which contain the pattern

'-L'
	print the file name which doesnt contains the given pattern.
	
