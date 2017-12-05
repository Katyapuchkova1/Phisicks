#include "TXLib.h"

struct Object

    {
    int x, y, vx, vy;
    };

//Prototypes

void DrawAsMolecula (int x, int y);
void MoveObject (int screenX, int screenY, int nObjects);
void Move (Object* obj, int dt, int r, int screenX, int screenY);
void InitializeRandom (Object objects[], int from, int to);
void MoveObjects (Object objects[], int from, int to, int dt, int r, int screenX, int screenY);
void DrawObjects (Object objects [], int from, int to, void (*objectShape) (int x, int y));
void DrawAsSquare (int x, int y);

int main()

    {
    int screenX = GetSystemMetrics (SM_CXSCREEN)-50, screenY = GetSystemMetrics (SM_CYSCREEN)-100;

    txCreateWindow (screenX, screenY);
    MoveObject (screenX, screenY, 20);
    }

void DrawAsMolecula (int x, int y)

    {
    txSetFillColor (RGB (255, 255, 255));
    txCircle (x, y, 20);
    }

void MoveObject (int screenX, int screenY, int nObjects)

    {

    int r = 20,  dt = 2;

    Object objects [nObjects]; // =  {};//Массив


    InitializeRandom (objects, 0, nObjects);


    while (!GetAsyncKeyState (VK_ESCAPE) )

        {

        txSetFillColor (RGB (0, 0, 0) );
        txClear();

        MoveObjects (objects, 0, nObjects, dt, r, screenX, screenY);

        DrawObjects (objects, 0, nObjects, &DrawAsSquare);

        txSleep (20);

        DrawObjects (objects, 0, nObjects, &DrawAsMolecula);

        txSleep (20);
        }


    }

void Move (Object* obj, int dt, int r, int screenX, int screenY)

    {

    (*obj).x = (*obj).x + (*obj).vx*dt;
    (*obj).y = (*obj).y + (*obj).vy*dt;

    printf ("x = %3d, y = %3d\n", (*obj).x, (*obj).y);

    if ((*obj).x >= screenX-r)

        {
        (*obj).vx = -(*obj).vx;
        (*obj).x = screenX-r;
        }

    if ((*obj).x <= 0+r)

        {
        (*obj).vx = -(*obj).vx;
        (*obj).x = 0+r;
        }

    if ((*obj).y >= screenY-r)

        {
        (*obj).vy = -(*obj).vy;
        (*obj).y = screenY-r;
        }

    if ((*obj).y <= 0+r)

        {
        (*obj).vy = -(*obj).vy;
        (*obj).y = 0+r;
        }

    }

void InitializeRandom (Object objects[], int from, int to)

    {
    int i = from;

    while (i < to)

        {
        objects [i].x = rand () % 100;
        objects [i].y = rand () % 100;
        objects [i].vx = rand ()% 100;
        objects [i].vy = rand () % 100;

        i++;
        }

    }

void MoveObjects (Object objects[], int from, int to, int dt, int r, int screenX, int screenY)

    {
    int i = from;

    while (i < to)

        {
        Move (&objects [i], dt, r, screenX, screenY);
        i++;
        }
    }

void DrawObjects (Object objects[], int from, int to, void (*objectShape) (int x, int y))

    {
    int i = from;

    while (i < to)

        {
        objectShape (objects [i].x, objects [i].y);
        i++;
        }


    }

void DrawAsSquare (int x, int y)

    {
    txSetFillColor (RGB (255, 255, 255));
    txSetColor (TX_NULL);
    txRectangle (x-10, y-5, x+10, y+5);
    }
