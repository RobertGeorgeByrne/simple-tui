#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "simpletui.h"
#include "escapeChars.h"

#define BUFFER_ELEMENT(B, ROW, COL) (B).chars[ROW * (B).c + COL] /* */


static void getwsize(TuiWindow *w);

int main() {

//    printf("%ld, %ld", sizeof(unsigned long), sizeof(FG_BLACK BG_BRIGHT_WHITE) );
    TuiWindow w = { 0 };
    tuiinit(&w);
    char c[256];

    for (int i = 0; i < 256; i++) {
        c[i] = 'X';
    }
    setrow(&w, c, w.r -1);
    setcol(&w, c, w.c -1);
    renderwindow(&w);
    getchar();
    tuicleanup(&w);
    return 0;
}


void 
renderwindow(TuiWindow *w)
{
    write(STDOUT_FILENO, w->cells, w->r * w->c * sizeof(cell));
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
    free(w->cells);
    write(STDOUT_FILENO, ORIGBUFFER, sizeof(ORIGBUFFER));
    return 0;
}

/* If terminal changes size need to get a new TuiWindow */
void
tuiinit(TuiWindow *w){
    write(STDOUT_FILENO, ALTBUFFER, sizeof(ALTBUFFER));
    getwsize(w);
    w->cells = (cell*)calloc(w->r * w->c, sizeof(cell));
    for (int i=0; i < w->r * w->c; i++){
        w->cells[i].c = ' ';
    }
}

void
setrow(TuiWindow *w, char *chars, unsigned short r)
{
    for (unsigned short i = 0; i < w->c; i++)
        (w->cells)[r * w->c + i].c = chars[i];
}

void
setcol(TuiWindow *w, char *chars, unsigned short c)
{
    //for (int i =0; i < 5; i++)
    //    w->cells[c].decorator += 0;//(BG_BRIGHT_WHITE)[0] ;
    for (unsigned short i = 0; i < w->r; i++){
        (w->cells)[i * w->c + c].c = chars[i]; 
    }
}
