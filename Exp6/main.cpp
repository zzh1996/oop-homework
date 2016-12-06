#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class Histogram : public Fl_Box {
    void draw() {
        Fl_Box::draw();
        fl_color(FL_WHITE);
        fl_rectf(0, 0, 800, 800);
        fl_color(FL_BLACK);
        fl_line(0, 700, 800, 700);
        fl_line(100, 0, 100, 800);
        fl_draw(xunit.c_str(), 750, 720);
        fl_draw(yunit.c_str(), 20, 20);
        auto xmin = min_element(xs.begin(), xs.end());
        auto xmax = max_element(xs.begin(), xs.end());
        auto ymin = min_element(ys.begin(), ys.end());
        auto ymax = max_element(ys.begin(), ys.end());

        for (int i = xs.size() - 1; i >= 0; i--) {
            int x = 150 + (xs[i] - *xmin) / (*xmax - *xmin) * 500;
            int y = 650 - (ys[i] - *ymin) / (*ymax - *ymin) * 500;
            fl_color(FL_BLACK);
            char buff[100];
            sprintf(buff, "%g", xs[i]);
            fl_draw(buff, x + 15, 720);
            sprintf(buff, "%g", ys[i]);
            fl_draw(buff, 80, y + 5);
            fl_color(FL_BLACK);
            fl_line_style(FL_DOT, 1, NULL);
            fl_line(100, y, x, y);
            if (ys.begin() + i == ymax || ys.begin() + i == ymin)
                fl_color(FL_RED);
            else
                fl_color(FL_DARK_BLUE);
            fl_rectf(x, y, 40, 700 - y);
        }
    }

    vector<double> xs;
    vector<double> ys;
    string xunit;
    string yunit;

public:
    Histogram(vector<double> xs, vector<double> ys, string xunit, string yunit)
            : Fl_Box(0, 0, 800, 800, ""), xs(xs), ys(ys), xunit(xunit), yunit(yunit) {}
};

int main() {
    ifstream infile("input.txt");
    vector<double> xs, ys;
    double t;
    for (int i = 1; i <= 12; i++) {
        xs.push_back(i);
        infile >> t;
        ys.push_back(t);
    }
    infile.close();
    Fl_Window window(800, 800, "Histogram");
    Histogram histogram(xs, ys, "month", "temperature");
    window.show();
    return Fl::run();
}