#include "std_lib_facilities.h"
using namespace std;
const string inname = "test.in";
const string outname = "test.out";
const int not_a_reading = -7777;
const int not_a_month = -1;
constexpr int implausible_min = -200;
constexpr int implausible_max = 200;
vector<string> month_input_tbl {"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
vector<string> month_print_tbl {"January", "February", "March", "April", "May", "June", "July","August", "September", "October", "November", "December"};
/* Data example:
 { year 1990 }
 {year 1991 { month jun }}
 { year 1992 { month jan ( 1 0 61.5) } {month feb (1 1 64) (2 2 65.2) } }
 {year 2000
       { month feb (1 1 68 ) (2 3 66.66 ) ( 1 0 67.2)}
       {month dec (15 15 –9.2 ) (15 14 –8.8) (14 0 –2) }
 }
 */

void end_of_loop(istream &ist, char term, const string &message){
    if(ist.fail()){
        ist.clear();
        char ch;
        if(ist>>ch && ch==term){
            return;
        }
        throw runtime_error(message);
    }
}

int month_to_int(string s){
    for(int i = 0; i<12; i++){
        if(month_input_tbl[i]==s){
            return 1;
        }
    }
    return -1;
}

string int_to_month(int i){
    if(i<0||i>13){
        throw runtime_error("Bad month index");
    }
    return month_print_tbl[i];
}

struct Day {
    vector<double> hour{vector<double>(24,not_a_reading)};
};
struct Month{
    int month{not_a_month};
    vector<Day> day{32};
};
struct Year{
    int year;
    vector<Month> month{12};
};
struct Reading{
    int day;
    int hour;
    double temperature;
};

bool is_valid(const Reading &r){
    if(r.day<1||r.day>31){
        return false;
    }
    if(r.hour<0||r.hour>23){
        return false;
    }
    if(r.temperature<implausible_min||r.temperature>implausible_max){
        return false;
    }
    return true;
}

istream &operator>>(istream &is, Reading &r){ // format: ( 3 4 9.7 )
    char ch1;
    if(is>>ch1&&ch1!='('){
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }
    char ch2;
    int d, h;
    double t;
    is>>d>>h>>t>>ch2;
    if(!is||ch2!=')'){
        throw runtime_error("Bad reading");
    }
    r.day = d;
    r.hour = h;
    r.temperature = t;
    return is;
}

istream &operator>>(istream &is, Month &m){
    char ch = 0;
    if(is>>ch&&ch!='{'){
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }
    string month_marker, mm;
    is>>month_marker>>mm;
    if(!is||month_marker!="month"){
        throw runtime_error("Bad start of month");
    }
    m.month = month_to_int(mm);
    int duplicates = 0, invalids = 0;
    for(Reading r; is>>r;){
        if(is_valid(r)){
            if(m.day[r.day].hour[r.hour]!=not_a_reading){
                ++duplicates;
            }
            m.day[r.day].hour[r.hour]=r.temperature;
        }
        else{
            invalids++;
        }
    }
    if(invalids){
        throw runtime_error("Invalid readings in a month"+to_string(invalids));
    }
    if (duplicates) {
      throw runtime_error("Duplicate readings in month"+to_string(duplicates));
    }
    end_of_loop(is, '}',"Bad end to month");
    return is;
}

istream &operator>>(istream &is, Year &y){
    char ch; is>>ch;
    if(ch!='{'){
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }
    string year_marker;
    int yy;
    is>>year_marker>>yy;
    if(!is||year_marker!="year"){
        throw runtime_error("Bad start of year");
    }
    y.year=yy;
    while(true){
        Month m;
        if (!(is >> m)) {
          break;
        }
        y.month[m.month] = m;
    }
    end_of_loop(is, '}',"Bad end of year");
    return is;
}

int main(){
    ifstream ist{inname};
    ofstream ost{outname};
    if(!ist||!ost){
        throw runtime_error("Can't open files");
    }
    ist.exceptions(ist.exceptions()|ios_base::badbit);
    vector<Year> ys;
    while(true){
        Year y;
        if(!(ist>>y)){
            break;
        }
        ys.push_back(y);
    }
    cout<<"Read: "<<ys.size()<<" years of readings"<<endl;
}