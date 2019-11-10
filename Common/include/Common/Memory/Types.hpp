#pragma once

//
// Provides common primitive like structs.
//

template<class FloatType>
struct Vec2d {
	FloatType x;
	FloatType y;
};

template<class FloatType>
struct RGBA {
	FloatType r;
	FloatType g;
	FloatType b;
	FloatType a;
};