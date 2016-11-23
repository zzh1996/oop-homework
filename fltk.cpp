#include<FL/Fl.h>
#include<FL/Fl_Box.h>
#include<FL/Fl_Window.h>

int main(){
	Fl_Window window(200,200,"Title");
	Fl_Box box(0,0,200,200,"Hello, zzh");
	window.show();
	return Fl::run();
}

