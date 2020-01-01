/*---------------------------------------------------------------------*\
| SWERC 2015 - Saint John Festival (J)                                  |
| Author: Ana Paula Tomas                                               |
| Date: 14.11.2015                                                      |
| Approach:   O(L log L + S log H), where H is the number of vertices   |
|    in the convex hull of the large lanterns                           |
|  - finds the convex hull C of the large lanterns in O(L log L)        |
|    Graham scan                                                        |
|  - for checking if a small lantern is not in Exterior(C) uses         |
|    binary search, considering the planar decomposition determined     |
|    by the wedges (C_0,C_i,C_{i+1}), for i >= 1                        | 
|  - performs robust computations (no floating point operations)        |
\*---------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

// add extra filter to check whether the "small" point belongs to the 
// bounding box of the convex hull of the "large" ones
#define BOUNDINGBOX 1

#define MAXLARGE 10000
#define FALSE 0
#define TRUE  1

typedef struct point {
  long long x, y;
} POINT;

POINT L[MAXLARGE];
int C[MAXLARGE], N, Nhull;

#ifdef BOUNDINGBOX
long long Xmin,Xmax,Ymin,Ymax;
#endif

void read_points();
void swap(int k, int j);
void maxheapify(int k, int size);
void sort_for_GrahamScan();
void convex_hull();
int cmp_turn(POINT p,POINT q, POINT r);
int turn(POINT p,POINT q, POINT r);
int in_edge_degenerate(long long kx,long long dy, long long ky);
int in_edge(POINT p, int a, int b);
int in_wedge(POINT p, int u, int v, int *below, int *above);
int checkpoint(POINT p);

void read_points(){
  int i;
  for (i=0;i<N;i++)
    scanf("%lli%lli",&L[i].x,&L[i].y);
}

void swap(int k, int j) {
  POINT aux;
  aux = L[k];
  L[k] = L[j];
  L[j] = aux;
}

int cmp_turn(POINT p, POINT q, POINT r) {
  long long aux;
  int t;
  if((t = turn(p,q,r)))
    return t;
  // t ==0  collinear  (analyse inner product  <pq,qr>)
  aux = (q.x-p.x)*(r.x-q.x)+(q.y-p.y)*(r.y-q.y);
  if (aux > 0) return 1;
  if (aux < 0) return -1;
  return 0;
}

int turn(POINT p, POINT q, POINT r) {
  long long aux = (q.x-p.x)*(r.y-p.y)-(r.x-p.x)*(q.y-p.y);
  // cross product
  if (aux > 0)  return 1;   //(p,q,r) left turn
  if (aux < 0)  return -1;  //(p,q,r) right turn
  return 0;  // collinear
}

void maxheapify(int k, int size) {
  int leftson = 2*k, rightson = 2*k+1,  largest = k;

  if (leftson <= size && cmp_turn(L[0],L[largest],L[leftson]) > 0)
    largest = leftson;
  if (rightson <= size && cmp_turn(L[0],L[largest],L[rightson]) > 0)
    largest = rightson;
  if(largest != k) {
    swap(k,largest);
    maxheapify(largest,size);
  }
}

void sort_for_GrahamScan() {
  int  kmin = 0, i, size;
  // kmin points to the leftmost point with the smallest y 

#ifdef BOUNDINGBOX
  Xmin = Xmax = L[0].x;
  Ymin = Ymax = L[0].y;
#endif
  
  for(i=1; i< N;i++) {
    if (L[i].y < L[kmin].y || (L[i].y == L[kmin].y && L[i].x < L[kmin].x))
      kmin = i;
#ifdef BOUNDINGBOX
    if (L[i].y < Ymin) Ymin = L[i].y;
    else if (L[i].y > Ymax) Ymax = L[i].y;
    if (L[i].x < Xmin)  Xmin = L[i].x;
    else if (L[i].x > Xmax) Xmax = L[i].x;
#endif
  }

  // sort for rotational sweep in CCW fixed at L[0]
  if (kmin != 0)  swap(0,kmin);
  // ---- make heap and heapsort ---
  for(i = (N-1)/2; i > 0; i--)
    maxheapify(i,N-1);
  size = N-1;
  while(size > 1) {
    swap(1,size);
    size--;
    maxheapify(1,size);
  }
}


void convex_hull() {   // Based on Graham scan
  int i, t;

  C[0] = 0;  C[1] = 1;
  for (i = 2; i < N && turn(L[0],L[1],L[i])==0; i++) 
    C[1] = i;
  C[2] = i;  // at least three are not collinear
  Nhull = 3;

  for(++i; i < N; i++) {
    while ((t = turn(L[C[Nhull-2]],L[C[Nhull-1]],L[i])) < 0 || t == 0)
      Nhull--;
    C[Nhull++] = i;
  }

  // collinear points in last edge?
  if (turn(L[C[Nhull-2]],L[C[Nhull-1]],L[0]) == 0) Nhull--;  
}


int in_edge_degenerate(long long kx,long long dy, long long ky){
  if (kx != 0) return FALSE;
  // dx ==0  kx == 0  ky != 0
  if (dy < 0) {
    if (ky < 0 && dy < ky) return TRUE;
    return FALSE;
  }
  if (ky > 0 && dy > ky) return TRUE;
  return FALSE;
}

int in_edge(POINT p, int a, int b) {
  // works for distinct points  (p in the interior of segment ab?)
  long long dx = L[C[b]].x-L[C[a]].x, dy = L[C[b]].y-L[C[a]].y;
  long long kx = p.x -L[C[a]].x,  ky = p.y -L[C[a]].y;

  // check existence of solution   m dx = kx    m dy = ky   for  0 < m < 1
  if (dx == 0) return in_edge_degenerate(kx,dy,ky);
  if (dy == 0) return in_edge_degenerate(ky,dx,kx);

  if (kx*dy != ky*dx) return FALSE;
  // kx*dy == ky*dx implies kx and ky non null (all points are distinct)
  if (kx > 0 && dx > kx) return TRUE;
  // kx < 0
  if (kx < 0 && dx < kx) return TRUE;
  return FALSE;
}

// check if p is in the interior or boundary of wedge <(0,u);(0,v)> 
int in_wedge(POINT p, int u, int v, int *left, int *right) {
  *left = turn(L[C[0]],L[C[u]],p);
  *right = turn(L[C[0]],L[C[v]],p);

  // p to the left of (0,u) ?
  if (*left < 0) return FALSE;     

  // p to the right of (0,v) ?
  if (*right > 0) return FALSE;  

  return TRUE;  
}


int checkpoint(POINT p) {
  // based on binary search
  // wedges with apex at L[0] induced by a triangulation

  int  wm, wa, wb, left, right;

  // check wedge <0,Null-1,1>
  left = turn(L[C[0]],L[C[Nhull-1]],p);
  if (left > 0) return FALSE;
  if (left == 0) return in_edge(p,0,Nhull-1);
  right = turn(L[C[0]],L[C[1]],p);
  if (right < 0) return FALSE;
  if (right == 0) return in_edge(p,0,1);


  // number of triangles is Nhull-2
  wa = 1; wb = Nhull-2;
  
  while (wa <= wb) {
    wm = (wa+wb)/2;
    if (in_wedge(p,wm,wm+1,&left,&right)) {
      if (turn(L[C[wm]],L[C[wm+1]],p) < 0) 
	return FALSE;  // exterior of polygon
      return TRUE; // inside or on the boundary
    }
    if (right > 0)  // to the left of 0,wm+1
      wa = wm+1;
    else // right < 0 and left < 0  
      wb = wm-1; // to the right of 0,wm 
  }
  return FALSE;   // not needed; must return during the while cycle
}

int main() {
  int m, count = 0;
  POINT p;

  scanf("%d",&N);

  read_points();  // large balloons
  sort_for_GrahamScan();
  convex_hull();

  scanf("%d",&m);
  while(m-- > 0) {
    scanf("%lli%lli",&p.x,&p.y);
#ifdef BOUNDINGBOX
    if (p.x >= Xmin && p.x <= Xmax && p.y >= Ymin && p.y <= Ymax) 
      count += checkpoint(p);   // small balloon
#endif
#ifndef BOUNDINGBOX
    count += checkpoint(p);   // small balloon
#endif
  }
  printf("%d\n",count);
  return 0;
}

