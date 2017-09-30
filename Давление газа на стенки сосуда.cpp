#include "TXLib.h"

//{Prototipy
void DrawBackground(HDC background);
void DrawVolume(int YPiston);
void MoveMolecule();
//}

int main()

    {
    txCreateWindow (GetSystemMetrics (SM_CXSCREEN) - 50, GetSystemMetrics (SM_CYSCREEN) - 50);

    HDC background = txLoadImage ("Mario.bmp");
    DrawBackground (background);
    txDeleteDC (background);

    MoveMolecule();
    }

void DrawBackground (HDC background)

    {
    txTransparentBlt (txDC(), 0, 0, 1500, 900, background, 0, 0);
    }

void DrawVolume (int yPiston)

    {
    txSetFillColor (RGB (255, 255, 255));
    txSetColor (TX_NULL);
    txRectangle (150, 90, 450, 790);
    txSetFillColor (RGB (0, 0, 0));
    txSetColor (TX_NULL);
    txRectangle (160, yPiston, 440, yPiston + 30);
    }

void MoveMolecule()

    {
    int x = 170, y = 150, vx = 4, vy = 10, dt = 2;
    int yPiston = 440, xPiston = 160;
    int xVolume = 150, yVolume = 90, xSzVolume = 300, ySzVolume = 700;

    while (!GetAsyncKeyState (VK_ESCAPE))

        {
        DrawVolume (yPiston);
        txCircle (x, y, 7);

        x = x + vx*dt;
        y = y + vy*dt;

        if (GetAsyncKeyState (VK_UP))

            {
            yPiston--;
            }

        if (GetAsyncKeyState (VK_DOWN))

            {
            yPiston++;
            }

        if (yPiston >= yVolume + ySzVolume)

            {
            yPiston = yVolume + ySzVolume;
            }

        if (yPiston <= yVolume)

            {
            yPiston = yVolume;
            }

        if (x <= xVolume)

            {
            vx = -vx;
            x = xVolume;
            }

        if (x >= xVolume + xSzVolume)

            {
            vx = -vx;
            x = xVolume + xSzVolume;
            }

        if (y >= yVolume + ySzVolume)

            {
            vy = -vy;
            y = yVolume + ySzVolume;
            }

        if (y <= yPiston)

            {
            vy = -vy;
            y = yPiston;
            }

        txSleep (1);
        }
    }
