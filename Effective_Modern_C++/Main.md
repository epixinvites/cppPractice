# Effective Modern C++

- Please note, this document is written based on my understanding of the book, and I may have added and left out bits of information. If you find any of the below factually or gramatically incorrect, please open an issue to correct them.

<!-- vim-markdown-toc GFM -->

* [Terminologies](#terminologies)
	* [lvalues and rvalues](#lvalues-and-rvalues)
		* [lvalues](#lvalues)
		* [rvalues](#rvalues)
		* [Initializing an object with another object](#initializing-an-object-with-another-object)
	* [Declaring and defining](#declaring-and-defining)
* [Deducing Types](#deducing-types)

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

#### Initializing an object with another object
When an object is initialized with another object of the same type, for example `int x = 123`, the new object is said to be a copy of the initializing object. 

Well, copy, in C++, it can be differentiated into two types
- Move constructed
	- Copies of rvalues are usually move constructed
	- `auto obj1 = std::move(obj2)` <- this calls the move constructor
		- The data that obj2 pointed to is transfered to obj1. Obj2 is now a nullptr, while obj1 now points to the data obj2 originally pointed to. 
- Copy constructed
	- Copies of lvalues are usually copy constructed
	- `auto obj1 = obj2` <- this calls the copy constructor
		- obj1 allocates memory and copies obj2's data for itself. The content of obj1 and obj2 is the same, but the both of them point to different parts of the memory.

```cpp
std::vector<int> obj1{1, 2, 3, 4, 5};
auto obj2 = obj1; // this calls the copy constructor
auto obj3 = std::move(obj2); // this calls the move constructor
```
In the first line we declared `obj1` with type `std::vector<int>` along with the elements `{1, 2, 3, 4, 5}`.

In the second line we declared obj2 and copied the elements of obj1 into it, now obj2 is identical to obj1.

In the third line however, we *moved* obj2 to obj3, now obj3 has the elements of obj2 and obj2 is now a nullpointer.

### Declaring and defining
**Declarations** introduce names and types, without specifying any details or implementations.

**Definitions** provide the storage locations or implementation details.

```cpp
extern int x; 				// object declaration
class X;					// class declaration
void f();					// function declaration

int x;						// object definition
class X{					// class definition
	// code goes here...
};
void f(){					// function definition
	// code goes here...
}
```

## Deducing Types
