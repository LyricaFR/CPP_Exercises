#pragma once

#include "pixels.hpp"

#include "../lib/lib.hpp"

#include <stdint.h>
#include <cstddef>
#include <functional>
#include <string>
#include <array>
#include <iostream>

template<typename P, size_t W, size_t H>
class Image
{
    public:

    Image() = default;

    Image(const P& pix){
        for (size_t i = 0; i < H ; i++){
            for (size_t j = 0; j < W; j++){
                img[i][j] = pix;
            }
        }
    }

    P & operator()(const size_t i, const size_t j){
        return img[j][i];
    }

    const P & operator()(const size_t i, const size_t j) const{
        return img[j][i];
    }

    friend Image<P,W,H> operator+(const Image<P, W, H>& img1, const Image<P, W, H>& img2){
        auto result = Image<P, W, H>();
        for (size_t i = 0; i < H ; i++){
            for (size_t j = 0; j < W; j++){
                result(i,j) = img1(i, j) + img2(i, j);
            }
        }
        return result;
    }

    Image<P, W, H>(const std::function<P(const size_t i, const size_t j)> & functor)
    {
        for (size_t i = 0; i < H ; i++){
            for (size_t j = 0; j < W; j++){
                img[i][j] = functor(j, i);
            }
        }
    }

    private:
    std::array<std::array<P, W>, H> img;
};


