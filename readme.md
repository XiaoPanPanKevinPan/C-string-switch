
# C String Switch - A switch-case alternative for strings

## Keeping Going Automatically

### Demo:
Considering we want to code something like below:
```C
char ch[20];
scanf("%s", ch);
switch(string){
	case "hello":
		printf("Hi!\n");
		char name[20];
		scanf("%s", name);
		switch(name){
			case "Kevin":
				printf("Nice to meet you!\n");
			default:
				printf("But my name is \"Kevin\"!!!");
		}
	default:
		printf("Not Working\n");
	case "bye":
		printf("The end\n");
		break;
	case "err":
		printf("Error");
		goto default;
	case "sth":
		printf("What?");
}
```
... we are sure to find out it's impossible to work - things after `case` should be a constant, while a string is actually a address.
The most common way is to do it like this:
```C
if(strcmp(ch, "hello") == 0){
	//...
}else if(strcmp(ch, "bye")){
	//...
}else if(strcmp(ch, "err")){
	//...
}else{
	//...
}
```

However, obviously, a lot of if-else and repeated strcmp are indeed stressful. 
Also, reusing codes in blocks won't be easy, either. 
Thus, here comes the match-like block! It looks like below:

```C
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
```
This demo can be found in [autoKeepGoing/demo.c](autoKeepGoing/demo.c).

### Features:
- Code reusing (`thenGo()` and `thenGoOther`)
- Code reducing (needless to use `strcmp`)
- Scope safety (codes after each `like()` or `other` is actually contained by a `{ }`)

### Usage:
The first step is to `#include` this library. 
Just put [autoKeepGoing/matchLikeMacro.h](autoKeepGoing/matchLikeMacro.h) under the same directory as `main.c` or something.
Then, copy & paste this line into it:
```C
 #include "matchLikeMacro.h"
```

A match-like block looks like this:
```C
match(switchString)
	like("cmd1")
	like("cmd2")
	other
endMatch
```
It starts with `match(switchString)` and ends up with `endMatch`.

Each case started with `like(identifierString)` or `other`. A `:` must *not* be provided. 
A case will be run when the `switchString` matchs the `identifierString`, or after the cases preceding is done.

To escape the block, use `break; `. To force another case to be run, use `thenGo(identifierString); ` or `thenGoOther; `.


## Auto Break
For those who found a bunch of `break; `s are useless.

Given a code like this:
```C
char ch[20];
scanf("%s", ch);

switch(ch){
	case "hello":
		printf("Hi\n");
		break;
	case "bye":
		printf("TheEnd!\n");
		break;
	case "err":
		printf("Weird.\n");
		goto default;
		break;
	default:
		printf("notWorking!\n");
		goto case "bye";
		break;
}
```
... on top of the impossibility of compiling and running, it is tiring to remember to use `break;`.
Thus, here comes the meet-as block!

```C
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
```
Ha! Much cleaner, right?

### Features:
- Code reusing (`forceMeet()` and `forceMeetRest`)
- Code reducing (needless to use `strcmp` and `break; `)
- Scope safety (codes after each `as()` or `rest` is actually contained by a `{ }`)

### Usage: 

### Usage:
The first step is to `#include` this library. 
Just put [autoBreak/meetAs.h](autoBreak/meetAs.h) under the same directory as `main.c` or something.
Then, copy & paste this line into it:
```C
#include "meetAs.h"
```

A meet-as block looks like this:

```C
meet(switchString)
	as("cmd1")
	as("cmd2")
	other
endMeet
```
It starts with `meet(switchString)` and ends up with `endMeet`.

Each case started with `as(identifierString)` or `rest`. A `:` must *not* be provided. 
The `rest` block *must* always be at the end, right before `endMeet`.
A case will be run when the `switchString` matchs the `identifierString`, or after the cases preceding is done.

To escape the block, use `break; `. To force another case to be run, use `forceMeet(identifierString); ` or `forceMeetOther; `.
