# Printf_Color 

## Introduction

In c, display color in terminale its not always easy while sometimes it's realy useful. So I was like "why not propose a rewrite of printf ? But a printf with colors "


## Usage 

### Initialization

First step is call initFormatting to initialize the setup of printf_color.
```c
initFormatting();
```

### Color 
There are 8 colors available. 
* BLACK
* RED
* GREEN
* YELLOW
* BLUE
* PURPLE
* CYAN
* WHILE


### Printf_color

Then the printf_color has the same usage as printf. The argument processing is exactly the same. 
```
printf_color("Hello World\n");
printf_color("Hello %s","John");
printf_color("%d / %d",10,20);
```
### Font Color

You can change the font color with setFontColor.
```c
setFontColor(RED);
setFontColor(BLUE);
```
### Background 

You can activate the background with enableBackground
```c
enableBackground(true); // to activate 
enableBackground(false); // to desactivate
```
> If you don't want to use stdbool library : true = 1 / false = 0

You can change the background color with setFontColor.
```c
setBackgroundColor(GREEN);
setBackgroundColor(YELLOW);
```
### Underline 

You can activate underline with enableUnderline
```c
enableUnderline(true); // to activate 
enableUnderline(false); // to desactivate
```
> If you don't want to use stdbool library : true = 1 / false = 0

### Limitation 

If you have a string argument that contains \n the background, the line after \n might have a problem. 
So avoid string argument with \n.

## Compilation

The compilation is basic. You have 3 solutions : 

### Compile with just .o file :
```bash
gcc -c printfcolor.c
gcc main.c prinfcolor.o -o exe
```
### Static library

##### Build static library :
```bash
gcc -c printfcolor.c
ar rcs libprintfcolor.a printfcolor.o
```
##### Use static library (.a) : 
```bash
gcc main.c -o exe -lprintfcolor -Ldir
```
> dir is the directory of the library (libprintfcolor.a)

### Dynammic library
##### Build dynamic library :
```bash
gcc -shared -o printfcolor.so -fPIC printfcolor.c
```

##### Use static library (.so) : 

###### LD_LIBRARY_PATH

```bash
gcc main.c -o exe -lprintfcolor -Ldir
```

>dir is the directory of the library (libprintfcolor.so)

>Don't forget to add dir at LD_LIBRARY_PATH
> export LD_LIBRARY_PATH=/path/to/dir:$LD_LIBRARY_PATH

###### Rpath

```bash
gcc -Ldir -Wl,-rpath dir -o exe main.c -lprintfcolor
```
> dir is the directory of the library (libprintfcolor.so)
>
> To have more information on dynamic library whith gcc : https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html


