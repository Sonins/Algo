#include <iostream>
#include <vector>

using namespace std;

const int L = 100;

struct point {
    double x, y;
};

class line {
    struct point p1;
    struct point p2;

   public:
    line(struct point src1, struct point src2) {
        if (src1.x < src2.x) {
            p1 = src1;
            p2 = src2;
        } else {
            p1 = src2;
            p2 = src1;
        }
    }

    double line_f(double x0) {
        return ((p1.y - p2.y) / (p1.x - p2.x)) * (x0 - p1.x) + p1.y;
    }

    bool operator<(line &l1) {
        return p2.x < l1.p1.x;
    }

    bool is_between(double x0) {
        return p1.x <= x0 && x0 <= p2.x;
    }
};

void decompose(vector<struct point> &src1,
               vector<struct point> &src2,
               vector<line> &dupper,
               vector<line> &dlower) {

    for (int i = 0; i < src1.size(); i++) {
        if (src1[i].x > src1[(i + 1) % src1.size()].x) {
            dupper.push_back(line(src1[i], src1[(i + 1) % src1.size()]));
        } else if (src1[i].x < src1[(i + 1) % src1.size()].x) {
            dlower.push_back(line(src1[i], src1[(i + 1) % src1.size()]));
        }
    }

    for (int i = 0; i < src2.size(); i++) {
        if (src2[i].x > src2[(i + 1) % src2.size()].x) {
            dupper.push_back(line(src2[i], src2[(i + 1) % src2.size()]));
        } else if (src2[i].x < src2[(i + 1) % src2.size()].x) {
            dlower.push_back(line(src2[i], src2[(i + 1) % src2.size()]));
        }
    }
}

double cal_dist(vector<line> &up, vector<line> &low, double x0) {
    double y_up = L + 1;

    for (int i = 0; i < up.size(); i++) {
        if (up[i].is_between(x0)) {
            y_up = min(y_up, up[i].line_f(x0));
        }
    }

    double y_low = -1;

    for (int i = 0; i < low.size(); i++) {
        if (low[i].is_between(x0)) {
            y_low = max(y_low, low[i].line_f(x0));
        }
    }

    if (y_up != L + 1)
        return y_up - y_low;
    else
        return -1;
}

double minx(vector<struct point> conv) {
    double x_min = L + 1;
    for (int i = 0; i < conv.size(); i++) {
        x_min = min(conv[i].x, x_min);
    }
    return x_min;
}

double maxx(vector<struct point> conv) {
    double x_max = -1;
    for (int i = 0; i < conv.size(); i++) {
        x_max = max(conv[i].x, x_max);
    }
    return x_max;
}

int main() {
    int C;
    cin >> C;
    cout.precision(10);
    cout << fixed;
    for (int tcase = 0; tcase < C; tcase++) {
        int N, M;
        cin >> N >> M;
        vector<struct point> conv1;
        vector<struct point> conv2;

        struct point p;

        for (int i = 0; i < N; i++) {
            cin >> p.x >> p.y;
            conv1.push_back(p);
        }

        for (int i = 0; i < M; i++) {
            cin >> p.x >> p.y;
            conv2.push_back(p);
        }

        vector<line> upper;
        vector<line> lower;
        decompose(conv1, conv2, upper, lower);

        double lo = max(minx(conv1), minx(conv2));
        double hi = min(maxx(conv1), maxx(conv2));

        for (int iter = 0; iter < 100; iter++) {
            double x1 = (2 * lo + hi) / 3;
            double x2 = (lo + 2 * hi) / 3;

            if (cal_dist(upper, lower, x1) < cal_dist(upper, lower, x2)) {
                lo = x1;
            } else {
                hi = x2;
            }
        }

        cout << max(0.0, cal_dist(upper, lower, lo)) << endl;
    }
    return 0;
}