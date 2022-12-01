#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<iostream>
using namespace std;

struct ToaDo
{
 int x,y;
};
 void vedagiac(ToaDo p[],int v)
 {
     for(int i=0;i<v;i++)
        line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
 }
 void nhapdagiac(ToaDo p[],int v)
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
void scanline(ToaDo p[],int v)
{
    int xmin,xmax,ymin,ymax,c,mang[50];
    xmin=xmax=p[0].x;
    ymin=ymax=p[0].y;
    for(int i=0;i<v;i++)
    {
        if(xmin>p[i].x) xmin=p[i].x;
        if(xmax<p[i].x) xmax=p[i].x;
        if(xmax>p[i].y) xmax=p[i].y;
        if(xmax<p[i].y) xmax=p[i].y;
        float y;
        y=ymin+0.01;
        while(y<=ymax)
        {
            int x,x1,x2,y1,y2,tg;
            c=0;
            for(int i=0;i<v;i++)
            {
                x1=p[i].x;
                y1=p[i].y;
                x2=p[i+1].x;
                y2=p[i+1].y;
                if(y2<y1){
                    tg=x1;x1=x2;x2=tg;
                    tg=y1;y1=y2;y2=tg;
                }
                if(y<=y2&&y>=y1){
                    if(y1==y2) x=x1;
                    else{
                        x=((y-y1)*(x2-x1)/(y2-y1));
                        x=x+x1;
                    }
                    if(x<=xmax && x>=xmin)
                        mang[c++]=x;
                }
            }
            for(int i=0;i<c;i+=2){
                    delay(10);
            line(mang[i],y,mang[i+1],y);

            }
            y++;
        }
}
}
int main()
{
    initwindow(600,700);
    int c1,v;
    do{
        cout<<"\n nhap vao so dinh cua da giac:";cin>>v;
    }while(v<3);
    ToaDo p[v];
    nhapdagiac(p,v);
    //cout<<"\nchon mau (0-15)";cin>>c1;
    vedagiac(p,v);
    setcolor(10);
    scanline(p, v);
    getch();
    //closegraph();
}