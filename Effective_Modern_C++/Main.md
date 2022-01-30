# Effective Modern C++

<!-- vim-markdown-toc GFM -->

* [Terminologies](#terminologies)
	* [lvalues and rvalues](#lvalues-and-rvalues)
		* [lvalues](#lvalues)
		* [rvalues](#rvalues)

<!-- vim-markdown-toc -->

## Terminologies
### lvalues and rvalues
#### lvalues
In short, it's something that can only go to the left-hand side of an assignment, as long as it isn't `const` qualified.

For example:
```cpp
std::string s;
s = "Hello world"; // s is a lvalue expression
int x;
x = 0; // x is a lvalue expression
```

Here's another example:
```cpp
void f(const int& x){
	std::cout<<x<<std::endl;
}
int main(){
	f(123);
}
```
Here, `123` isn't a variable, it's a lvalue. 

Why? In the function `f()` it takes a parameter of reference type. An expression of reference type, as the name implies, requires an address to be able to refer to something. `123` by itself is a rvalue, but the function `f()`'s parameter type `const int&` requires an address. Hence, 123 is assigned an address and becomes a lvalue.

#### rvalues
We've briefly touched rvalues in the above, and as you can guess, it's the opposite of lvalues. Rvalues, as the name indicates, goes to the right-hand side of an assignment.

A rvalue does not have a address, it can be
- Temporary objects returned from functions
- Objects that are eligible for move operations
- An unnamed object or a member of an object which is not a reference

For example:
```cpp
std::string f(){return "Hello world";}

struct X{
	std::string s;
};

std::string s;
s = "Hello world"; 	// 1
s = f();			// 2
s = X().s;			// 3

int&& a = 10; 		// 4
```
1. `s` is assigned "Hello world", "Hello world" is a temporary object, hence making it a rvalue
2. As stated above, temporary objects returned from functions are rvalues
3. Temporary object X is a rvalue, therefore the member of `s` in struct `X` is also a rvalue
4. Ok, here's something different. The 10 assigned to `a` here is no longer a rvalue, as int&& means a reference to a rvalue, hence the 10 here is now given an address where it can be referred to, which now makes it a lvalue.

