#include "std_lib_facilities.h"
using namespace std;
enum class Month{
    jan=1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
};

class Year{
private:
    static const int min = 1970;
    static const int max = 2100;
    int y;
public:
    class Invalid {};
    Year(int x):y{x}{
        if (x < min || x >= max) {
            throw Invalid{};
        }
    }
    int year(){
        return y;
    }
};

class Date{
private:
    int y;
    Month m;
    int d;
public:
    Date(Year y, Month m, int d);
};
