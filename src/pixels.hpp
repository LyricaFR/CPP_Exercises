#pragma once

#include "../lib/lib.hpp"

#include <stdint.h>

struct RGBA
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

struct RGB
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

struct Luma
{
    uint8_t gray;
};