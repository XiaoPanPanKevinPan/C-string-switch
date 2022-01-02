#include <stdio.h>
#include <stdlib.h>

#include "meetAs.h"

int main(){
	char ch[20];
	scanf("%s", ch);

	meet(ch)
		as("hello")
			printf("Hi\n");
		as("bye")
			printf("TheEnd!\n");
		as("err")
			printf("Weird.\n");
			forceMeetRest;
		rest
			printf("notWorking!\n");
			forceMeet("bye");
	endMeet
}
