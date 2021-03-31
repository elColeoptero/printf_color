#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <string.h>
#include "printfcolor.h"

#define MAX_SIZE 1000

const char * FONT_COLOR_REFERECENCE[] = {"\033[1;30m","\033[1;31m","\033[1;32m","\033[1;33m","\033[1;34m","\033[1;35m","\033[1;36m","\033[1;37m"};
const char * UNDERLINE_COLOR_REFERECENCE[] = {"\033[4;30m","\033[4;31m","\033[4;32m","\033[4;33m","\033[4;34m","\033[4;35m","\033[4;36m","\033[4;37m"};
const char * BACKGROUND_COLOR_REFERECENCE[] = {"\033[40m","\033[41m","\033[42m","\033[43m","\033[44m","\033[45m","\033[46m","\033[47m"};
const char * RESET = "\033[0m";

const int BLACK = 0;
const int RED = 1;
const int GREEN = 2 ;
const int YELLOW = 3;
const int BLUE = 4;
const int PURPLE = 5;
const int CYAN = 6;
const int WHITE = 7;

Formatting formatting ;

void insert_substring(char *a, const char *b, int position);
char *substring(char *string, int position, int length);
char* banaliser(char *format,char *format2);

/**
 * initialisation of formatting struct
 */

void initFormatting(){
    formatting.fontColor = 7;
    formatting.backgroundColor = 0;
    formatting.backgroundEnable = false;
    formatting.underlineEnable = false;
}

/**
 * insert string into another
 * @param a destination string
 * @param b string to insert
 * @param position position of insertion
 */
void insert_substring(char *a, const char *b, int position)
{
   char *f, *e;
   int length;
   
   length = strlen(a);
   
   f = substring(a, 1, position - 1 );      
   e = substring(a, position, length-position+1);

   strcpy(a, "");
   strcat(a, f);
   free(f);
   strcat(a, b);
   strcat(a, e);
   free(e);
}

/**
 * substring of param string
 * @param string source string
 * @param position index of first char for substring 
 * @param length length of substring
 * @return pointer on substring
*/
char *substring(char *string, int position, int length)
{
   char *pointer;
   int c;
 
   pointer = malloc(length+1);
   
   if( pointer == NULL )
       exit(EXIT_FAILURE);
 
   for( c = 0 ; c < length ; c++ )
      *(pointer+c) = *((string+position-1)+c);      
       
   *(pointer+c) = '\0';
 
   return pointer;
}


/**
 * clean color configuration for \n to avoid full line of color
 * @param format the string to modify
 * @param destination of new string 
 * @return pointer on new string 
*/
char* banaliser(char *format,char *nformat)
{    
    int i =0;
    while(nformat[i]!='\0'){
        if(nformat[i]=='\n'){
            insert_substring(nformat,RESET,i+1);
            if ( formatting.backgroundEnable ){
                insert_substring(nformat,BACKGROUND_COLOR_REFERECENCE[formatting.backgroundColor],i+6);
            }
            insert_substring(nformat,FONT_COLOR_REFERECENCE[formatting.fontColor],i+6);
            if ( formatting.underlineEnable ) {
                insert_substring(nformat,UNDERLINE_COLOR_REFERECENCE[formatting.fontColor],i+6);

            }
            i+=6;
        }
        i++;
    }
    return nformat;
}

/**
 * count \n in string  
 * @param string 
 * @return nb of \n
*/
int count_new_line(char * string){
  int i = 0,nb = 0;
  while(string[i]!='\0'){
    if(string[i] == '\n'){
      nb++;
    }
  }
}
/**
 * same as printf 
 * @see printf
*/
int printf_color (char *format, ...)
{
    char nformat[MAX_SIZE];
    strcpy(nformat,format);
    banaliser(format,nformat);
    if ( formatting.underlineEnable){
        printf ("%s",UNDERLINE_COLOR_REFERECENCE[formatting.fontColor]);
    }
    printf ("%s",FONT_COLOR_REFERECENCE[formatting.fontColor]);
    if ( formatting.backgroundEnable ) {
        printf ("%s",BACKGROUND_COLOR_REFERECENCE[formatting.backgroundColor]);
    }
    va_list arg;    
    int done;
    va_start (arg, format);
    done = vfprintf (stdout, nformat, arg);
    va_end (arg);
    printf ("%s",RESET);
    return done;
    }

/**
 * change font color
 * @param color font color
*/
void setFontColor(int color){
  if (color>=0 && color<=7 ){
    formatting.fontColor = color;
  }
}

/**
 * change background color
 * @param color background color
*/
void setBackgroundColor(int color){
  if (color>=0 && color<=7 ){
    formatting.backgroundColor = color;
  }
}

/**
 * enabale background 
 * @param active 
*/
void enableBackground(bool active){
  if (active == true || active == false){
    formatting.backgroundEnable = active;
  }
}

/**
 * enable underline
 * @param active font color
*/
void enableUnderline(bool active){
  if (active == true || active == false){
    formatting.underlineEnable = active;
  }
}
