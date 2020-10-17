#include<iostream>
#include<graphics.h>
#include<conio.h>

using namespace std;

void drawcircle(int x0, int y0, int radius)
{
    int y = radius;
    int x = 0;
    int p = 5/4-radius;

    while (x < y)
    {
	putpixel(x0 + x, y0 + y, 7);
	putpixel(x0 + y, y0 + x, 7);
	putpixel(x0 - y, y0 + x, 7);
	putpixel(x0 - x, y0 + y, 7);
	putpixel(x0 - x, y0 - y, 7);
	putpixel(x0 - y, y0 - x, 7);
	putpixel(x0 + y, y0 - x, 7);
	putpixel(x0 + x, y0 - y, 7);

	x=x+1;
	if (p < 0)
            p=p+2*x+3;

	else{
            p=p+2*(x-y)+5;
            y=y-1;
        }
    }
}

int main()
{
	int gdriver=DETECT, gmode, error, x, y, r;
	initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

	cout<<"Enter radius of circle: ";
	cin>>r;

	cout<<"Enter co-ordinates of center(x and y): ";
	cin>>x>>y;
	drawcircle(x, y, r);

    getch();
    closegraph();
	return 0;
}
