
#ifndef _PORT_H_
#define _PORT_H_

#include "wilddog_config.h"
#include <stdio.h>




typedef struct {
	char type;//0:IPv4 1:IPv6
	char* ip;
	int port;
} wilddog_address_t;

int wilddog_gethostbyname(char* ipString,char* host);
int wilddog_openSocket(int* socketId);
int wilddog_closeSocket(int socketId);
int wilddog_send(int socketId,wilddog_address_t*,void* tosend,size_t tosendLength);
int wilddog_receive(int socketId,wilddog_address_t*,void* toreceive,size_t toreceiveLength);

void* wd_malloc(size_t size);
void wd_free(void*);

#endif