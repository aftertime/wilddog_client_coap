/*
 * Wilddog.h
 *
 *  Created on: 2015年3月12日
 *      Author: x
 */

#ifndef __WILDDOG_H_
#define __WILDDOG_H_
#include "wilddog_config.h"
#include "port.h"

typedef struct {
	char* queryString;
} wilddog_query_t;

typedef struct {
	char* appid;
	char* token;
	wilddog_address_t remoteAddr;
	int socketId;
	char serverIp[64];
	unsigned short msgId;

} wilddog_t;



wilddog_t* wilddog_init(char* appid, char* token);

/*
 * appid:appid
 * path:path
 * resBuffer: response buffer
 * maxLength: the max length of the buffer
 * return:
 * reallength of response
 * if <0 error
 *
 */
int wilddog_get(wilddog_t* wilddog, char* path, wilddog_query_t* query,
		char* resultBuffer, size_t max);

int wilddog_put(wilddog_t* wilddog, char* path, char* buffer, size_t length);


int wilddog_post(wilddog_t* wilddog, char* path, char* buffer, size_t length,
		char* resultBuffer, size_t max);


int wilddog_delete(wilddog_t* wilddog, char* path,char* buffer,size_t length);


int wilddog_observe(wilddog_t* wilddog, char* path, wilddog_query_t* query,
		char* resultBuffer, size_t max);

int wilddog_waitNotice(wilddog_t* wilddog, char* buffer,size_t length);


int wilddog_stopObserve(wilddog_t* wilddog);


int wilddog_destroy(wilddog_t*);

#endif /* WILDDOG_H_ */