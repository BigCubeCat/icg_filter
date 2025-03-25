#pragma once

inline double bayer(int i, int j, int n) {
    unsigned char b = ~((i % n) ^ (j % n));
    b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
    b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
    b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
    return static_cast<double>(b) / (n * n);
}

#define stepify(x, step) static_cast<uchar>(std::round((x) / (step)) * (step));
