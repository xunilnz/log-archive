#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

char buffer[128];

int main(int argc,char* argv[])
{
	printf("\e[1;1H\e[2J"); // Clears the terminal window. 
	printf("log-archive v1.0.1 by ZL4KJ\n\n");
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	DIR *d;
	struct dirent *dir;
	if(argc==2)
	{
		char* path = argv[1];
		char* path2 = argv[2];
		d = opendir(path);
		if (d) 
		{
			closedir(d);
			printf("Archiving directory %s\n\n",path);
			snprintf(buffer, sizeof(buffer), "tar -cf logs_archive_%d%02d%02d_%02d%02d%02d.tar.gz %s/", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, path);
			system(buffer);
		}
		else if (ENOENT == errno)
		{
			printf("Sorry, %s does not exist\n\n", path);
		}
			return(0);
		}
		else
		{
			printf("error: no directory passed\n\nPlease use the following syntax:\n\nlog-archive </directory/to/archive>\n\n");
			return 1;
		}
}


