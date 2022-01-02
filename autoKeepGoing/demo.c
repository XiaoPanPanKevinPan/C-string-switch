#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "matchLikeMacro.h" 

int main(){
	char ch[20];
	scanf("%s", ch);
	match(ch)
		like("hello")
			printf("Hi\n");
			char name[20];
			scanf("%s", name);
			match(name)
				like("Kevin")
					printf("Nice to meet you!\n");
					break;
				other
					printf("But my name is Kevin!\n");
			endMatch
			thenGo("bye");
		other
			printf("Not working\n");
		like("bye")
			printf("The end\n");
			break;
		like("err")
			printf("Error\n");
			thenGoOther;
		like("sth")
			printf("What?\n");
	endMatch
}
