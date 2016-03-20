#pragma once

#include "glm\glm.hpp"
#include <vector>
#include <math.h>

class Pyramid
{
	typedef std::vector<glm::vec3> Row;
	typedef std::vector<Row> Matrix;
	
public:
	Pyramid();
	Pyramid(int);
	void updateSize(int);
	int getSize();

private:
	void fillMatrix(int size);
	glm::vec3 getCellValue(int, int);
	double getYPosition(int, int);

public:
	Matrix pyramidPosition;

private:
	int pyramidSize;
};

