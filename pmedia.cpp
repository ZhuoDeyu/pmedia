#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#include "plog.h"
#include "prtsp_server.h"

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("media ip port\n");
        return -1;
    }

	PString ip = argv[1];
	int port = atoi(argv[2]);	

	PLog::Instance()->Init("media.log");

	PRtspServer* rtspServer = new PRtspServer(ip, port);
	
	rtspServer->Start();

	for (;;)
	{
		sleep(60);
	}

	PLog::Instance()->Exit();
	
	return 0;
}