//
// Created by anton on 3/26/25.
//

#include "MedianFinder.h"

#include <qalgorithms.h>

#include <iostream>
MedianFinder::MedianFinder(const int& capacity) : size(0), capacity(capacity) {
    queue.resize(capacity);
    for (int i = 0; i < queue.size(); i++) {
        queue[i] = -1;
    }

    min_heap.resize(capacity);
    max_heap.resize(capacity);
    min_heap_size = 0;
    max_heap_size = 0;
    begin = 0;
}

void MedianFinder::push(uchar value) {
    if (size == capacity) {
        return;
    }
    if (!max_heap_size || value < max_heap[0].value) {
        if (max_heap_size > min_heap_size) {
            int tmp_q_pos = max_heap[0].q_pos;
            uchar tmp_value = max_heap[0].value;
            pop_max_heap(0);
            push_min_heap(tmp_value, tmp_q_pos);
        }
        push_max_heap(value, (begin + size) % capacity);
    } else if (!min_heap_size || value > min_heap[0].value) {
        if (min_heap_size > max_heap_size) {
            int tmp_q_pos = min_heap[0].q_pos;
            uchar tmp_value = min_heap[0].value;
            pop_min_heap(0);
            push_max_heap(tmp_value, tmp_q_pos);
        }
        push_min_heap(value, (begin + size) % capacity);
    } else {
        if (min_heap_size > max_heap_size) {
            push_max_heap(value, (begin + size) % capacity);
        } else {
            push_min_heap(value, (begin + size) % capacity);
        }
    }
    ++size;
}

void MedianFinder::pop() {
    if (queue[begin] >= capacity) {
        //min heap
        pop_min_heap(queue[begin] - capacity);
        if (max_heap_size > min_heap_size + 1) {
            int tmp_q_pos = max_heap[0].q_pos;
            uchar tmp_value = max_heap[0].value;
            pop_max_heap(0);
            push_min_heap(tmp_value, tmp_q_pos);
        }
    } else {
        //max heap
        pop_max_heap(queue[begin]);
        if (min_heap_size > max_heap_size + 1) {
            int tmp_q_pos = min_heap[0].q_pos;
            uchar tmp_value = min_heap[0].value;
            pop_min_heap(0);
            push_max_heap(tmp_value, tmp_q_pos);
        }
    }
    begin = (begin + 1) % capacity;
    --size;
}
uchar MedianFinder::median() {
    std::cout << max_heap_size << " " << min_heap_size << std::endl;
    if (max_heap_size > min_heap_size) {
        return max_heap[0].value;
    }
    return min_heap[0].value;
}

void MedianFinder::sift_up_max(int pos) {
    if (pos == 0)
        return;
    if (max_heap[(pos - 1) / 2].value < max_heap[pos].value) {
        std::swap(max_heap[pos], max_heap[(pos - 1) / 2]);
        queue[max_heap[pos].q_pos] = pos;
        assert(queue[max_heap[pos].q_pos] == pos);
        queue[max_heap[(pos - 1) / 2].q_pos] = (pos - 1) / 2;
        assert(queue[max_heap[(pos -1)/2].q_pos] == (pos -1) /2);
        sift_up_max((pos - 1) / 2);
    }
}
void MedianFinder::sift_up_min(int pos) {
    if (pos == 0)
        return;
    if (min_heap[(pos - 1) / 2].value > min_heap[pos].value) {
        std::swap(min_heap[pos], min_heap[(pos - 1) / 2]);
        queue[min_heap[pos].q_pos] = pos + capacity;
        assert(queue[min_heap[pos].q_pos] == pos + capacity);
        queue[min_heap[(pos - 1) / 2].q_pos] = (pos - 1) / 2 + capacity;
        assert(queue[min_heap[(pos - 1) /2 ].q_pos] == (pos - 1)/2 + capacity);
        sift_up_min((pos - 1) / 2);
    }
}
void MedianFinder::sift_down_max(int pos) {
    int left_val = 0;
    int right_val = 0;
    bool left_exist = false;
    bool right_exist = false;
    if ((left_exist = (pos * 2 + 1 < max_heap_size))) {
        left_val = max_heap[pos * 2 + 1].value;
    }
    if ((right_exist = pos * 2 + 2 < max_heap_size)) {
        right_val = max_heap[pos * 2 + 2].value;
    }

    if (left_exist && (left_val > max_heap[pos].value) &&
        (left_val >= right_val)) {
        std::swap(max_heap[pos], max_heap[pos * 2 + 1]);
        queue[max_heap[pos].q_pos] = pos;
        assert(queue[max_heap[pos].q_pos] == pos);
        queue[max_heap[pos * 2 + 1].q_pos] = pos * 2 + 1;
        assert(queue[max_heap[pos * 2 + 1].q_pos] == pos * 2 + 1);
        sift_down_max(pos * 2 + 1);
    } else if (right_exist && (right_val > max_heap[pos].value) &&
               (right_val >= left_val)) {
        std::swap(max_heap[pos], max_heap[pos * 2 + 2]);
        queue[max_heap[pos].q_pos] = pos;
        assert(queue[max_heap[pos].q_pos] == pos);
        queue[max_heap[pos * 2 + 2].q_pos] = pos * 2 + 2;
        assert(queue[max_heap[pos * 2 + 2].q_pos] == pos * 2 + 2);
        sift_down_max(pos * 2 + 2);
    }
}
void MedianFinder::sift_down_min(int pos) {
    int left_val = 0;
    int right_val = 0;
    bool left_exist = false;
    bool right_exist = false;
    if ((left_exist = (pos * 2 + 1 < min_heap_size))) {
        left_val = min_heap[pos * 2 + 1].value;
    }
    if ((right_exist = pos * 2 + 2 < min_heap_size)) {
        right_val = min_heap[pos * 2 + 2].value;
    }

    if (left_exist && (left_val < min_heap[pos].value) &&
        (left_val <= right_val)) {
        std::swap(min_heap[pos], min_heap[pos * 2 + 1]);
        queue[min_heap[pos].q_pos] = pos + capacity;
        assert(queue[min_heap[pos].q_pos] == pos + capacity);
        queue[min_heap[pos * 2 + 1].q_pos] = pos * 2 + 1 + capacity;
        assert(queue[min_heap[pos * 2 + 1].q_pos] == pos * 2 + 1 + capacity);
        sift_down_min(pos * 2 + 1);
    } else if (right_exist && (right_val < min_heap[pos].value) &&
               (right_val <= left_val)) {
        std::swap(min_heap[pos], min_heap[pos * 2 + 2]);
        queue[min_heap[pos].q_pos] = pos + capacity;
        assert(queue[min_heap[pos].q_pos] == pos + capacity);
        queue[min_heap[pos * 2 + 2].q_pos] = pos * 2 + 2 + capacity;
        assert(queue[min_heap[pos * 2 + 2].q_pos] == pos * 2 + 2 + capacity);
        sift_down_min(pos * 2 + 2);
    }
}
void MedianFinder::push_min_heap(uchar data, int q_pos) {
    min_heap[min_heap_size].value = data;
    min_heap[min_heap_size].q_pos = q_pos;
    queue[q_pos] = min_heap_size + capacity;
    sift_up_min(min_heap_size);
    assert(queue[min_heap[min_heap_size].q_pos] == min_heap_size + capacity);
    min_heap_size++;
}
void MedianFinder::push_max_heap(uchar data, int q_pos) {
    max_heap[max_heap_size].value = data;
    max_heap[max_heap_size].q_pos = q_pos;
    queue[q_pos] = max_heap_size;
    assert(queue[max_heap[max_heap_size].q_pos] == max_heap_size);
    sift_up_max(max_heap_size);
    max_heap_size++;
}
void MedianFinder::pop_min_heap(int pos) {
    assert(queue[min_heap[pos].q_pos] == pos + capacity);
    queue[min_heap[pos].q_pos] = -2;
    if (pos == min_heap_size - 1) {
        min_heap_size--;
        return;
    }
    min_heap_size--;
    min_heap[pos] = min_heap[min_heap_size];
    queue[min_heap[pos].q_pos] = pos + capacity;
    sift_down_min(pos);
}
void MedianFinder::pop_max_heap(int pos) {
    assert(queue[max_heap[pos].q_pos] == pos);
    queue[max_heap[pos].q_pos] = -2;
    if (pos == max_heap_size - 1) {
        max_heap_size--;
        return;
    }
    max_heap_size--;
    max_heap[pos] = max_heap[max_heap_size];
    queue[max_heap[pos].q_pos] = pos;
    sift_down_max(pos);
}