#pragma once
class SingleTone
{
private:
	static SingleTone* pThis;

public:
	static SingleTone* GetInstance()
	{
		if (pThis == nullptr)
			pThis = new SingleTone();

		return pThis;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
	}

	static void Release()
	{
		if (pThis == nullptr)
			delete pThis;
	}

	SingleTone();
	~SingleTone();
};

