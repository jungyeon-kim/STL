#include "save.h"

void save(string fname)
{
	ifstream in(fname);			// �����б�
	ofstream out("text.txt");	// ���Ͼ��⸦ �������� �Ѵ�.
	//ofstream out("text.txt", ios::app);	// ���Ͼ��⸦ ���ٿ�������(ios::app)�� �Ѵ�.

	// ����� �ð��� ����Ѵ�.
	auto tic = chrono::system_clock::now();				// �ð�������� �� tic�� �귶��?
	auto time = chrono::system_clock::to_time_t(tic);	// �� ���� time_t�� ��ȯ
	string date = ctime(&time);							// �� ���� ���ڷ� ��ȯ

	out << "=========================" << endl;
	out << date;
	out << "=========================" << endl;
	out << endl;

	// fname�� ��� ������ ���ٿ� ����.
	std::copy(istreambuf_iterator<char>(in), istreambuf_iterator<char>(), ostreambuf_iterator<char>(out));	// copy(������, ������, ����)
}