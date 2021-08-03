#include "std_lib_facilities.h"
double *get_from_jack(int *count);
vector<double> *get_from_jill();
template<typename Iterator> Iterator high(Iterator first, Iterator last){
    Iterator high=first;
    for(Iterator p = first; p!=last; p++){
        if(*high<*p){high=p;}
    }
    return high;
}
void fct(){
    int jack_count = 0;
    double *jack_data = get_from_jack(&jack_count);
    vector<double> *jill_data = get_from_jill();
    vector<double> &v=*jill_data;
    double *jack_high = high(jack_data, jack_data+jack_count);
    double *jill_high = high(&v[0],&v[0]+v.size());
    cout<<"Jill's max: "<<*jill_high<<"; Jack's max: "<<*jack_high;
    delete[] jack_data;
    delete jill_data;
}
