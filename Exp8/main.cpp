#include <iostream>
#include <cmath>

using namespace std;

class Complex {
public:
    Complex() : re(0), im(0) {}

    Complex(double r, double i) : re(r), im(i) {}

    Complex(double r) : re(r), im(0) {}

    Complex(const Complex &a) : re(a.re), im(a.im) {}

    friend Complex operator+(const Complex &a, const Complex &b);

    friend Complex operator-(const Complex &a);

    friend Complex operator-(const Complex &a, const Complex &b);

    friend Complex operator*(const Complex &a, const Complex &b);

    friend Complex operator/(const Complex &a, const Complex &b);

    friend bool operator==(const Complex &a, const Complex &b);

    friend bool operator!=(const Complex &a, const Complex &b);

    friend istream &operator>>(istream &in, Complex &a);

    friend ostream &operator<<(ostream &out, const Complex &a);

    friend double abs(const Complex &a);

    Complex &operator=(const Complex a);

    Complex &operator+=(const Complex a);

    Complex &operator-=(const Complex a);

    Complex &operator*=(const Complex a);

    Complex &operator/=(const Complex a);

    operator double() const;

private:
    double re, im;
};

Complex operator+(const Complex &a, const Complex &b) {
    return Complex(a.re + b.re, a.im + b.im);
}

Complex operator-(const Complex &a) {
    return Complex(-a.re, -a.im);
}

Complex operator-(const Complex &a, const Complex &b) {
    return a + (-b);
}

Complex operator*(const Complex &a, const Complex &b) {
    return Complex(a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re);
}

Complex operator/(const Complex &a, const Complex &b) {
    return Complex((a.re * b.re + a.im * b.im) / (b.re * b.re + b.im * b.im),
                   (a.im * b.re - a.re * b.im) / (b.re * b.re + b.im * b.im));
}

bool operator==(const Complex &a, const Complex &b) {
    return a.re == b.re && a.im == b.im;
}

bool operator!=(const Complex &a, const Complex &b) {
    return !(a == b);
}

istream &operator>>(istream &in, Complex &a) {
    char t;
    in >> a.re >> a.im >> t;
    return in;
}

ostream &operator<<(ostream &out, const Complex &a) {
    if (a.im == 0) {
        out << a.re;
    } else if (a.re == 0) {
        if (a.im == -1)out << "-";
        else if (a.im != 1)out << a.im;
        out << "i";
    } else {
        cout << a.re;
        if (a.im > 0)cout << "+";
        if (a.im == -1)out << "-";
        else if (a.im != 1)out << a.im;
        out << "i";
    }
    return out;
}

double abs(const Complex &a) {
    return sqrt(a.re * a.re + a.im * a.im);
}

Complex &Complex::operator=(const Complex a) {
    re = a.re;
    im = a.im;
    return *this;
}

Complex &Complex::operator+=(const Complex a) {
    *this = *this + a;
    return *this;
}

Complex &Complex::operator-=(const Complex a) {
    *this = *this - a;
    return *this;
}

Complex &Complex::operator*=(const Complex a) {
    *this = *this * a;
    return *this;
}

Complex &Complex::operator/=(const Complex a) {
    *this = *this / a;
    return *this;
}

Complex::operator double() const {
    return re;
}

int main() {
    Complex a, b;
    cout << "Input complex number a:";
    cin >> a;
    cout << "Input complex number b:";
    cin >> b;
    cout << "a+b=" << a + b << endl;
    cout << "a-b=" << a - b << endl;
    cout << "a*b=" << a * b << endl;
    cout << "a/b=" << a / b << endl;
    cout << "a==b:" << (a == b) << endl;
    cout << "a!=b:" << (a != b) << endl;
    cout << "(double)a=" << (double) a << endl;
    cout << "abs(a)=" << abs(a) << endl;
    Complex c(b);
    cout << "c(b);c=" << c << endl;
    c = a;
    cout << "c=a;c=" << c << endl;
    c += b;
    cout << "c+=b;c=" << c << endl;
    c -= b;
    cout << "c-=b;c=" << c << endl;
    c *= b;
    cout << "c*=b;c=" << c << endl;
    c /= b;
    cout << "c/=b;c=" << c << endl;
    return 0;
}

