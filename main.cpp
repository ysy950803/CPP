#include <iostream>

using namespace std;

// 1
class Test {
public:
    int v;

    int add(int a, int b);
};

int Test::add(int a, int b) {
    return a + b + v;
}

// 2
extern int count;
int count = 0;

void printInt(int value) {
    cout << value << endl;
}

int main() {
    int count = 1;
    printInt(count);
    printInt(::count);
    {
        int count = 2;
        printInt(count);
        printInt(::count);
    }

    // 3
    {
        wchar_t wc1 = '1234';
        wchar_t wc2 = 1234567890;
        printInt(wc1);
        printInt(wc2);
    }

    // 4
    {
        typedef short int shint;
        typedef long int loint;
        volatile loint li1 = 100;
    }

    // 5
    {
        enum color {
            red, green = 'g', blue = 5
        } c = blue;
        printInt(c);
    }

    // 6
    {
        int at1;
        auto at2 = 2;
    }
    return 0;
}
