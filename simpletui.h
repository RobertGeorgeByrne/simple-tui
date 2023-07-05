typedef struct {
    unsigned short r;
    unsigned short c;
    unsigned short size;  /* size of memory allocated for bytes */
    char* chars;
} TuiWindow ;

TuiWindow tuiinit();
int tuicleanup(TuiWindow*);
