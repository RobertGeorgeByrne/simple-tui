typedef struct {
    unsigned long decorator;
    char c;
} cell;
typedef struct {
    unsigned short r;
    unsigned short c;
    cell* cells;
} TuiWindow ;

/*
 * *** Need to be called again if window is resised ***
 *
 * initialises tuiwindow struct and 
 * sets terminal to alternate buff
 */
extern void tuiinit(TuiWindow*);

/*
 * frees internal pointers and
 * resores terminal to origional buffer
 */
extern int tuicleanup(TuiWindow*);


/*
 * sends the character array to output
 */
extern void renderwindow(TuiWindow*);

extern void setrow(TuiWindow*, char*, unsigned short);
extern void setcol(TuiWindow*, char*, unsigned short);
