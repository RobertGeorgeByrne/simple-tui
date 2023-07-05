#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "simpletui.h"
#include "escapeChars.h"

#define BUFFER_ELEMENT(B, ROW, COL) (B).chars[ROW * (B).c + COL] /* */


void renderwindow(TuiWindow*);
static void getwsize(TuiWindow *w);

int main() {

    TuiWindow b;
    
    getwsize(&b);
    printf("%i, %i\n", b.r, b.c);

    b.size = 2 * b.r * b.c * sizeof(char);
    b.chars = (char*)malloc(b.size);
    b.chars[b.r*b.c + b.c] = 'x';

    TuiWindow *bp = &b;

    printf("%c\n", BUFFER_ELEMENT(*bp, b.r, b.c));

    TuiWindow tst = tuiinit();
    getchar();
    write(STDOUT_FILENO, ORIGBUFFER, sizeof(ORIGBUFFER));
    free(b.chars);
    return 0;
}


void 
renderwindow(TuiWindow *w)
{
    write(STDOUT_FILENO, w->chars, w->r * w->c);
}

void
getwsize(TuiWindow *w){
    static struct winsize ws;  /* winsize defined in ioctl-types.h */
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1)
        fprintf(stderr, "Failed to get window size");
    w->r = ws.ws_row;
    w->c = ws.ws_col;
}

int
tuicleanup(TuiWindow *w){
    free(w->chars);
    write(STDOUT_FILENO, ORIGBUFFER, sizeof(ORIGBUFFER));
    return 0;
}

/* If terminal changes size need to get a new TuiWindow */
TuiWindow
tuiinit(){
    write(STDOUT_FILENO, ALTBUFFER, sizeof(ALTBUFFER));
    TuiWindow w;
    getwsize(&w);
    w.size = w.r * w.c * sizeof(char);
    w.chars = (char*)malloc(w.size);
    return w;
}

void
setrow(TuiWindow *w, char *chars, unsigned short r)// dont pass chars[] that is less than length w->c
{
    for (unsigned short i = 0; i < w->c; i++)
        w->chars[r * w->c + i] = chars[i]; //overflow of chars[i]?????????
}


void
setcol(TuiWindow *w, char *chars, unsigned short c)// dont pass chars[] that is less than length w->r
{

    for (unsigned short i = 0; i < w->r; i++)
        w->chars[r * w->c + i] = chars[i]; //overflow of chars[i]?????????
}
