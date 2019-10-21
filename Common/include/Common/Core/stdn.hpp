#pragma once
// Standard Number Header
//
// Uses: Shorthand stdint, std floats
//

#include <iostream>
#include <stdint.h>
#include <string>

typedef int8_t int8;
typedef uint8_t uint8;
typedef int16_t int16;
typedef uint16_t uint16;
typedef int32_t int32;
typedef uint32_t uint32;
typedef int64_t int64;
typedef uint64_t uint64;

typedef char TChar;

typedef std::basic_string<TChar> String;
#define TO_STRING(x) std::to_string(x)

typedef float float32;
typedef double float64;

typedef float32 tfloat;

using std::clog;
using std::cerr;