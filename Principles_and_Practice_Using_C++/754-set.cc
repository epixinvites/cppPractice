#include <iostream>
#include <set>
#include <string>
struct Item{
    std::string name;
    int count;
    Item(std::string name, int count);
};
std::ostream &operator<<(std::ostream &os, const Item &item){
    return os<<item.name<<','<<item.count;
}
Item::Item(std::string name, int count):name{name},count{count}{}
struct Item_order{
    bool operator()(const Item &a, const Item &b) const{
	return a.name<b.name;
    }
};
int main(){
    std::set<Item,Item_order> inventory;
    inventory.insert(Item("Item1",1));
    inventory.insert(Item("Item2",2));
    for(auto p = inventory.begin(); p!=inventory.end(); p++){
	std::cout<<*p<<std::endl;
    }
}
