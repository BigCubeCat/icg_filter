//
// Created by anton on 3/26/25.
//

#ifndef MEDIANFINDER_H
#define MEDIANFINDER_H
#include <qtypes.h>

#include <queue>
#include <vector>

class MedianFinder {
    public:
    MedianFinder(const int &capacity);
    void push(uchar value);
    void pop();
    uchar median();

private:
    struct HeapNode {
        int q_pos;
        uchar value;
    };
    std::vector<HeapNode> max_heap;
    int max_heap_size;
    std::vector<HeapNode> min_heap;
    int min_heap_size;
    std::vector<int> queue;
    int size;
    int capacity;
    int begin;

private:
    void sift_up_max(int pos);
    void sift_up_min(int pos);
    void sift_down_max(int pos);
    void sift_down_min(int pos);
    void push_min_heap(uchar data, int q_pos);
    void push_max_heap(uchar data, int q_pos);
    void pop_min_heap(int pos);
    void pop_max_heap(int pos);
};



#endif //MEDIANFINDER_H
