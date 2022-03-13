#include <iostream>

using namespace std;

int is_one_line(double x1, double y1, double x2, double y2, double x3, double y3) {
    if ((y1 - y2) * x3 + (x2 - x1) * y3 + (x1 * y2 - x2 * y1) == 0.0) {
        return 1;
    }
    return 0;
}


void check_triangle_or_rectangle() {
    double xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya;
    cin >> xb >> yb;
    cin >> xc >> yc;

    if (is_one_line(xa, ya, xb, yb, xc, yc)) {
        cout << "Correct";
    } else {
        cout << "Incorrect";
    }
}

double triangle_area(double x1, double y1, double x2, double y2, double x3, double y3) {
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

int intersect(double a, double b, double c, double d) {
    if (a > b) {
        swap(a, b);
    }
    if (c > d) {
        swap(c, d);
    }
    return max(a, c) <= min(b, d);
}

void check_segments_intersect() {
    double xa, ya, xb, yb, xc, yc, xd, yd, x, y;
    cin >> xa >> ya;
    cin >> xb >> yb;
    cin >> xc >> yc;
    cin >> xd >> yd;

    if (!(intersect(xa, xb, xc, xd)
    && intersect(ya, yb, yc, yd)
    && triangle_area(xa, ya, xb, yb, xc, yc) * triangle_area(xa, ya, xb, yb,xd, yd) <= 0
    && triangle_area(xc, yc, xd, yd, xa, ya) * triangle_area(xc, yc, xd, yd, xb, yb) <= 0))
    {
        cout << "Incorrect";
        return;
    }
    x = ((xd - xc) * (ya - yc) - (yd - yc) * (xa - xc)) / ((yd - yc) * (xb - xa) - (xd - xc) * (yb - ya));
    y = ((xb - xa) * (ya - yc) - (yb - ya) * (xa - xc)) / ((yd - yc) * (xb - xa) - (xd - xc) * (yb - ya));

    cout << x << ' ' << y;
}

int main() {
    // check_triangle_or_rectangle()
    // check_segments_intersect();
    return 0;
};

