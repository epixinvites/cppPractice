namespace My_code{
    class complex {};

    complex sqrt(complex);

    int main();
} // namespace My_code

int My_code::main(){
    // Something goes here
    return 0;
}

int main(){
    return My_code::main();
}
