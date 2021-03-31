#ifndef PRINTF_COLOR
#define PRINTF_COLOR
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <string.h>

void initFormatting();
int printf_color (char *format, ...);
void setFontColor(int color);
void setBackgroundColor(int color);
void enableBackground(bool active);
void enableUnderline(bool active);

typedef struct  Formatting Formatting;
struct Formatting
{
    int fontColor;
    int backgroundColor;
    bool backgroundEnable;
    bool underlineEnable;
};

extern const int BLACK;
extern const int RED ;
extern const int GREEN ;
extern const int YELLOW ;
extern const int BLUE ;
extern const int PURPLE ;
extern const int CYAN ;
extern const int WHITE;


#endif //PRINTF_COLOR
