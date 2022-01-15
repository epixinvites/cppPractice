class X{
public:
    X(int);
    X();
    X(const X&); // copy constructor
    X(X&&); // move constructor
    X& operator=(const X&); // copy assignment - clean up target and move
    X& operator=(X&&); // move assignment - clean up target and move
    ~X();
};
