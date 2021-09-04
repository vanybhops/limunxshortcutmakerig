#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    char username[LOGIN_NAME_MAX];
    int x;
    x=getlogin_r(username, LOGIN_NAME_MAX);
    if (!(argc>2))
    {
        printf("Usage is \"./shortcutmaker (file path),(name of desired shortcut) \" ");
    }
    else
    {
        char *command=(char*)malloc(13 * sizeof(char));;
        sprintf(command,"sudo ln -s /home/%s/%s /usr/bin/%s",username,argv[1],argv[2]);
        system(command);
    }
    return 0;
}
