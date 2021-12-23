#include <vector>
class Point {};
class Shape{
public:
    virtual Point center() const = 0;
    virtual void move(Point to) = 0;
    virtual void draw() const = 0;
    virtual void rotate(int angle) = 0;
    virtual ~Shape(){}
};

class Circle:public Shape {
    Point x;
    int r;
public:
    Circle(Point p, int rad);
    Point center() const override{
        return x;
    }
    void move(Point to) override{
        x = to;
    }
    void draw() const override;
    void rotate(int) override;
};

class Smiley:public Circle{
    std::vector<Shape*> eyes;
    Shape* mouth;
public:
    Smiley(Point p, int rad):Circle{p, rad}, mouth{nullptr}{}
    ~Smiley(){
        delete mouth;
        for(auto p:eyes){
            delete p;
        }
    }
    void move(Point to) override;
    void draw() const override;
    void rotate(int) override;
};

void rotate_all(std::vector<Shape*> &v, int angle){
    for(auto p:v){
        p->rotate(angle);
    }
}

void Smiley::draw() const{
    Circle::draw();
    for(auto p:eyes){
        p->draw();
    }
    mouth->draw();
}
