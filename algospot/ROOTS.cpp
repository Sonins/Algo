#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const double L = 10;

vector<double> differentiate(const vector<double> &poly) {
    vector<double> result;
    double n = poly.size() - 1;

    for (double i = 0; i < poly.size() - 1; i++) {
        result.push_back(poly[i] * (n - i));
    }

    return result;
}

double eval(const vector<double> &poly, double x0) {
    double result = 0;

    for (int i = 0; i < poly.size(); i++) {
        result += poly[poly.size() - 1 - i] * pow(x0, i);
    }

    return result;
}

vector<double> solve_naive(const vector<double> &poly) {
    vector<double> result;

    if (poly.size() > 3 || poly.size() < 2) {
        fprintf(stderr, "%dth equation cannot be solved by solve_naive\n", poly.size());
        exit(EXIT_FAILURE);
    }

    if (poly.size() == 2) {
        result.push_back(poly[1] * -1 / poly[0]);
        return result;
    }

    double a = poly[0];
    double b = poly[1];
    double c = poly[2];

    result.push_back((-b - sqrt(b * b - 4 * a * c)) / (2 * a));
    result.push_back((-b + sqrt(b * b - 4 * a * c)) / (2 * a));

    return result;
}

vector<double> solve(const vector<double> &poly) {
    if (poly.size() <= 3) {
        return solve_naive(poly);
    }

    vector<double> derivative = differentiate(poly);
    vector<double> extreme = solve(derivative);
    vector<double> result;

    extreme.insert(extreme.begin(), -L - 1);
    extreme.insert(extreme.end(), L + 1);
    
    for (int i = 1; i < extreme.size(); i++) {
        double x1 = extreme[i - 1];
        double x2 = extreme[i];
        double y1 = eval(poly, x1);
        double y2 = eval(poly, x2);

        if (y1 * y2 > 0) continue;

        if (y1 > y2) {
            swap(y1, y2);
            swap(x1, x2);
        }

        for (int iter = 0; iter < 100; iter++) {
            double mx = (x1 + x2) / 2;
            double my = eval(poly, mx);

            if (my * y1 > 0) {
                x1 = mx;
                y1 = my;
            } else {
                x2 = mx;
                y2 = my;
            }
        }
        result.push_back((x1 + x2) / 2);
    }

    sort(result.begin(), result.end());
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    int C;
    cin >> C;

    int n;
    vector<double> coef;
    double input;

    for (int c = 0; c < C; c++) {
        
        cin >> n;

        for (int i = 0; i < n + 1; i++) {
            cin >> input;
            coef.push_back(input);
        }

        vector<double> result = solve(coef);
        
        cout.precision(10);
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << ' ';
        }
        cout << endl;
        coef.clear();
    }
    return 0;
}