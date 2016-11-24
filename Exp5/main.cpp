#include<FL/Fl.H>
#include<FL/Fl_Box.H>
#include<FL/Fl_Window.H>
#include<FL/fl_draw.H>

class MyBox : public Fl_Box {
    void draw() {
        Fl_Box::draw();
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if ((i + j) % 2)
                    fl_color(FL_RED);
                else
                    fl_color(FL_WHITE);
                fl_rectf(i * 100, j * 100, 100, 100);
            }
        }
    }

public:
    MyBox(int x, int y, int x1, int y1) : Fl_Box(x, y, x1, y1, "") {}
};

int main() {
    Fl_Window window(800, 800, "ChessBoard");
    MyBox box(0, 0, 800, 800);
    window.show();
    return Fl::run();
}