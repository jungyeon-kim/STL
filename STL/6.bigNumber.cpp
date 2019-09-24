#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

class Add
{
private:
	string		topStr{}, bottomStr{}, result{};
	string		topFileName{}, bottomFileName{};
	ifstream	topIn{}, bottomIn{};
	ofstream	resultOut{};
public:
	void menual()
	{
		int num{};

		while (true)
		{
			cout << "[0]general [1]fstream: ";
			cin >> num;

			if (!num) caseOne();
			else caseTwo();
		}
	}
	void addAlgorithm()	// ***
	{
		int carry{};			// 올림수

		while (!topStr.empty() || !bottomStr.empty())
		{
			int singleDigit{};	// 자릿수

			if (topStr.empty()) singleDigit += carry + bottomStr.back() - '0';
			else if (bottomStr.empty()) singleDigit += carry + topStr.back() - '0';
			else singleDigit += carry + topStr.back() + bottomStr.back() - '0' * 2;

			if (!topStr.empty()) topStr.pop_back();
			if (!bottomStr.empty()) bottomStr.pop_back();

			result.push_back(singleDigit % 10 + '0');
			carry = singleDigit / 10;
		}
		if (carry) result.push_back('1');
		reverse(result.begin(), result.end());
	}
	void caseOne()	// general version
	{
		cout << "input integer: ";
		cin >> topStr;
		cout << "input integer: ";
		cin >> bottomStr;
		// printStr
		cout << "	" << topStr << endl;
		cout << " +	" << bottomStr << endl;
		// addString
		addAlgorithm();
		// printResult
		cout << " =	" << result << endl;
		// init
		result.clear();
	}
	void caseTwo()	// fstream version
	{
		cout << "input filename: ";
		cin >> topFileName;
		cout << "input filename: ";
		cin >> bottomFileName;
		// inStr
		topIn.open(topFileName + ".txt");
		bottomIn.open(bottomFileName + ".txt");
		topIn >> topStr;
		bottomIn >> bottomStr;
		cout << "정수 1 파일이름: " << topFileName + ".txt" << endl;
		cout << "정수 2 파일이름: " << bottomFileName + ".txt" << endl;
		// addString
		addAlgorithm();
		// outResult
		resultOut.open(topFileName + "+" + bottomFileName + ".txt");
		resultOut << result;
		// init
		result.clear();
		// fileClose
		topIn.close();
		bottomIn.close();
		resultOut.close();
	}
};

int main()
{
	Add add;

	add.menual();
}