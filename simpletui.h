typedef struct {
    unsigned short r;
    unsigned short c;
    unsigned short size;  /* size of memory allocated for bytes */
    char* chars;
} TuiWindow ;

/*
 * *** Need to be called again if window is resised ***
 *
 * initialises tuiwindow struct and 
 * sets terminal to alternate buff
 */
extern TuiWindow tuiinit();

/*
 * frees internal pointers and
 * resores terminal to origional buffer
 */
extern int tuicleanup(TuiWindow*);
