#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    double x, y;
};

/*
    _/\_
    each point in koch curbe; start, s, u, t, end

    calculation of midpoints in a line, which devide internally as m : n.
    when A(x1, y1), B(x2, y2),
    ((n * x1 + m * x2)/(m + n), (n * y1 + m * y2/(m + n))

    rotation matrix:
    R = [[cosZ, -sinZ], [sinZ, cosZ]]
    rotated vector:
    v' = R * v = [xcosZ - ysinZ, xsinZ + ycosZ]
*/
void koch(Point start, Point end, int count)
{
    if (count == 0)
        return;

    Point s, t, u;
    s.x = (2.0 * start.x + 1.0 * end.x) / 3.0;
    s.y = (2.0 * start.y + 1.0 * end.y) / 3.0;
    t.x = (1.0 * start.x + 2.0 * end.x) / 3.0;
    t.y = (1.0 * start.y + 2.0 * end.y) / 3.0;

    double th = M_PI * 60.0 / 180.0;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

    koch(start, s, count - 1);
    printf("%.8f %.8f\n", s.x, s.y);
    koch(s, u, count - 1);
    printf("%.8f %.8f\n", u.x, u.y);
    koch(u, t, count - 1);
    printf("%.8f %.8f\n", t.x, t.y);
    koch(t, end, count - 1);
}

int main()
{
    int n;
    cin >> n;

    Point start = {x : 0.0, y : 0.0};
    Point end = {x : 100.0, y : 0.0};

    printf("%.8f %.8f\n", start.x, start.y);
    koch(start, end, n);
    printf("%.8f %.8f\n", end.x, end.y);

    return 0;
}
