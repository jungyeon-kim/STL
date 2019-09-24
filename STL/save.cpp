#include "save.h"

void save(string fname)
{
	ifstream in(fname);			// 파일읽기
	ofstream out("text.txt");	// 파일쓰기를 덮어쓰기모드로 한다.
	//ofstream out("text.txt", ios::app);	// 파일쓰기를 덧붙여쓰기모드(ios::app)로 한다.

	// 실행된 시간을 기록한다.
	auto tic = chrono::system_clock::now();				// 시간기원에서 몇 tic이 흘렀나?
	auto time = chrono::system_clock::to_time_t(tic);	// 이 값을 time_t로 변환
	string date = ctime(&time);							// 이 값을 글자로 변환

	out << "=========================" << endl;
	out << date;
	out << "=========================" << endl;
	out << endl;

	// fname의 모든 내용을 덧붙여 쓴다.
	std::copy(istreambuf_iterator<char>(in), istreambuf_iterator<char>(), ostreambuf_iterator<char>(out));	// copy(어디부터, 어디까지, 어디로)
}