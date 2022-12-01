#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
struct poite2d
{
    int x,y;
};
poite2d p1,p2,p3,p4;
void khoitao()
{
    p1.x = 100;
    p1.y = 100;
    p2.x = 200;
    p2.y = 100;
    p3.x = 200;
    p3.y = 200;
    p4.x = 100;
    p4.y = 200;
}
void velai()
{
    setcolor(GREEN); setlinestyle(0,0,3);
    line(p1.x,p1.y,p2.x,p2.y); outtextxy(p1.x-15,p1.y,"A");
    line(p2.x,p2.y,p3.x,p3.y); outtextxy(p2.x+10,p2.y,"B");
    line(p3.x,p3.y,p4.x,p4.y); outtextxy(p3.x+10,p3.y,"C");
    line(p4.x,p4.y,p1.x,p1.y); outtextxy(p4.x-15,p4.y,"D");
}
void tinhtienx(int dis)
{
    p1.x += dis;
    p2.x += dis;
    p3.x += dis;
    p4.x+=dis;
}
void tinhtieny(int dis)
{
    p1.y += dis;
    p2.y += dis;
    p3.y += dis;
    p4.y+=dis;
}
void keyboad(int c, int n)
{
     while(true)
    {
        c = getch();
        if(c == 0)
        c=getch();
        cleardevice();
        switch (c)
        {
        case 27:
            exit(1);
        case 75: /* phím trái */
            tinhtienx(-1);
            velai();
            break;
        case 77: /* phím phải */
            tinhtienx(+1);
            velai();
            break;
        case 72:  /*phím lên */
            tinhtieny(-1);
            velai();
            break;
        case 80: /* phím xuống*/
            tinhtieny(+1);
            velai();
            break;
        }
    }
}
int main()
{
    initwindow(600,600);
    int c=0,n;
    khoitao();
    velai();
    keyboad(c,n);
    getch();
    closegraph();
    return 0;
}
