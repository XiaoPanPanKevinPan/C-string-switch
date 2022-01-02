
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*	`while(){}` or `do{}while();` makes `break` possible */
/*	the loop goes twice, and `other` runs at 2nd time,
 *	so it will try to compare anything until nothing matches,
 *	and then run the block for exception
 */

#define match(sth)		{	char *_____toMatch = sth;\
							while(true){\
								static bool _____keepGoing = false, _____haveMatched = false, _____first = true; \
								{\
									{

#define like(a)						}\
								}if(_____keepGoing || (_____first && strcmp(_____toMatch, a)==0)){\
									_____keepGoing = true; _____haveMatched = true; {

#define other						}\
								}if(!_____first || _____keepGoing){\
									_____keepGoing = true;\
									{

#define thenGo(sth)						_____toMatch = sth; _____keepGoing = false; continue
#define thenGoOther						_____first = false; _____keepGoing = false; continue

#define endMatch					}\
								}if(_____first && !_____haveMatched){\
									_____first = false;\
								}else{\
									break;\
								}\
							}\
						}
