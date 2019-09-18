#include <iostream>

#include "ConsoleMap.h"
#include "Macro.h"

void ConsoleMap::Initialize(Size size) {
	m_size = size;

	m_pBuffers = new std::string[m_size.height * m_size.width];
	for (int y = 0; y < m_size.height; ++y) {
		for (int x = 0; x < m_size.width; ++x) {
			m_pBuffers[Utility::GetIndex4DoublePtr(m_size.width, x, y)] = "  ";
		}
	}
}

void ConsoleMap::Update() {
	for (int y = 0; y < m_size.height; ++y) {
		for (int x = 0; x < m_size.width; ++x) {
			m_pBuffers[Utility::GetIndex4DoublePtr(m_size.width, x, y)] = "  ";
		}
	}
}

void ConsoleMap::Render() {
	for (int y = 0; y < m_size.height; ++y) {
		for (int x = 0; x < m_size.width; ++x) {
			std::cout << m_pBuffers[Utility::GetIndex4DoublePtr(m_size.width, x, y)];
		}
		std::cout << std::endl;
	}
}

void ConsoleMap::Release( ){
	SAFE_DELETE_ARRAY(m_pBuffers);
}

ConsoleMap::ConsoleMap() {
}


ConsoleMap::~ConsoleMap() {
}
