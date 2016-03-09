#ifndef OA_SIZE_H
#define OA_SIZE_H

#include <type_traits>

struct Size1D {
	int width;
};

struct Size2D {
	int width;
	int height;
};

struct Size3D {
	int width;
	int height;
	int depth;
};

/*template<int dimension>
using temp_Size = typename std::conditional<dimension == 2, Size2D, Size3D>::type;

template<int dimension>
using Size = typename std::conditional < dimension == 1, Size1D, temp_Size<dimension> ::type;*/

#endif