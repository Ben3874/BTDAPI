#pragma once
// Standard Number Header
//
// Uses: Shorthand stdint, std floats
//

#include <iostream>
#include <stdint.h>
#include <string>

//
// Comments are for intellisense.
//

// 8 bit signed integer
typedef int8_t i8;

// 8 bit unsigned integer
typedef uint8_t u8;

// 16 bit signed integer
typedef int16_t i16;

// 16 bit unsigned integer
typedef uint16_t u16;

// 32 bit signed integer
typedef int32_t i32;

// 32 bit unsigned integer
typedef uint32_t u32;

// 64 bit signed integer
typedef int64_t i64;

// 64 bit unsigned integer
typedef uint64_t u64;

// 32 bit floating point (single precision)
typedef float f32;

// 64 bit floating point (double precision)
typedef double f64;

//
// String types are used for easy conversion between wchar and char if necessary.
//

// String of characters
typedef std::basic_string<char> String;

// Conversion between characters
#define TO_STRING(x) std::to_string(x)


//
// Common STD usings here that wont conflict with anything
//

using std::cout;
using std::clog;
using std::cerr;