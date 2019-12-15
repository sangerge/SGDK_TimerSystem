#include "stimer.h"
#include <genesis.h>

void initTimer(Timer *_timer, u16 _deltaTime, void (*cal)(void))
{
    _timer->deltaTime = _deltaTime;
    _timer->timer = 0;
    _timer->timerEvent = cal;
}

void timerUpdate(Timer *_timer)
{
    if (_timer->timer % _timer->deltaTime == _timer->deltaTime - 1)
    {
        _timer->timerEvent();
    }
    _timer->timer++;
}

void timerLog(Timer *_timer, u16 x, u16 y)
{
    char msg[10];
    u16 res = _timer->timer % _timer->deltaTime;
    intToStr(res, msg, 10);
    VDP_drawText(msg, x, y);
}