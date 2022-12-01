
#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include <dos.h>
#include <math.h>

using namespace std;

struct toado
{
    int x,y;
};
void nhaptoado(toado p[],int v)
{
int i;
for (i=0;i<v;i++)
{
    std::cout << "nhap toa do diem" <<(i+1)<<":"<<std::endl;
    std::cout << "Tx[" <<(i+1)<<"]=n"<< std::endl;  
    cin >>p[i].x;
    std::cout << "Ty[" <<(i+1)<<"]=n"<< std::endl;  
    cin >>p[i].y;
}
p[i].x=p[0].x;
p[i].y=p[0].y;
}
void vedagiac(toado p[], int v)
{
    for (int i = 0; i < v; i++)
    {
        line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
    }
}
void dbien(int x, int y, int mt, int mb)
{
    if (getpixel(x,y)!=mt && getpixel(x,y)!= mb)
    {
        delay(0.1);
        putpixel(x,y,mt);
        dbien(x-1,y,mt,mb);
        dbien(x+1,y,mt,mb);
        dbien(x,y-1,mt,mb);
        dbien(x,y+1,mt,mb);
    }
    
}
int main()
{
    initwindow(800,800);
    int v;
    do
    {
        std::cout << "nhap so dinh da giac :" << std::endl; cin>>v;
    } while (v<3);
    toado p[v];
    nhaptoado(p,v);
    vedagiac(p,v);
    dbien(200,200,5,15);
    getch();
    return 0;
}
