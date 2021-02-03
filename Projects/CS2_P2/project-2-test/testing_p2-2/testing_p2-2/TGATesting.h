#pragma once
#include "TGAImg.h"

class TGATesting
{
public:
	TGATesting();

	bool CompareTGA(TGAImg& A, TGAImg& B);
	void PrintMsg(bool test, int num);
};

