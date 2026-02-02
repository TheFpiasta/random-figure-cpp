#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef __BORLANDC__
#include <conio.h>
#endif

/* definition of function irand - see above */
/* ... */
int irand(int a, int e)
{
    double r = e - a + 1;
    return a + (int)(r * rand() / (RAND_MAX + 1.0));
}

/* create a figure with random apperance */
void randomFigure(char a[79][24])
{
    int nParts, i;
    char app;
    int x, y;

    /* number of parts */
    nParts = irand(1, 100);
    /* apperance of the parts */
    app = (char)irand(0, 15);
    /* starting position */
    x = irand(0, 78);
    y = irand(0, 23);
    a[x][y] = app;
    for (i = 0; i < nParts; ++i) {
        /* get next position */
        x += irand(-1, 1);
        y += irand(-1, 1);
        if (x > 78) x = 78;
        if (x < 0) x = 0;
        if (y > 23) y = 23;
        if (y < 0) y = 0;
        a[x][y] = app;
    }
}

int main(int argc, char** argv)
{
    int i, j;
    char a[79][24];

    /* set the random seed */
    srand(time(0));

    /* clear painting */
    for (j = 0; j < 24; ++j) {
        for (i = 0; i < 79; ++i) {
            a[i][j] = 0;
        }
    }

    /* create some random figures */
    for (i = 0; i < irand(10, 60); ++i) {
        randomFigure(a);
    }

    /* draw the painting */
    for (j = 0; j < 24; ++j) {
        for (i = 0; i < 79; ++i) {
#ifdef __BORLANDC__
            textcolor(a[i][j]);
            cprintf("%c", 0xdb);
#else
            printf("%c", 32 + a[i][j]);
#endif
        }
        printf("\n");
    }
}