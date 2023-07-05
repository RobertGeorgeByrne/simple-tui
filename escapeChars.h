
#define ESC "\033["

/* 
 * Alternate buffer used for drawing so the origional can
 * be restored after program ends. Not defined in offical ANSI 
 * spec but supported on all xterm derivitives 
*/
#define ALTBUFFER          ESC "?1049h"
#define ORIGBUFFER         ESC "?1049l"

/* 
 * Cursor contols
*/
#define MV_NUP(N)          ESC #N "A"
#define MV_NDOWN(N)        ESC #N "B"
#define MV_NRIGHT(N)       ESC #N "C"
#define MV_NLeft(N)        ESC #N "D"

#define MV(ROW, COL)       ESC #ROW ";" #COL "H"

#define MV0                ESC "H"

/* 
 *  Default terminal colors
*/
#define FG_BLACK           ESC "30m"
#define FG_RED             ESC "31m"
#define FG_GREEN           ESC "32m"
#define FG_YELLOW          ESC "33m"
#define FG_BLUE            ESC "34m"
#define FG_MAGENTA         ESC "35m"
#define FG_CYAN            ESC "36m"
#define FG_WHITE           ESC "37m"
#define FG_DEFAULT         ESC "39m"

#define BG_BLACK           ESC "40m"
#define BG_RED             ESC "41m"
#define BG_GREEN           ESC "42m"
#define BG_YELLOW          ESC "43m"
#define BG_BLUE            ESC "44m"
#define BG_MAGENTA         ESC "45m"
#define BG_CYAN            ESC "46m"
#define BG_WHITE           ESC "47m"
#define BG_DEFAULT         ESC "49m"

#define FG_BRIGHT_BLACK    ESC "90m"
#define FG_BRIGHT_RED      ESC "91m"
#define FG_BRIGHT_GREEN    ESC "92m"
#define FG_BRIGHT_YELLOW   ESC "93m"
#define FG_BRIGHT_BLUE     ESC "94m"
#define FG_BRIGHT_MAGENTA  ESC "95m"
#define FG_BRIGHT_CYAN     ESC "96m"
#define FG_BRIGHT_WHITE    ESC "97m"

#define BG_BRIGHT_BLACK    ESC "100m"
#define BG_BRIGHT_RED      ESC "101m"
#define BG_BRIGHT_GREEN    ESC "102m"
#define BG_BRIGHT_YELLOW   ESC "103m"
#define BG_BRIGHT_BLUE     ESC "104m"
#define BG_BRIGHT_MAGENTA  ESC "105m"
#define BG_BRIGHT_CYAN     ESC "106m"
#define BG_BRIGHT_WHITE    ESC "107m"
