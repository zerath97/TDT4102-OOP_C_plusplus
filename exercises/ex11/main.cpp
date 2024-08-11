#include "includes.h"
#include "ListHandling.h"


//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	// 1a, b, c)
	vector<string> vec1 = {"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectetur"};
	printVector(vec1);
	printReverseVector(vec1);
	replaceVectorElement(vec1, "Lorem", "Ipsum");
	printVector(vec1);

	// 1d)
	set<string> set1 = {"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectetur"};
	printSet(set1);
	printReverseSet(set1);
	replaceSetElement(set1, "Lorem", "Ipsum");
	printSet(set1);

	cin.get();
}

//------------------------------------------------------------------------------
