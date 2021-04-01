# Printf_Color 

## Introduction

In c, display color in terminale its not always easy while sometimes it's realy useful. So i was like "why not propose a rewrite of printf ? But a printf with colors "


## Code Samples

You've gotten their attention in the introduction, now show a few code examples. So they get a visualization and as a bonus, make them copy/paste friendly.

## Installation

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
> To have more information on dynamic library whith gcc : https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html


