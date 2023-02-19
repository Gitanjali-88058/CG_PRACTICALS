#include <cmath>
#include <graphics.h>
#include <iostream>

using namespace std;

void drawline(int x0, int y0, int x1, int y1)
{
  if (x0 == x1 && y0 == y1)
  {
    putpixel(x1, y1, WHITE);
  }
  else
  {
    int dx = x1 - x0;
    int dy = y1 - y0;

    float m = float(dy) / (float)(dx);

    if (m >= 1 || m <= 0)
    {
      cout << "Slope must be between 0 and 1." << endl;
      exit(1);
    }

    int d = 2 * dy - dx;
    int del_E = 2 * dy;
    int del_NE = 2 * (dy - dx);

    int x = x0;
    int y = y0;
    putpixel(x, y, WHITE);

    while (x < x1)
    {
      if (d <= 0)
      {
        d += del_E;
        x += 1;
      }
      else
      {
        d += del_NE;
        x += 1;
        y += 1;
      }

      putpixel(x, y, WHITE);
    }
  }

  return;
}

int main()
{
    int x1, y1, x2, y2;
    cout << "Enter coordinates of first point (x1,y1): ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of second point (x2,y2): ";
    cin >> x2 >> y2;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    if (x1 == x2 && y1 == y2)
    {
        putpixel(x1, y1, WHITE);
    }
    else
    {
        drawline(x1, y1, x2, y2);
    }

    getch();
    closegraph();
}