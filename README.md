# Classes

## Table of Contents

1. Memory Management and C++
2. Memory Partitioning
3. The Heap
4. Object Orientation
5. The Three P's
6. Constuctors and Destructors in C++ 

---
---

## Memory Management and C++
Control over how and where to obtain memory

* Static memory
	- Global variables
	- Static local variable in functions or classes
	
* The Stack
	- Non-static variables
	- Anything declared at **compile time**
		+ Can possibly lead to a memory leak	
* The Heap
	- Dynamically allocated memory
	- Variables
		+ Static
		+ Dynamic
		

## Memory Partitioning
Operating System allocated memory block from Appropriate division

### Static Memory
Memory allocated during compile time and before program execution  
Only one copy of memory will be created  
Changes made to static variables will impact all uses of that variable

* Static variables will only go out of scope when the program terminates

Created through the static keyword

```c++
{

	void login()
	{
	
		static int counter = 0; //only initialized once
		readId_pwd();
		if(verified())
			counter++;		//count the number of users that are logged in
	
	}

}
```

### Static

Static variables are not the same as a global variable  

* They can be global, but can also be local
* Global variables are always accessible
	- Statics in a local sense can only be accessed within that function
	

These static variables can also be defined within a part of a class  
A static local variable doesn't go out of the scope


## The Heap

Used for dynamic allocation
Used within Java because JVM created a Heap for garbage collection and memory allocation  
The heap is allocated during run time through dynamic allocation, changed during runtime  

* This is where garbage collection and management comes from


### Trouble
Manging memory can come with issues

* Memory leaks
	- Forget to delete  unused objects or a dynamically created structure
		+ Takes up RAM that cannot be reallocated
		
	- If the memory is abandoned by a pointer.. it will continue to exist
	
	
* Dangling Reference and Segmentation Faults
	- A dangling reference happens when object or memory is trying to be accessed which has already been deleted or out of scope
	- A seg-fault happens when you try to access some memory illegally
		+ Going out of bounds within an array
		+ Accessing bad memory through a dangling reference
		+ Using a pointer that hasn't been allocated correctly (null-reference)
		

	
---
---
		


# Object Orientation

## Object Oriented Paradigm
Classes become the primary unit of abstraction

A class definition beings with the keyword *class*  
The body of the class is contained within a set of `{ };` (notice the semicolon)  

Two things that make a class

* properties
	- Properties can accept values like strings, integers, and booleans (true/false values), like any other variable
	- Student ID, grades, age, gender
	
* Object
	- Something that would store the information from properties, assign personal properties
	
* Methods 
	- A function within a class that manipulates some object or returns values


Method is a function that specifically belongs to a class 

Python can have both, where as Java would only deal with methods rather than functions


```c++
{

	class class name
	{
	
		...
	
	}; //do NOT FORGET the semicolon

}
```

## The Three P's
Encapsulation and Data Hiding require judicious use of Visibility Modifiers  
Unlike other programming languages, these are 	NOT prefixes  
Public, Private and Protected are sections within the class

Attention must be payed to organization of properties and methods

* items are private by default

```cpp
{

	class class_name
	{
	
		private:
				...
				...
				...
			
		public:
				...
				...
				...

	}; //SEMI-COLON!

}
```

### Example Class

```cpp
{

	class Circle
	{
	
		private:
			double radius;
			
		public:
			void setRadius(double radius);
			double getDiameter();
			double getArea();
			
	
	};


}
```
Different than something like Java we only declare the methods and variables (properties) but nothing is defined

### Details
Scope-resolution must be used to define method in the class  
The double-colon

```cpp
{

//class A could be forward declared in any situation, as most things can
class A; //forward declaration... not necessary

	class A
	{
	
		private:
			int a;
			void doubleA();
			
		public:
			static int nextId;
			int getA();
			void setA(int);
				
	};
	
	int A::nexId = 1000; //modify the variable
	int nextId = 1000; //this would declare a Global variable
	
	
	int getA() //this would define a function rather than a method from the class 
	{
	
		return this->a;
	
	}
	
	
	int A::getA() //this defines a METHOD from class A
	{
	
		...
	
	}
	
	void A::setA(int val)
	{
	
		this ->a = val;
	
	}
	
	void A::doubleA()
	{
	
		this->a = a * 2;
	
	}
	
	int main(int argc, char ** argv)
	{
	
		return 0;
	
	}


}
```

### Instantiation

Create a variable of the object on the stack or one can be created through a pointer on the heap  

* Using a pointer is much more common within C++ code


```cpp
circle c1;
Circle* c2 = new Circle();
```



## Constuctors and Destructors in C++ 

A **constructor** in a class is a function whose name is the same as the class name and is used to initialize objects

A **destructor** is used to collect garbage

```cpp
{

	class Queue {
	
		private:
			int queue_size;
		
		protected: 
			int *buffer;
			int front;
			int rear;
			
		public:
			...
	
	}

}
```

The constructor is defined below:   

```cpp
Queue(void) { //constructor

	front = 0; rear = 0;
	queue_size = 0;
	buffer = NULL;

}

Queue(int n){ //constructor

	front = 0; rear = 0;
	queue_size = n;
	buffer = new int[queue_size];

} //constructor Overload


```

If it is put on the heap and we delete the pointer, it would now be a memory leak. We need garabge collection which is not automatically done for us with C++. The destructor allows us to delete everything from the object. Helping with our memory leak.
*Destructor -->*

```cpp
virtual ~Queue(void) {

	delete buffer;
	buffer[]  = NULL;
	
}
```


### Combine Delete and Destructor

```cpp
void application(){

	Queue *myQueue; //declare pointer only
	myQueue = new Queue(500); //created in application
	myQueue->enqueue(23); //add 23 on myQueue
	myQueue->enqueue(8);
	delete myQueue; //delete will call ~Queue();

}
```

The destructor is called in *delete* function

### Responsibilities of Garbage Collecting Heap Memory

* Class-Writer: If heap memory is used (through new() operator) in the class (constructor) a destructor must be used to delete the memory - Class users are NOT responsible for the garbage collection of memory they did not explicitly create
* For each new() operation, one must use a delete somewhere to delete the memory created by the new()




