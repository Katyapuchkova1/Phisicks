#include "TXLib.h"

struct Object

    {
    int x, y, vx, vy;
    };

void DrawMolecula (int x, int y);
void Move (Object* obj [], int dt, int r, int screenX, int screenY);
void MoleculeModelling (int screenX, int screenY, int nObjects, int from);
void InitializeRandom (Object objects [], int nObjects, int from);
void MoveObjects (Object objects [], int nObjects, int dt, int r, int from, int screenX, int screenY);
void DrawObject (Object objects [], int nObjects, int from);

int main()

    {
    int screenX = GetSystemMetrics (SM_CXSCREEN)-50, screenY = GetSystemMetrics (SM_CYSCREEN)-100;

    txCreateWindow (screenX, screenY);
    MoleculeModelling (screenX, screenY, 20, 0);

    }

void DrawMolecula (int x, int y)

    {
    txSetFillColor (RGB (255, 255, 255) );
    txSetColor (TX_NULL);
    txCircle (x, y, 20);
    }

void Move (Object* obj , int dt, int r, int screenX, int screenY)

    {

    (*obj).x = (*obj).x + (*obj).vx*dt;
    (*obj).y = (*obj).y + (*obj).vy*dt;

    if ((*obj).x > screenX-r)

        {
        (*obj).x = screenX-r;
        (*obj).vx = -(*obj).vx;
        }

    if ((*obj).x < 0)

        {
        (*obj).x = 0;
        (*obj).vx = -(*obj).vx;
        }

    if ((*obj).y > screenY-r)

        {
        (*obj).y = screenY-r;
        (*obj).vy = -(*obj).vy;
        }

    if ((*obj).y < 0)

        {
        (*obj).y = 0;
        (*obj).vy = -(*obj).vy;
        }
    }

void MoleculeModelling (int screenX, int screenY, int nObjects, int from)

    {
    int dt = 2, r = 20;
    int i = from;

    Object objects [nObjects];

    InitializeRandom (objects, nObjects, 0);

    while (!GetAsyncKeyState (VK_ESCAPE) )

        {
        MoveObjects (objects, nObjects, dt, r, 0, screenX, screenY);
        DrawObject (objects, nObjects, 0);
        }
    }

void InitializeRandom (Object objects [], int nObjects, int from)

    {

    int i = from;

    while (i < nObjects)

        {

        objects [i].x = rand () %100;
        objects [i].y = rand () %100;
        objects [i].vx = rand () %10;
        objects [i].vy = rand () %10;

        i++;
        }

    }

void MoveObjects (Object objects [], int nObjects, int dt, int r, int from, int screenX, int screenY)

    {

    int i = from;

    while (i < nObjects)

        {
        Move (&objects [i], dt, r, screenX, screenY);
        i++;
        }

    }

void DrawObject (Object objects [], int nObjects, int from)

    {
    int i = from;

    txSetFillColor (RGB (0, 0, 0) );
    txClear();

    while (i < nObjects)

        {
        DrawMolecula (objects [i].x, objects [i].y);
        i++;
        }

    }