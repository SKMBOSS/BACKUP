#ifndef _CONSOLEMAP_H_
#define _CONSOLEMAP_H_

#include <string>

#include "Utility.h"
#include "Content.h"

class ConsoleMap {
private:
	std::string* m_pBuffers;
	Size m_size;
	
public:
	void Initialize(Size size);
	void Update();
	void Render();
	void Release();

	inline std::string* GetBuffer(int x, int y) {
		return &m_pBuffers[Utility::GetIndex4DoublePtr(m_size.width, x, y)];
	}
	const inline Size* GetSize() { return &m_size; }

public:
	ConsoleMap();
	virtual ~ConsoleMap();
};



#endif


