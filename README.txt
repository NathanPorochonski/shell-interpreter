Project Description:
	This program is a simple shell that prompts an input from user and utilizes internal commands such as cd, path, and quit. The user builds a path environment and from there can attempt to run a provided executable file name if it is found in the path environment. A simple "hello world" executable is included as a sample under the filename "Hello".

Use the "path" command to display the current path environment. To add a path use "path + [path name]" and to remove one use "path - [path name]". Use "cd [directory name]" to change directories. Type the name of the executable to run it. The path of the executable must be included in the path environment to run it.
	
Sample Test Run:
	$ path + /bin/

	$ ls
	main    processPath.c  runExec.c
	main.c  processPath.h  runExec.h

	$ path - /bin/

	$ path


	$ path + /bin/sbin/

	$ path
	/bin/sbin/

	$ cd ..
	Directory changed to /home/runner

	$ cd
	Error: Directory not found

	$ quit
	exit status 1
