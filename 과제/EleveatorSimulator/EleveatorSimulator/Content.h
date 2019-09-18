#ifndef _CONTENT_H_
#define _CONTENT_H_

typedef struct tagPoint {
public:
	int x;
	int y;

	bool operator== (const tagPoint& target) {
		if (this->x == target.x && this->y == target.y)
			return true;
		else
			return false;
	}
	void operator+=(const tagPoint& target) {
		this->x += target.x;
		this->y += target.y;
	}

public:
	tagPoint(int _x, int _y) {
		x = _x;
		y = _y;
	}
	tagPoint() { x = 0; y =01; }
} Point;

typedef struct tagSize {
public:
	int width;
	int height;

public:
	tagSize(int _w, int _h) {
		width = _w;
		height = _h;
	}
	tagSize() : width(0), height(0) { }
} Size;

#endif