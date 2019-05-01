#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <TXLib.h>

using std::cout;

void DrawBranch(double x, double y, double a, double len);

int main()
    {
     srand(time(NULL));

     double x = 700, y = 650, a = -(3.14/2), len = 70;

     txCreateWindow (1300, 650, true);

     cout << "Press space to draw or any other key twice to exit";

     txSetColor(TX_WHITE);
     while(getche() == ' ')
     {
      txSetColor(TX_BLACK);
      txClear();

      DrawBranch(x, y, a, len);
     }

    }
void DrawBranch(double x, double y, double a, double len)
                {
                 if (len <= 10  or !(rand()%6))
                     return;

                 double x1 = x + len * cos(a), y1 = y + len * sin(a);

                 if((y1 > 600) or (y1 < 20))
                    return;
                 txSetColor(RGB(len*16/15 - 32/3, -len*17*0.25 + 595/2, 0), len*0.1);
                 txLine (x, y, x1, y1);

                 double randomA = (rand()%5)*0.15;
                 double randomL = rand()%8;
                 DrawBranch(x1, y1, a-randomA, len-1-randomL);

                 randomA = (rand()%5)*0.15;
                 randomL = rand()%8;
                 DrawBranch(x1, y1, a+randomA, len-1-randomL);
                }
