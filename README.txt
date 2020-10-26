Project Description:
	This program is a simple shell that prompts an input from user and utilizes internal commands such as cd, path, and quit. The user builds a path environment and from there can attempt to run a provided executable file name if it is found in the path environment.
Compiling Instructions:
	make shell
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