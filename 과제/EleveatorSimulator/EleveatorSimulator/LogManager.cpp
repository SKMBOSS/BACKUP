#include "LogManager.h"
#include <iostream>
#include "Macro.h"

void LogManager::Initialize() {
}

void LogManager::Render() {
	std::cout << m_title;
	if (m_title.size() > 0)
		std::cout << std::endl;
	for (auto iter = m_logs.begin(); iter != m_logs.end(); ++iter) {
		std::cout << **iter << std::endl;
	}
}

void LogManager::Release() {
	for (auto iter = m_logs.begin(); iter != m_logs.end(); ++iter) {
		SAFE_DELETE(*iter);
	}
	DESTROY_SINGLE(LogManager);
}

void LogManager::Clear() {
	for (auto iter = m_logs.begin(); iter != m_logs.end(); ++iter) {
		SAFE_DELETE(*iter);
	}
	m_logs.clear();
}

void LogManager::PushLine(std::string line) {
	std::string* s = new std::string();
	*s = line;
	m_logs.push_back(s);

	if (m_logs.size() > m_maximumLine) {
		SAFE_DELETE(*m_logs.begin());
		m_logs.erase(m_logs.begin());
	}
}

LogManager::LogManager() : m_maximumLine(4) { }

LogManager::~LogManager() { }
