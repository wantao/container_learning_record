// constructing vectors
#include <iostream>
#include <vector>
#include "../include/vector.h"

using namespace std;

class VectorUseSample g_VectorTest;
VectorUseSample::VectorUseSample()
{

}
VectorUseSample::~VectorUseSample()
{

}

////////Constructs a vector, initializing its contents depending on the constructor version used
void VectorUseSample::vector_constructor_sample()
{
	unsigned int i;

	// constructors used in the same order as described above:
	std::vector<int> first;                                // empty vector of ints
	std::vector<int> second (4,100);                       // four ints with value 100
	std::vector<int> third (second.begin(),second.end());  // iterating through second
	std::vector<int> fourth (third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth are:";
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	///output
	//The contents of fifth are: 16 2 77 29 
}

///This destroys all container elements, and deallocates all the storage capacity allocated 
////by the vector using its allocator.
void VectorUseSample::vector_destructor_sample()
{
	//~vector();
}

//Assigns new contents to the vector, replacing its current contents,
//and modifying its size accordingly.
void VectorUseSample::vector_assign_sample()
{
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;

	first.assign (7,100);             // 7 ints with a value of 100

	std::vector<int>::iterator it;
	it=first.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';
	/////output
		//Size of first: 7
		//Size of second: 5
		//Size of third: 3
	/////output
}

//Returns a reference to the element at position n in the vector.
void VectorUseSample::vector_at_sample()
{
	std::vector<int> myvector (10);   // 10 zero-initialized ints

	// assign some values:
	for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i)=i;

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
	std::cout << '\n';

	///output
	//myvector contains: 0 1 2 3 4 5 6 7 8 9

}

//Returns a reference to the last element in the vector.
void VectorUseSample::vector_back_sample()
{
	std::vector<int> myvector;

	myvector.push_back(10);

	while (myvector.back() != 0)
	{
		myvector.push_back ( myvector.back() -1 );
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size() ; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	//output
	//myvector contains: 10 9 8 7 6 5 4 3 2 1 0
}

//Returns an iterator pointing to the first element in the vector.
void VectorUseSample::vector_begin_sample()
{
	std::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	//output
	//myvector contains: 1 2 3 4 5
}

//Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
void VectorUseSample::vector_capacity_sample()
{
	std::vector<int> myvector;

	// set some content in the vector:
	for (int i=0; i<100; i++) myvector.push_back(i);

	std::cout << "size: " << (int) myvector.size() << '\n';
	std::cout << "capacity: " << (int) myvector.capacity() << '\n';
	std::cout << "max_size: " << (int) myvector.max_size() << '\n';

	//output
	//size: 100
	//capacity: 128
	//max_size: 1073741823
}
//Returns a const_iterator pointing to the first element in the container.
void VectorUseSample::vector_cbegin_sample()
{

	std::vector<int> myvector = {10,20,30,40,50};

	std::cout << "myvector contains:";

	for (auto it = myvector.cbegin(); it != myvector.cend(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	//output
	//myvector contains: 10 20 30 40 50
}

//Returns a const_iterator pointing to the past-the-end element in the container.
void VectorUseSample::vector_cend_sample()
{

	std::vector<int> myvector = {10,20,30,40,50};

	std::cout << "myvector contains:";

	for (auto it = myvector.cbegin(); it != myvector.cend(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	//output
	//myvector contains: 10 20 30 40 50
}

//Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
void VectorUseSample::vector_clear_sample()
{
	std::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	//output
	//myvector contains: 100 200 300
	//myvector contains: 1101 2202
}

//Returns a const_reverse_iterator pointing to the last element in the container (i.e., its reverse beginning)
void VectorUseSample::vector_crbegin_sample()
{
	std::vector<int> myvector = {1,2,3,4,5};

	std::cout << "myvector backwards:";
	for (auto rit = myvector.crbegin(); rit != myvector.crend(); ++rit)
		std::cout << ' ' << *rit;
	std::cout << '\n';

	//output
	//myvector backwards: 5 4 3 2 1
}

//Return const_reverse_iterator to reverse end
//Returns a const_reverse_iterator pointing to the theoretical element preceding the first element 
//in the container (which is considered its reverse end).
void VectorUseSample::vector_crend_sample()
{

	std::vector<int> myvector = {1,2,3,4,5};

	std::cout << "myvector backwards:";
	for (auto rit = myvector.crbegin(); rit != myvector.crend(); ++rit)
		std::cout << ' ' << *rit;
	std::cout << '\n';
	//output
	//myvector backwards: 5 4 3 2 1
}

//Returns a direct pointer to the memory array used internally by the vector to store its owned elements.

//Because elements in the vector are guaranteed to be stored in contiguous storage locations in the same order as represented by the vector, 
//the pointer retrieved can be offset to access any element in the array.
void VectorUseSample::vector_data_sample()
{
	std::vector<int> myvector (5);

	int* p = myvector.data();

	*p = 10;
	++p;
	*p = 20;
	p[2] = 100;

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	//output
	//myvector contains: 10 20 0 100 0
}

//Construct and insert element
//The container is extended by inserting a new element at position. 
//This new element is constructed in place using args as the arguments for its construction.
void VectorUseSample::vector_emplace_sample()
{
	std::vector<int> myvector = {10,20,30};

	auto it = myvector.emplace ( myvector.begin()+1, 100 );
	myvector.emplace ( it, 200 );
	myvector.emplace ( myvector.end(), 300 );

	std::cout << "myvector contains:";
	for (auto& x: myvector)
		std::cout << ' ' << x;
	std::cout << '\n';
	//output
	//myvector contains: 10 200 100 20 30 300

}

//Construct and insert element at the end
//Inserts a new element at the end of the vector, right after its current last element. 
//This new element is constructed in place using args as the arguments for its constructor.
void VectorUseSample::vector_emplace_back_sample()
{
	std::vector<int> myvector = {10,20,30};

	myvector.emplace_back (100);
	myvector.emplace_back (200);

	std::cout << "myvector contains:";
	for (auto& x: myvector)
		std::cout << ' ' << x;
	std::cout << '\n';
	//output
	//myvector contains: 10 20 30 100 200
}

//Test whether vector is empty
//Returns whether the vector is empty (i.e. whether its size is 0).
void VectorUseSample::vector_empty_sample()
{
	std::vector<int> myvector;
	int sum (0);

	for (int i=1;i<=10;i++) myvector.push_back(i);

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}

	std::cout << "total: " << sum << '\n';
	//output
	//total: 55

}

//Return iterator to end
//Returns an iterator referring to the past-the-end element in the vector container.
void VectorUseSample::vector_end_sample()
{
	std::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	//output
	//myvector contains: 1 2 3 4 5
}

//Erase elements
//Removes from the vector either a single element (position) or a range of elements ([first,last)).
void VectorUseSample::vector_erase_sample()
{
	std::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myvector.push_back(i);

	// erase the 6th element
	myvector.erase (myvector.begin()+5);

	// erase the first 3 elements:
	myvector.erase (myvector.begin(),myvector.begin()+3);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	//output
	//myvector contains: 4 5 7 8 9 10
}

//Access first element
//Returns a reference to the first element in the vector.
void VectorUseSample::vector_front_sample()
{
	std::vector<int> myvector;

	myvector.push_back(78);
	myvector.push_back(16);

	// now front equals 78, and back 16

	myvector.front() -= myvector.back();

	std::cout << "myvector.front() is now " << myvector.front() << '\n';
	//output
	//myvector.front() is now 62

}

//Get allocator
//Returns a copy of the allocator object associated with the vector.
void VectorUseSample::vector_get_allocator_sample()
{
	std::vector<int> myvector;
	int * p;
	unsigned int i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';

	// destroy and deallocate:
	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p,5);
	//output
	//The allocated array contains: 0 1 2 3 4

}

//Insert elements
//The vector is extended by inserting new elements before the element at the specified position,
//effectively increasing the container size by the number of elements inserted.
void VectorUseSample::vector_insert_sample()
{
	std::vector<int> myvector (3,100);
	std::vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert ( it , 200 );

	myvector.insert (it,2,300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	std::vector<int> anothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	//output
	//myvector contains: 501 502 503 300 300 400 400 200 100 100 100

}

//Return maximum size
//Returns the maximum number of elements that the vector can hold.
void VectorUseSample::vector_max_size_sample()
{
	std::vector<int> myvector;

	// set some content in the vector:
	for (int i=0; i<100; i++) myvector.push_back(i);

	std::cout << "size: " << myvector.size() << "\n";
	std::cout << "capacity: " << myvector.capacity() << "\n";
	std::cout << "max_size: " << myvector.max_size() << "\n";
	//output
	//A possible output for this program could be:
	//size: 100
	//capacity: 128
	//max_size: 1073741823
}

//Assign content
//Assigns new contents to the container, replacing its current contents, 
//and modifying its size accordingly.
void VectorUseSample::vector_operator_equal_sample()
{
	std::vector<int> foo (3,0);
	std::vector<int> bar (5,0);

	bar = foo;
	foo = std::vector<int>();

	std::cout << "Size of foo: " << int(foo.size()) << '\n';
	std::cout << "Size of bar: " << int(bar.size()) << '\n';
	//output
	//Size of foo: 0
	//Size of bar: 3
}

//Access element
//Returns a reference to the element at position n in the vector container.
void VectorUseSample::vector_operator_brackets_sample()
{
	std::vector<int> myvector (10);   // 10 zero-initialized elements

	std::vector<int>::size_type sz = myvector.size();

	// assign some values:
	for (unsigned i=0; i<sz; i++) myvector[i]=i;

	// reverse vector using operator[]:
	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = myvector[sz-1-i];
		myvector[sz-1-i]=myvector[i];
		myvector[i]=temp;
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<sz; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	//output
	//myvector contains: 9 8 7 6 5 4 3 2 1 0

}

//Delete last element
//Removes the last element in the vector, effectively reducing the container size by one.
void VectorUseSample::vector_pop_back_sample()
{
	std::vector<int> myvector;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	while (!myvector.empty())
	{
		sum+=myvector.back();
		myvector.pop_back();
	}

	std::cout << "The elements of myvector add up to " << sum << '\n';

	//output
	//The elements of myvector add up to 600
}

//Add element at the end
//Adds a new element at the end of the vector, after its current last element. 
//The content of val is copied (or moved) to the new element.
void VectorUseSample::vector_push_back_sample()
{
	std::vector<int> myvector;
	int myint;

	std::cout << "Please enter some integers (enter 0 to end):\n";

	do {
		std::cin >> myint;
		myvector.push_back (myint);
	} while (myint);

	std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	//output
	//
}

//Return reverse iterator to reverse beginning
//Returns a reverse iterator pointing to the last element in the vector (i.e., its reverse beginning).
void VectorUseSample::vector_rbegin_sample()
{
	std::vector<int> myvector (5);  // 5 default-constructed ints

	std::vector<int>::reverse_iterator rit = myvector.rbegin();

	int i=0;
	for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	//output
	//myvector contains: 5 4 3 2 1
}

//Return reverse iterator to reverse end
//Returns a reverse iterator pointing to the theoretical 
//element preceding the first element in the vector (which is considered its reverse end).
void VectorUseSample::vector_rend_sample()
{
	std::vector<int> myvector (5);  // 5 default-constructed ints

	std::vector<int>::reverse_iterator rit = myvector.rbegin();

	int i=0;
	for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	//output
	//5 4 3 2 1 
}
//Request a change in capacity
//Requests that the vector capacity be at least enough to contain n elements.
void VectorUseSample::vector_reserve_sample()
{
	std::vector<int>::size_type sz;

	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	//output
	//Possible output:

	//making foo grow:
	//capacity changed: 1
	//capacity changed: 2
	//capacity changed: 4
	//capacity changed: 8
	//capacity changed: 16
	//capacity changed: 32
	//capacity changed: 64
	//capacity changed: 128
	//making bar grow:
	//capacity changed: 100
}

//Change size
//Resizes the container so that it contains n elements.

//If n is smaller than the current container size, the content is reduced to its first n elements, 
//removing those beyond (and destroying them).
void VectorUseSample::vector_resize_sample()
{
	std::vector<int> myvector;

	// set some initial content:
	for (int i=1;i<10;i++) myvector.push_back(i);

	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);

	std::cout << "myvector contains:";
	for (int i=0;i<myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	//output
	//myvector contains: 1 2 3 4 5 100 100 100 0 0 0 0
}

//Shrink to fit
//Requests the container to reduce its capacity to fit its size.

//The request is non-binding, and the container implementation is free to optimize
//otherwise and leave the vector with a capacity greater than its size
void VectorUseSample::vector_shrink_to_fit_sample()
{
	std::vector<int> myvector (100);
	std::cout << "1. capacity of myvector: " << myvector.capacity() << '\n';

	myvector.resize(10);
	std::cout << "2. capacity of myvector: " << myvector.capacity() << '\n';

	myvector.shrink_to_fit();
	std::cout << "3. capacity of myvector: " << myvector.capacity() << '\n';
	//output
	//Possible output:
	//1. capacity of myvector: 100
	//2. capacity of myvector: 100
	//3. capacity of myvector: 10
}

//Return size
//Returns the number of elements in the vector.

//This is the number of actual objects held in the vector, which is not necessarily equal to its storage capacity.
void VectorUseSample::vector_size_sample()
{
	std::vector<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.insert (myints.end(),10,100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';
	//output
	//0. size: 0
	//1. size: 10
	//2. size: 20
	//3. size: 19
}
//Swap content
//Exchanges the content of the container by the content of x, 
//which is another vector object of the same type. Sizes may differ.
void VectorUseSample::vector_swap_sample()
{
	std::vector<int> foo (3,100);   // three ints with a value of 100
	std::vector<int> bar (5,200);   // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << '\n';
	//output
	//foo contains: 200 200 200 200 200 
	//bar contains: 100 100 100 
}

//Relational operators for vector
//Performs the appropriate comparison operation between the vector containers lhs and rhs.
void VectorUseSample::vector_relational_opeators()
{
	std::vector<int> foo (3,100);   // three ints with a value of 100
	std::vector<int> bar (2,200);   // two ints with a value of 200

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	//output
	//foo and bar are not equal
	//foo is less than bar
	//foo is less than or equal to bar
}

//Exchange contents of vectors
//The contents of container x are exchanged with those of y. 
//Both container objects must be of the same type (same template parameters), although sizes may differ.
void VectorUseSample::vector_swap_vector_sample()
{

	unsigned int i;
	std::vector<int> foo (3,100);   // three ints with a value of 100
	std::vector<int> bar (5,200);   // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (std::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "bar contains:";
	for (std::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	//output
	//foo contains: 200 200 200 200 200 
	//bar contains: 100 100 100 
}

void VectorUseSample::init()
{
	vector_constructor_sample();
	vector_destructor_sample();
	vector_assign_sample();
	vector_at_sample();
	vector_back_sample();
	vector_begin_sample();
	vector_capacity_sample();
	vector_cbegin_sample();
	vector_cend_sample();
	vector_clear_sample();
	vector_crbegin_sample();
	vector_crend_sample();
	vector_data_sample();
	vector_emplace_sample()
	vector_emplace_back_sample();
	vector_empty_sample()
	vector_end_sample();
	vector_erase_sample()
	vector_front_sample();
	vector_get_allocator_sample();
	vector_insert_sample();
	vector_max_size_sample();
	vector_operator_equal_sample();
	vector_operator_brackets_sample();
	vector_pop_back_sample();
	vector_push_back_sample();
	vector_rbegin_sample();
	vector_rend_sample();
	vector_reserve_sample();
	vector_resize_sample();
	vector_shrink_to_fit_sample();
	vector_size_sample();
	vector_swap_sample();
	vector_relational_opeators();
	vector_swap_vector_sample();
}

