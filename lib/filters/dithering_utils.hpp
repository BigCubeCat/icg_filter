#pragma once



#define stepify(x, step) static_cast<uchar>(std::round((x) / (step)) * (step))
