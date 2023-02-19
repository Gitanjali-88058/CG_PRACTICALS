#include <cmath>
#include <graphics.h>
#include <cstdlib>
#include <iostream>
using namespace std;

void drawline(int x1, int y1, int x2, int y2)
{
    double y = y1, x = x1;

    double m = float(y2 - y1) / float(x2 - x1);
    cout << m << endl;
    if (abs(m) <= 1)
    {
        // slope less than 1
        if (x1 < x2)
        {
            // left to right
            //  x++,y+=m
            for (; x <= x2; x++)
            {
                putpixel(x, round(y), WHITE);
                y += m;
            }
        }
        else
        {
            // right to left
            // x--, y-=m
            for (x = x2, y = y2; x >= x1; x--)
            {
                putpixel(x, round(y), WHITE);
                y -= m;
            }
        }
    }
    if (abs(m) > 1)
    {
        // slope more than 1
        if (x1 < x2)
        {
            // left to right
            // y++, x+=1/m
            for (; y <= y2; y++)
            {
                putpixel(round(x), y, WHITE);
                x += 1 / m;
            }
        }
        else
        {

            // right to left
            // y--, x-=1/m
            for (x = x2, y = y2; y >= y1; y--)
            {
                putpixel(round(x), y, WHITE);
                x -= 1 / m;
            }
        }
    }
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