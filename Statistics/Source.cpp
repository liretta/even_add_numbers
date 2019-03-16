#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

using namespace std;
typedef vector<int> vectori;

void CreateVectors(vector <int> &basic, vector<int> &even, vector<int> &odd);
bool countStatistic(vector <int> &basic, vector <int> &even, vector<int> &odd);
void Test();

int main()
{
	ifstream in("input.txt");
	int nSize = 0;
	in >> nSize;
	in.ignore();
	
	vectori basic;
	for (int i = 0; i < nSize; ++i)
	{
		int tmp;
		in >> tmp;
		basic.push_back(tmp);
		in.ignore();
	}

	vectori even, odd;
	CreateVectors(basic, even, odd);
	ofstream out("output.txt");
	if (odd.size() != 0)
	{
		for (auto it = odd.begin(); it < odd.end(); ++it)
			out << (*it) << " ";
	}
	out << endl;

	if (even.size() != 0)
	{
		for (auto it = even.begin(); it < even.end(); ++it)
			out << (*it) << " ";
	}
	out << endl;

	if (countStatistic(basic, even, odd) == true)
		out << "YES" << endl;
	else
		out << "NO" << endl;
}

void CreateVectors(vector <int> &basic, vector<int> &even, vector<int> &odd)
{
	even.clear();
	odd.clear();
	for (int i = 0; i < basic.size(); ++i)
	{
		if (basic[i] % 2 == 0)
			even.push_back(basic[i]);
		else
			odd.push_back(basic[i]);
	}
}

bool countStatistic(vector <int> &basic, vector <int> &even, vector<int> &odd)
{
	bool result = even.size() < odd.size() ? false : true;
	return result;
}


void Test()
{
	vectori basic;
	basic.push_back(1);
	vectori even, odd;

	CreateVectors(basic, even, odd);
	
	assert(countStatistic(basic, even, odd) == false);
	vectori evenTest;
	vectori oddTest = { 1 };
	assert(evenTest == even);
	assert(oddTest == odd);
	cout << "First test complited" << endl;

	basic.push_back(2);
	CreateVectors(basic, even, odd);
	assert(countStatistic(basic, even, odd) == false);
	vectori evenTest2 = {2};
	vectori oddTest2 = { 1 };
	assert(evenTest2 == even);
	assert(oddTest2 == odd);
	cout << "Second test complited" << endl;

	basic.clear();
	basic = { 29, 4, 7, 12,15,17,24,1,31,30,31,20 };
	CreateVectors(basic, even, odd);
	assert(countStatistic(basic, even, odd) == false);
	vectori evenTest3 = { 4,12,24,30,20 };
	vectori oddTest3 = { 29,7, 15,17,1, 31,31 };
	assert(evenTest3 == even);
	assert(oddTest3 == odd);
	cout << "Third test complited" << endl;
	cout << "All tests ok\n";
}



