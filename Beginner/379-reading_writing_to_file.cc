#include "std_lib_facilities.h"
using namespace std;
const string inname = "test.in";
const string outname = "test.out";
struct Reading{
    int hour;
    double temperature;
};

int main(){
    ifstream ist {inname};
    ofstream ost {outname};
    if(!ist||!ost){
        error("Cannot open input file");
    }
    vector<Reading> temps;
    int hour;
    double temperature;
    while(ist>>hour>>temperature){
        if(hour<0||hour>23){
            error("Out of range");
        }
        temps.push_back(Reading{hour, temperature});
    }
    for(int i = 0; i<temps.size(); i++){
        ost<<'(' << temps[i].hour << ',' << temps[i].temperature << ")\n";
    }
}
