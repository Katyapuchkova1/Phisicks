#include "TXLib.h"

//#define $  printf ("{%d}\n", __LINE__);
#define $

struct Object

    {
    int x, y, vx, vy;
    };

struct Tank

    {
    int xContainer, yContainer, xSzContainer, ySzContainer;
    };

void DrawMolecula (int x, int y);
void ObjectModelling (int nObject, Tank tank);
void Move (Object* obj, int dt, Tank tank, int r);
void InitializeRandom (Object objects [], int from, int to);
void MoveObjects (Object objects [], int dt, int from, int to, Tank tank);
void DrawObject (Object objects [], int from, int to, void (*ObjectShape) (int x, int y), Tank tank);
double TemperatureMeasuring (Object obj [], int nObjects, int from);
void DrawContainer (Tank tank);

int main()

    {
    int screenX = GetSystemMetrics (SM_CXSCREEN)-50, screenY = GetSystemMetrics (SM_CYSCREEN)-100;

$   txCreateWindow (screenX, screenY);
$   ObjectModelling (100, Tank {100, 100, 300, 500});
    }

void DrawMolecula (int x, int y)

    {
    txSetFillColor (RGB (255, 255, 255));
    txCircle (x, y, 10);
    }

void ObjectModelling (int nObjects, Tank tank )

    {

    int dt = 2;

    Object objects [nObjects]; //Массив

    InitializeRandom (objects, 0, nObjects);

    double T = TemperatureMeasuring (objects, nObjects, 0);

    printf ("T = %lf", T);

$   while (!GetAsyncKeyState (VK_ESCAPE) )

        {

please  MoveObjects (objects, dt, 0, nObjects, tank);

$       DrawObject (objects, 0, nObjects, &DrawMolecula, tank);

        txSleep (20);
        }
    }

void Move (Object* obj, int dt, Tank tank, int r)

    {

    (*obj).x = (*obj).x + (*obj).vx*dt;
    (*obj).y = (*obj).y + (*obj).vy*dt;


    if ((*obj).x >= tank.xContainer + tank.xSzContainer - r)

        {
        (*obj).vx = -(*obj).vx;
        (*obj).x = tank.xContainer + tank.xSzContainer - r;
        }

    if ((*obj).x <= tank.xContainer + r)

        {
        (*obj).vx = -(*obj).vx;
        (*obj).x = tank.xContainer + r;
        }

    if ((*obj).y >= tank.yContainer + tank.ySzContainer - r)

        {
        (*obj).vy = -(*obj).vy;
        (*obj).y = tank.yContainer + tank.ySzContainer - r;
        }

    if ((*obj).y <= tank.yContainer + r)

        {
        (*obj).vy = -(*obj).vy;
        (*obj).y = tank.yContainer + r;
        }

    }

void InitializeRandom (Object objects [], int from, int to)

    {

    int i = from;

    while (i < to)

        {
        objects [i].x = rand () %100;
        objects [i].y = rand () %100;
        objects [i].vx = rand () %10;
        objects [i].vy = rand () %10;

        i++;
        }
    }

void DrawObject (Object objects [], int from, int to, void (*ObjectShape) (int x, int y), Tank tank)

    {
    txSetFillColor (RGB (0, 0, 0) );
    txClear();

    int i = from;

$   while (i < to)

        {
        DrawContainer (tank);
        ObjectShape (objects [i].x, objects [i].y);
        i++;
        }
    }

void MoveObjects (Object objects [], int dt, int from, int to, Tank tank)

    {

$   int i = from;
    while (i < to)

        {
$       Move (&objects [i], dt, tank, 20);
$       i++;
        }
    }

double TemperatureMeasuring (Object obj [], int nObjects, int from)

    {

    int i = from;

    double v2 = 0;

    while (i < nObjects )

        {
        v2 = v2 + (obj [i].vx)*(obj [i].vx) + (obj [i].vy)*(obj [i].vy);
        i++;
        }

    const double K = 1.4e-23;

    double m = 1;

    double Ek = nObjects * m*v2/2/* =(3/2)*KT */;

    double T = Ek/(3.0/2)/K;

    return T*1e23;

    }

void DrawContainer (Tank tank)

    {
    txSetFillColor (RGB (0, 0, 0) );
    txSetColor (RGB (255, 255, 255), 10);
    txLine (tank.xContainer, tank.yContainer, tank.xContainer + tank.xSzContainer, tank.yContainer);
    txLine (tank.xContainer, tank.yContainer, tank.xContainer, tank.yContainer + tank.ySzContainer);
    txLine (tank.xContainer, tank.yContainer + tank.ySzContainer, tank.xContainer + tank.xSzContainer, tank.yContainer + tank.ySzContainer);
    txLine (tank.xContainer + tank.xSzContainer, tank.yContainer + tank.ySzContainer, tank.xContainer + tank.xSzContainer, tank.yContainer);
    }
