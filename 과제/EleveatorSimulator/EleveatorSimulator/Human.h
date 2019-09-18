#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "Content.h"

class ConsoleMap;
class Human {
private:
	Point m_position;
	ConsoleMap* m_pConsoleMap;
	int m_weight;
	int m_targetFloor;

public:
	void Initialize(int targetFloor, Point pos, ConsoleMap* buffer);
	void Update();
	void Render();
	void Release();

	inline void SetPosition(Point pos) { m_position = pos; }
	inline int GetWeight() { return m_weight; }
	const inline int GetTargetFloorCount() { return m_targetFloor; }

public:
	Human();
	virtual ~Human();
};

#endif