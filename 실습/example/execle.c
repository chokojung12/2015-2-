#include <stdio.h>
#include <unistd.h>

int main()
{
   char *envp[]   = { NULL};

   execle( "/bin/ls", "ls", envp);
}
