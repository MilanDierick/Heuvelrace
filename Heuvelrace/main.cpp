#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> parseMulti(const string input);
vector<int> getInputMulti();
vector<int> processJumps();
int parseSingle(const string input);
int getInputSingle();
int calculatePoints(vector<int> jumps);

int main()
{
	vector<int> points = processJumps();
	int i = 1;

	for each (int point in points)
	{
		cout << i << " " << point << endl;
		i++;
	}

	cin.get();
	return 0;
}

vector<int> parseMulti(const string input)
{
	vector<int> out;
	string::const_iterator cpos1 = input.cbegin();
	string tmp1;
	do
	{
		if (*cpos1 != ' ')
		{
			tmp1 += *cpos1;
		}
		else
		{
			out.push_back(atoi(tmp1.c_str()));
			tmp1 = "";
		}
		cpos1++;
	} while (cpos1 != input.cend());

	if (!tmp1.empty())
	{
		out.push_back(atoi(tmp1.c_str()));
	}

	return out;
}

vector<int> getInputMulti()
{
	vector<int> out;
	string tmp1;

	getline(cin, tmp1);
	return parseMulti(tmp1);
}

vector<int> processJumps()
{
	vector<int> out;
	vector<int> jumps;
	int tasks = getInputSingle();
	string jumpCount;

	for (int i = 0; i < tasks; i++)
	{
		jumpCount = getInputSingle();			// Not used.
		jumps = getInputMulti();
		out.push_back(calculatePoints(jumps));
	}

	return out;
}

int parseSingle(const string input)
{
	string::const_iterator cpos1 = input.cbegin();
	string tmp1;
	int out;

	do
	{
		tmp1 += *cpos1;
		cpos1++;
	} while (cpos1 != input.cend());

	out = atoi(tmp1.c_str());
	return out;
}

int getInputSingle()
{
	string tmp1;

	getline(cin, tmp1);
	return parseSingle(tmp1);
}

int calculatePoints(vector<int> jumps)
{
	int out = 0, phase1 = 0, phase2 = 0, phase3 = 0, phaseMax = 4;

	for each (int jumpTime in jumps)
	{
		phase1 = 0, phase2 = 0, phase3 = 0;
		while (jumpTime > 0)
		{
			if (phase1 < phaseMax)
			{
				jumpTime--;
				phase1++;
				out += 25;
			}
			else if (phase2 < phaseMax)
			{
				jumpTime--;
				phase2++;
				out += 100;
			}
			else if (phase3 < phaseMax)
			{
				jumpTime--;
				phase3++;
				out += 500;
			}
			else
			{
				jumpTime--;
				out += 1000;
			}
		}
	}

	return out;
}

