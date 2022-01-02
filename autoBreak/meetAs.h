#include <stdbool.h>
#include <string.h>


/*	`while(){}` or `do{}while();` makes `break` possible */
/*	the loop goes twice, and `other` runs at 2nd time,
 *	so it will try to compare anything until nothing matches,
 *	and then run the block for exception
 */

#define meet(sth)		{	char *_____toMeet = sth; bool _____meetRest = false;\
							while(true){\
								if(false){

#define as(a)					}else if(strcmp(a, _____toMeet) == 0 && !_____meetRest){

#define rest					}else{\
									_____meetRest = false;

#define forceMeet(sth)				_____toMeet = sth; continue
#define forceMeetRest				_____meetRest = true; continue

#define endMeet					}\
								break;\
							}\
						}
