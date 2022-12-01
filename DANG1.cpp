// DANG 1
// VE HINH

#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>
#include <windows.h>
#include <winbgim.h>

using namespace std;

struct point2d
{
    int x,y;
};

void Textcolor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// Thuat toan midpoint de ve duong thang
void midpoint(int x1, int y1, int x2, int y2, int color)
{
    int a,b,x,y,pi,p;
    a = y2 - y1;
    b = -(x2 - x1);
    y = y1;
    x = x1;
    putpixel(x,y,color);
    p = 2 * a + b;
    while(x < x2)
    {
        if(p < 0)
        {
            p = p + 2 * a;
        }
        else
        {
            y++;
            p = p + 2 * (a + b);
        }
        x++;
        putpixel(x,y,color);
        delay(10);
    }
}

// Ve hinh tron
void put8pixel(int xc, int yc, int x, int y, int color)
{
    putpixel(x + xc, y + yc, color);
    putpixel(-x + xc, y + yc, color);
    putpixel(x + xc, -y + yc, color);
    putpixel(-x + xc, -y + yc, color);
    putpixel( y + xc, x + yc, color);
    putpixel(-y + xc, x + yc, color);
    putpixel(y + xc, -x + yc, color);
    putpixel(-y + xc, -x + yc, color);
}
// thuat toan midpoint
void drawCircleMidpoint(int xc, int yc, int r, int color)
{
    int x = 0, y = r;
    int f = 1 - r;

    put8pixel(xc, yc, x, y, color);

    while (x < y)
    {
        if (f < 0) f += (x << 1) + 3;
        else
        {
            y--;
            f += ((x - y) << 1) + 5;
        }
        x++;
        delay(100);
        put8pixel(xc, yc, x, y, color);
    }
}

// thuat toan brechxemham
void ellipseBR(int xcenter,int ycenter,int xradius,int yradius, int color)
{
    int x,y; float c,p;
    x=0; y=yradius;
    c=(float)yradius/xradius;
    c=c*c; p=2*c-2*yradius+1;
    while (c*x<=y)
        {
            delay(100);
            putpixel(xcenter+x,ycenter+y,color);
            putpixel(xcenter-x,ycenter+y,color);
            putpixel(xcenter+x,ycenter-y,color);
            putpixel(xcenter-x,ycenter-y,color);
            if (p<0) p += 2*c*(2*x+3);
            else
                {
                    p +=4*(1-y)+2*c*(2*x+3);
                    y--;
                }
            x++;
        }

    y=0;x=xradius;
    c= (float)xradius/yradius;
    c=c*c; p=2*c-2*xradius+1;
    while (c*y<=x)
        {
            delay(100);
            putpixel(xcenter+x,ycenter+y,color);
            putpixel(xcenter-x,ycenter+y,color);
            putpixel(xcenter+x,ycenter-y,color);
            putpixel(xcenter-x,ycenter-y,color);
            if (p<0) p +=2*c*(2*y+3);
            else
                {
                    p +=4*(1-x)+2*c*(2*y+3);
                    x--;
                }
            y++;
        }
}

void vedagiac(point2d p[],int v)
 {
    setlinestyle(3,0,3); setcolor(YELLOW);
    for(int i=0;i<v;i++)
    {
        line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
    }
 }
void nhapdagiac(point2d p[],int v)
 {
     int i;
     for(i=0;i<v;i++)
     {
         cout<<"\nnhap toa do dinh"<<i+1;
         cout<<"\n\tx["<<(i+1)<<"] = ";cin>>p[i].x;
         cout<<"\n\ty["<<(i+1)<<"] = ";cin>>p[i].y;

     }
     p[i].x=p[0].x;
     p[i].y=p[0].y;
 }
int menu()
{
   while(69)
   {
    system("cls");
    cleardevice();
    int chon;
    Textcolor(10);
    cout<<"\t\t\tMENU\n";
    cout<<"\t1. Ve Duong thang \n";
    cout<<"\t2. Ve Duong tron \n";
    cout<<"\t3. Ve elip \n";
    cout<<"\t4. Ve da giac\n";
    cin >> chon;
    if(chon == 1)
    {
      int a[100];
      for(int i = 0; i < 4; i++)
    {
        Textcolor(10);
        cout <<"\tNhap diem "<<i<<"\t"; cin >> a[i];
    }
       midpoint(a[0],a[1],a[2],a[3],10);
       outtextxy(a[0],a[1],"A"); outtextxy(a[2],a[3],"B");
       getch();
    }
    else if(chon == 2)
    {
        Textcolor(10);
        int x,y,r;
        cout<<"\tNhap x = "; cin >> x;
        cout<<"\tnhap y = "; cin >> y;
        cout<<"\tNhap ban kinh r = "; cin >> r;
        drawCircleMidpoint(x,y,r,10);
        getch();
    }
    else if(chon == 3)
    {
        int x,y,Rx,Ry;
        cout<<"\tNhap x = "; cin >> x;
        cout<<"\tnhap y = "; cin >> y;
        cout<<"\tNhap Rx = "; cin >> Rx;
        cout<<"\tNhap Ry = "; cin >> Ry;
        ellipseBR(x,y,Rx,Ry,10);
        getch();
    }
    else if(chon == 4)
    {
        int v;
        point2d p[v];
        cout<<"\tNhap so dinh da giac : "; cin >> v;
        nhapdagiac(p,v);
        vedagiac(p,v);
        getch();
    }
   }
}

int main()
{
    initwindow(800,600);
    menu();
}
