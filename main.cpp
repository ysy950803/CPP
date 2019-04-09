#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// 1
class Test {
public:
    mutable int v;

    int add(int a, int b);
};

int Test::add(int a, int b) {
    return a + b + v;
}

// 2
extern int count;
int count = 0;

void print_int(int value) {
    cout << value << endl;
}

// 6
static auto print_string(string value) {
    cout << value << endl;
    return value;
}

// 7
extern string extern_test(const string &value);

// 9
auto lamda1 = [](int x, int y) -> bool {
    count++;
    return x < y;
};

// 10
void print_double(double value) {
    cout << value << endl;
}

int main() {
    // 2
    int count = 1;
    print_int(count);
    print_int(::count);
    {
        int count = 2;
        print_int(count);
        print_int(::count);
    }

    // 3
    {
        wchar_t wc1 = '1234';
        wchar_t wc2 = 1234567890;
        print_int(wc1);
        print_int(wc2);
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
        print_int(c);
    }

    // 6
    {
        auto at1 = 2;
        auto at2('c');
        auto at3("string");
        print_int(at1);
        print_string(at3);
    }

    // 7
    print_string(extern_test("CPP is NB."));

    // 8
    thread_local int local_int = 10;
    for (;;) {
        local_int--;
        if (local_int == 0)
            break;
    }

    // 9
    print_int(lamda1(1, 2) ? 1 : 0);
    auto lamda2 = [](int x) { return ++x; };
    print_int(lamda2(4));

    // 10
    print_double(hypot(3, 4));
    print_double(fabs(-3.4));
    print_double(floor(5.6));
    print_double(log(exp(4)));

    // 11
    srand(time(nullptr));
    int rand1 = rand();
    long int rand2 = random();
    // printf("%d\n%ld", rand1, rand2);
    cout << rand1 << "\n" << setw(12) << rand2 << endl;

    // 12


    return 0;
}
