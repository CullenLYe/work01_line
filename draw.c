#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int x = x0;
  int y = y0;
  int dx = x1-x0;
  int dy = y1-y0;
  if (x1<x0) {
    x=x1;
    y=y1;
    dx*=-1;
    dy*=-1;
  }
  int a, b, d, e, f;
  e=x+dx;
  f=y+dy;
  if (!dx) { // Vertical line
    while (y<=y1) {
      plot(s,c,x,y);
      y++;
    }
  }
  if (!dy) { // Horizontal line
    while (x<=x1) {
      plot(s,c,x,y);
      x++;
    }
  }
  if (dy==dx) { // Slope 1
    while (x<=x1) {
      plot(s,c,x,y);
      x++;
      y++;
    }
  }
  if (-dy==dx) { // Slope -1
    while (y>=y1) {
      plot(s,c,x,y);
      x++;
      y--;
    }
  }
  else if (dx>dy && dy>0) { // Octant 1 and 5
    a=dy;
    b=-dx;
    d=2*a+b;
    e=x+dx;
    while (x<=e) {
      plot(s,c,x,y);
      if (d>0) {
        y++;
        d+=2*b;
      }
      x++;
      d+=2*a;
    }
  }
  else if (dy>dx) { // Octant 2 and 6
    a=dx;
    b=-dy;
    d=2*b+a;
    f=y+dy;
    while (y<=f) {
      plot(s,c,x,y);
      if (d>0) {
        x++;
        d+=2*b;
      }
      y++;
      d+=2*a;
    }
  }
  else if (-dy>dx) { // Octant 3 and 7
    a=dx;
    b=-dy;
    d=2*a-b;
    while (y>=f) {
      plot(s,c,x,y);
      if (d>0) {
        x++;
        d-=2*b;
      }
      y--;
      d+=2*a;
    }
  }
  else { // Octant 4 and 8
    a=dy;
    b=-dx;
    d=2*a-b;
    while (x<=e) {
      plot(s,c,x,y);
      if (d<0) {
        y--;
        d-=2*b;
      }
      x++;
      d+=2*a;
    }
  }

}