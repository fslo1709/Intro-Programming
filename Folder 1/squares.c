#include <stdio.h> 
#include <math.h>
#include <string.h>
#define eps 1e-10
typedef struct {
    double x, y;
} Pt;
Pt subtract(Pt a, Pt b) {
	Pt c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
    return c;
}
double dot(Pt a, Pt b) {
    return a.x * b.x + a.y * b.y;
}
double cross(Pt a, Pt b) {
    return (a.x)*(b.y)-(a.y)*(b.x);
}
int between(Pt a, Pt b, Pt c) {
    return dot(subtract(c, a), subtract(b, a)) >= -eps && dot(subtract(c, b), subtract(a, b)) >= -eps;
}
int onSeg(Pt a, Pt b, Pt c) {
    return between(a, b, c) && fabs(cross(a, b)) < eps;
}
int inPolygon(Pt p[], int n) {
    int i, j, cnt = 0;
	Pt q;
	q.x=0, q.y=0;
    for (i = 0, j = n-1; i < n; j = i++) {
        if(onSeg(p[i], p[j], q))
            return 1;
        if(p[i].y > q.y != p[j].y > q.y &&
        q.x < (p[j].x-p[i].x)*(q.y-p[i].y)/(p[j].y-p[i].y) + p[i].x)
        cnt++;
    }
    return cnt&1;
}
int main() {
	int i;
	Pt p[4];
	double x, y;
	for (i = 0; i < 4; i++) {
		scanf("%lf %lf", &x, &y);
		p[i].x = x, p[i].y = y;
	}
	printf("%d\n", inPolygon(p, 4));
	return 0;
}
