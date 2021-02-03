#include <iostream>
#include "TGATesting.h"
using namespace std;

TGATesting::TGATesting()
{

}

bool TGATesting::CompareTGA(TGAImg& A, TGAImg& B)
{
	TGAHead head1 = A.GetHead();
	TGAHead head2 = B.GetHead();

	vector<Pixel> data1 = A.GetData();
	vector<Pixel> data2 = B.GetData();

	if (head1.GetHeight() != head2.GetHeight())
		return false;
	if (head1.GetWidth() != head2.GetWidth())
		return false;

	if (data1.size() != data2.size())
		return false;

	for (unsigned int i = 0; i < data1.size(); i++)
	{
		if (data1[i].GetBlue() != data2[i].GetBlue())
			return false;
		if (data1[i].GetGreen() != data2[i].GetGreen())
			return false;
		if (data1[i].GetRed() != data2[i].GetRed())
			return false;
	}

	return true;
}

void TGATesting::PrintMsg(bool test, int num)
{
	if (test)
		cout << "Test #" << num << ".....Passed!" << endl;
	else
		cout << "Test #" << num << ".....Failed!" << endl;
}