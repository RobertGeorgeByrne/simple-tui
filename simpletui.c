#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main() {
    struct winsize {
        unsigned short  ws_row;         /* rows, in characters */
        unsigned short  ws_col;         /* columns, in characters */
        unsigned short  ws_xpixel;      /* horizontal size, pixels - not used */
        unsigned short  ws_ypixel;      /* vertical size, pixels - not used */
    } w;

    
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    printf("rows: %d, columns: %d\n", w.ws_row, w.ws_col);

    return 0;
}

void 
printbuffer(char *buffer, size_t size)
{
    write(STDOUT_FILENO, buffer, size);
}

