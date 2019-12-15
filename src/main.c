#include <genesis.h>
#include <vdp.h>
#include "stimer.h"

u8 lv = 0;

Timer t1;
Timer t2;
void t1Callback();
void t2Callback();

int main()
{
    initTimer(&t1, 255, t1Callback);
    initTimer(&t2, 600, t2Callback);

    while (lv == 0)
    {
        timerUpdate(&t1);
        timerLog(&t1, 0, 0);
        VDP_waitVSync();
    }

    while (lv == 1)
    {
        timerUpdate(&t2);
        timerLog(&t2, 0, 4);
        VDP_waitVSync();
    }

    while (TRUE)
    {
        VDP_drawText("All timer is over", 0, 8);
        VDP_waitVSync();
    }

    return 0;
}

void t1Callback()
{
    VDP_drawText("Timer 1 is over...", 0, 1);
    lv = 1;
}

void t2Callback()
{
    VDP_drawText("Timer 2 is over...", 0, 5);
    lv = 2;
}