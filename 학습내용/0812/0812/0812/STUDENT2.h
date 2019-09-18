#pragma once
#include <iostream>

class STUDENT2
{
private:
	int no;
	char* pOut;
	char szName[256];
protected:
public:
	static int aaa;
	
	STUDENT2(int no);
	~STUDENT2();
	STUDENT2(const STUDENT2& other);

	void print();

	inline void SetNo(int _no)
	{
		no = _no;
	}
};

