#include "Pyramid.h"

Pyramid::Pyramid()
{
}

Pyramid::Pyramid(int size)
{
	pyramidSize = size;
	fillMatrix(size);
}

void Pyramid::updateSize(int size)
{
	if (size < 0) {
		return;
	}

	pyramidPosition.clear();
	pyramidSize = size;
	fillMatrix(size);
}

int Pyramid::getSize()
{
	return pyramidSize;
}

void Pyramid::fillMatrix(int size)
{
<<<<<<< HEAD
	for (size_t i = 0; i < pyramidSize; ++i)
	{
		Row row(pyramidSize);

		for (size_t j = 0; j < pyramidSize; ++j)
		{
			row[j] = getCellValue(i,j);
=======
	for (int i = 0; i < pyramidSize; ++i)
	{
		Row row(pyramidSize);

		for (int j = 0; j < pyramidSize; ++j)
		{
			row[j] = getCellValue(i, j);
>>>>>>> Dev
		}

		pyramidPosition.push_back(row);
	}
}

glm::vec3 Pyramid::getCellValue(int x, int z)
{
<<<<<<< HEAD
	return glm::vec3(x, getYPosition(x,z), z - 20.0f);
=======
	return glm::vec3(x, getYPosition(x, z), z - 20.0f);
>>>>>>> Dev
}

double Pyramid::getYPosition(int x, int z)
{
	double y = pyramidSize / 2 - fmax(abs(pyramidSize / 2 - x),
		abs(pyramidSize / 2 - z));
	return y;
}


