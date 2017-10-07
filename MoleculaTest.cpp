#include "TXLib.h"

//Prototypes

void Molecula (int x, int y);
void MoveMolecula (int screenX, int screenY);

int main()

    {
    int screenX = GetSystemMetrics (SM_CXSCREEN)-50, screenY = GetSystemMetrics (SM_CYSCREEN)-40;

    txCreateWindow (screenX, screenY);
    MoveMolecula (screenX, screenY);
    }

void Molecula (int x, int y)

    {
    txSetFillColor (RGB (255, 255, 255));
    txCircle (x, y, 20);
    }

void MoveMolecula (int screenX, int screenY)

    {
    int x = 100, y = 200;
    int vx = 3, vy = 3, dt = 2;
    int r = 20;

    while (!GetAsyncKeyState (VK_ESCAPE) )

        {

        txSetFillColor (RGB (0, 0, 0) );
        txClear();
        Molecula (x, y);

        x = x + vx*dt;
        y = y + vy*dt;

        printf ("x = %3d, y = %3d\n", x, y);

        if (x >= screenX-r)

            {
            vx = -vx;
            x = screenX-r;
            };

        if (x <= 0+r)

            {
            vx = -vx;
            x = 0+r;
            };

        if (y >= screenY-r)

            {
            vy = -vy;
            y = screenY-r;
            };

        if (y <= 0+r)

            {
            vy = -vy;
            y = 0+r;
            };


        txSleep (20);

        };
    }
