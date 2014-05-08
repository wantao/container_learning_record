#include "../include/vector.h"
#include <iostream>
#include <list>

bool mycomparison (double first, double second)
{ 
	std::cout<<"first:"<<first<<" "<<"second:"<<second<<std::endl;
	std::cout<<"int(first):"<<(int)(first)<<" "<<"int(second)"<<(int)(second)<<std::endl;
	return ( int(first)<int(second) );
}

#include <iostream>
#include <set>

int main ()
{
	std::set<int> myset;
	int highest;

	std::set<int>::key_compare mycomp = myset.key_comp();

	for (int i=0; i<=5; i++) myset.insert(i);

	std::cout << "myset contains:";

	highest=*myset.rbegin();
	std::set<int>::iterator it=myset.begin();
	do {
		std::cout << ' ' << *it;
	} while ( mycomp(*(++it),highest) );

	std::cout << '\n';

	return 0;
}

//#include <iostream>
//#include <map>
//
//int main ()
//{
//	std::multimap<char,int> mymm;
//
//	mymm.insert(std::pair<char,int>('a',10));
//	mymm.insert(std::pair<char,int>('b',20));
//	mymm.insert(std::pair<char,int>('b',30));
//	mymm.insert(std::pair<char,int>('b',40));
//	mymm.insert(std::pair<char,int>('c',50));
//	mymm.insert(std::pair<char,int>('c',60));
//	mymm.insert(std::pair<char,int>('d',60));
//
//	std::cout << "mymm contains:\n";
//	for (char ch='a'; ch<='d'; ch++)
//	{
//		std::pair <std::multimap<char,int>::iterator, std::multimap<char,int>::iterator> ret;
//		ret = mymm.equal_range(ch);
//		std::cout << ch << " =>";
//		for (std::multimap<char,int>::iterator it=ret.first; it!=ret.second; ++it)
//			std::cout << ' ' << it->second;
//		std::cout << '\n';
//	}
//
//	return 0;
//}

// map::value_comp
//#include <iostream>
//#include <map>

//int main ()
//{
//	std::map<char,int> mymap;
//
//	mymap['x']=1001;
//	mymap['y']=4002;
//	mymap['z']=3003;
//
//	std::cout << "mymap contains:\n";
//
//	std::pair<char,int> highest = *mymap.rbegin();          // last element
//
//	std::map<char,int>::iterator it = mymap.begin();
//	do {
//		std::cout << it->first << " => " << it->second << '\n';
//	} while ( mymap.value_comp()(*it++, highest) );
//
//	return 0;
//}

//int main(void)
//{
//
//
//	//std::list<double> first, second;
//
//	//first.push_back (3.1);
//	//first.push_back (2.2);
//	//first.push_back (2.9);
//
//	//second.push_back (3.7);
//	//second.push_back (7.1);
//	//second.push_back (1.4);
//
//	//first.sort();
//	//second.sort();
//
//	//first.merge(second);
//
//	//// (second is now empty)
//
//	//for (std::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
//	//	std::cout << ' ' << *it;
//	//std::cout << '\n';
//	//second.push_back (2.1);
//
//	//first.merge(second,mycomparison);
//
//	//std::cout << "first contains:";
//	//for (std::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
//	//	std::cout << ' ' << *it;
//	//std::cout << '\n';
//	g_VectorTest.init();
//}