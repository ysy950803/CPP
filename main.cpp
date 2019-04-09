#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>

using namespace std;

// 1
class Test {
public:
    mutable int v = 0;

    virtual int test_add(int a, int b) {
        return a - b + v;
    }

    virtual float base() = 0;
};

//int Test::test_add(int a, int b) {
//    return a + b + v;
//}

class TSon : public Test {
private:
protected:
public:
    int test_add(int a, int b) override {
        return a - b + v + v;
    }
};

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

// 12+
void main_12_forward();

int main() {
    // 1
    Test *test;
    TSon tSon{};
    test = &tSon;

    test->v = 10;
    print_int(test->test_add(test->v, 0));
    tSon.v = 11;
    print_int(tSon.test_add(tSon.v, 0));

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
    {
        thread_local int local_int = 10;
        for (;;) {
            local_int--;
            if (local_int == 0)
                break;
        }
    }

    // 9
    {
        print_int(lamda1(1, 2) ? 1 : 0);
        auto lamda2 = [](int x) { return ++x; };
        print_int(lamda2(4));
    }

    // 10
    {
        print_double(hypot(3, 4));
        print_double(fabs(-3.4));
        print_double(floor(5.6));
        print_double(log(exp(4)));
    }

    // 11
    {
        srand(time(nullptr));
        int rand1 = rand();
        long int rand2 = random();
        // printf("%d\n%ld", rand1, rand2);
        cout << rand1 << "\n" << setw(12) << rand2 << endl;
    }

    main_12_forward();

    return 0;
}

// 12
template<class T>
int arr_len(T &array) {
    return sizeof(array) / sizeof(array[0]);
}

void test_arr1(double *arr /*same: arr[], arr[3]*/) {
    print_int(arr_len(arr));
}

// 13
double *pow2(double v1, double v2) {
    static double res[2];
    res[0] = pow(v1, 2);
    *(res + 1) = pow(v2, 2);
    return res;
}

void main_12_forward() {
    // 12
    double *p1;
    double arr1[3] = {7, 8, 9};
    p1 = arr1; // same: = &arr1[0]
    cout << &p1 << ' ' << &arr1 << endl; // not same

    cout << p1 << ' ' << &p1[0] << endl; // same
    cout << arr1 << ' ' << &arr1[0] << endl; // same

    cout << p1[1] << *&p1[1] << *(p1 + 1) << endl; // same
    cout << arr1[1] << *&arr1[1] << *(arr1 + 1) << endl; // same

    /*
     * 当数组传入函数时，传入的是指针，指针仅指向数组头arr[0]，不带有任何长度信息
     * 请牢记：如果把数组作为参数传入函数，那么这个数组会退化为一个指针int *arr
     */
    test_arr1(p1); // 1
    test_arr1(arr1); // 1
    print_int(arr_len(p1)); // 1
    print_int(arr_len(arr1)); // 3

    // 13
    double *p2 = pow2(2, 3);
    print_double(p2[1]);

    // TODO 14 还需深入研究
    {
        cout << endl;
        char hello[] = "Hello";
        char lo[] = "lo";

        print_int(arr_len(hello)); // len = 6, end is '\0'
        cout << strlen(hello) << endl; // len = 5

        strcpy(hello, "Hel");
        cout << hello << endl
             << strcmp(hello, lo) << endl;

        strcat(hello, lo);
        cout << hello << endl;

        char *o_p = strchr(hello, 'o');
        char *lo_p = strstr(hello, lo);
        cout << o_p << endl
             << lo_p << endl;
    }
}
