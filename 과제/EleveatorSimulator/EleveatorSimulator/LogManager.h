#ifndef _LOGMANAGER_H_
#define _LOGMANAGER_H_

#include "Macro.h"
#include <string>
#include <list>

class LogManager {
	DECLARE_SINGLETON(LogManager)
private:
	std::list<std::string*> m_logs;
	std::string m_title;
	int m_maximumLine;

public:
	void Initialize();
	void Render();
	void Release();

	inline void SetTitle(std::string title) {
		if(m_title.size() <= 0)
			m_title = title; 
	}
	inline void SetMaximum(int max) { m_maximumLine = max; }

	inline void ClearTitle() { m_title.clear(); }
	void Clear();
	void PushLine(std::string line);

private:
	LogManager();
public:
	~LogManager();
};

#endif


