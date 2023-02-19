#include <cmath>
#include <graphics.h>
#include <iostream>

using namespace std;

void drawCirclePoints(int x, int y, int c_x, int c_y)
{
  putpixel(c_x + x, c_y + y, WHITE);
  putpixel(c_x + y, c_y + x, WHITE);
  putpixel(c_x + y, c_y + -x, WHITE);
  putpixel(c_x + x, c_y + -y, WHITE);
  putpixel(c_x + -x, c_y + -y, WHITE);
  putpixel(c_x + -y, c_y + -x, WHITE);
  putpixel(c_x + -y, c_y + x, WHITE);
  putpixel(c_x + -x, c_y + y, WHITE);
  return;
}

void midpointCircle(int r, int c_x = 0, int c_y = 0)
{
  int x = 0;
  int y = r;
  int d = 1 - r;
  drawCirclePoints(x, y, c_x, c_y);
  while (y > x)
  {
    if (d < 0)
    {
      d += 2 * x + 3;
      x += 1;
    }
    else
    {
      d += 2 * (x - y) + 5;
      x += 1;
      y -= 1;
    }
    drawCirclePoints(x, y, c_x, c_y);
  }
  return;
}

int main(void)
{
  int x, y, r;
  cout << "Enter Centre (x y): ";
  cin >> x >> y;
  cout << "Enter Radius (r): ";
  cin >> r;
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);
  midpointCircle(r,x, y);
  getch();
  closegraph();
  return 0;
}
