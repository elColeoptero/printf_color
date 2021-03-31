# Printf_Color 

## Introduction

> In c, display color in terminale its not always easy while sometimes it's realy useful. So i was like "why not propose a rewrite of printf ? But a printf with colors "


## Code Samples

> You've gotten their attention in the introduction, now show a few code examples. So they get a visualization and as a bonus, make them copy/paste friendly.

## Installation

> The compilation is basic. 

> Compile with just .o file :
>>`gcc -c printfcolor.c`

>>`gcc main.c prinfcolor.o -o exe`

> ##Static library

> Make static library :
>>`gcc -c printfcolor.c`

>>`ar rcs libprintfcolor.a printfcolor.o`

> To use static library (.a) : 
>> `gcc main.c -o exe -lprintfcolor -Ldir`

>> dir is the directory of the library (libprintfcolor.a)

> Make dynamic library :
>>`gcc -shared -o printfcolor.so -fPIC printfcolor.c`

> To use static library (.so) : 
>> `gcc main.c -o exe -lprintfcolor -Ldir`

>> dir is the directory of the library (libprintfcolor.so)

>>Don't forget to add dir at LD_LIBRARY_PATH

>> export LD_LIBRARY_PATH=/path/to/dir:$LD_LIBRARY_PATH

>> Or use Rpath

>> `gcc -Ldir -Wl,-rpath dir -o exe main.c -lprintfcolor`

>> dir is the directory of the library (libprintfcolor.so)



