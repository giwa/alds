#include <stdio.h>
#include <math.h>

struct Point {double x, y;};


int koch(int d, Point p1, Point p2) {
    if (d == 0) return 0;
    Point s, t, u;
    double th = M_PI * 60.0 / 180.0;

    s.x = (2.0 * p1.x + 1.0 * p2.x)/3.0;
    s.y = (2.0 * p1.y + 1.0 * p2.y)/3.0;
    t.x = (1.0 * p1.x + 2.0 * p2.x)/3.0;
    t.y = (1.0 * p1.y + 2.0 * p2.y)/3.0;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

    koch(d - 1, p1, s);
    printf("%8f %8f\n", s.x, s.y);
    koch(d - 1, s, u);
    printf("%8f %8f\n", u.x, u.y);
    koch(d - 1, u, t);
    printf("%8f %8f\n", t.x, t.y);
    koch(d - 1, t, p2);
}

int main() {
    Point a, b;
    int n;

    scanf("%d", &n);
    a.x = 0;
    a.y = 0;
    b.x = 100;
    b.y = 0;

    printf("%8f %8f\n", a.x, a.y);
    koch(n, a, b);
    printf("%8f %8f\n", b.x, b.y);

}
