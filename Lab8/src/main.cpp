//
// Created by Riddleton on 17.05.2025.
//

#include <algorithm>
#include <iterator>
#include <functional>
#include <utility>

template <class It, class Out, class Compare = std::less<>>
Out merge(It first1, It last1, It first2, It last2, Out out, Compare cmp = Compare{}) {
    while (first1 != last1 && first2 != last2) {
        if (cmp(*first1, *first2)) {
            *out++ = *first1++;
        } else {
            *out++ = *first2++;
        }
    }
    return std::copy(first2, last2, std::copy(first1, last1, out));
}

template <class It, class Out, class Compare = std::less<>>
Out merge_sort(It first, It last, Out out, Compare cmp = Compare{}) {
    const auto len = std::distance(first, last);
    if (len <= 1) {
        return std::copy(first, last, out);
    }

    const auto mid = std::next(first, len / 2);
    std::vector<typename std::iterator_traits<It>::value_type> left(first, mid);
    std::vector<typename std::iterator_traits<It>::value_type> right(mid, last);

    std::vector<typename std::iterator_traits<It>::value_type> temp_left_result;
    merge_sort(left.begin(), left.end(), std::back_inserter(temp_left_result), cmp);

    std::vector<typename std::iterator_traits<It>::value_type> temp_right_result;
    merge_sort(right.begin(), right.end(), std::back_inserter(temp_right_result), cmp);

    return merge(temp_left_result.begin(), temp_left_result.end(),
                temp_right_result.begin(), temp_right_result.end(),
                out, cmp);
}

template <class It, class Compare>
void inplace_merge(It first, It mid, It last, Compare cmp) {
    It i = first;
    It j = mid;
    while (i != mid && j != last) {
        if (cmp(*j, *i)) {
            typename std::iterator_traits<It>::value_type val = std::move(*j);
            It k = j;
            do {
                *k = std::move(*std::prev(k));
                --k;
            } while (k != i);
            *i = std::move(val);
            ++mid;
            ++j;
        }
        ++i;
    }
}

template <class It, class Compare = std::less<>>
void inplace_merge_sort(It first, It last, Compare cmp = Compare{}) {
    const auto len = std::distance(first, last);
    if (len <= 1) return;

    const auto mid = std::next(first, len / 2);
    inplace_merge_sort(first, mid, cmp);
    inplace_merge_sort(mid, last, cmp);
    inplace_merge(first, mid, last, cmp);
}

template <class It, class Compare>
void sift_down(It first, It last, It start, Compare cmp) {
    auto parent = start;
    auto child = std::next(first, 2 * (std::distance(first, parent) + 1) - 1);

    while (child < last) {
        if (std::next(child) < last && cmp(*child, *std::next(child))) {
            ++child;
        }
        if (!cmp(*parent, *child)) {
            return;
        }
        std::iter_swap(parent, child);
        parent = child;
        child = std::next(first, 2 * (std::distance(first, parent) + 1) - 1);
    }
}

template <class It, class Compare>
void heapify(It first, It last, Compare cmp) {
    const auto len = std::distance(first, last);
    if (len <= 1) return;

    for (auto i = std::next(first, (len - 2) / 2); i >= first; --i) {
        sift_down(first, last, i, cmp);
    }
}

// Пирамидальная сортировка
template <class It, class Compare = std::less<>>
void heap_sort(It first, It last, Compare cmp = Compare{}) {
    heapify(first, last, cmp);
    for (auto i = last; i != first; --i) {
        std::iter_swap(first, std::prev(i));
        sift_down(first, std::prev(i), first, cmp);
    }
}

template <class It, class Compare = std::less<>>
void quick_sort(It first, It last, Compare cmp = Compare{}) {
    const auto len = std::distance(first, last);
    if (len <= 1) return;

    auto pivot = *std::next(first, len / 2);
    auto middle1 = std::partition(first, last, [&](const auto& val) { return cmp(val, pivot); });
    auto middle2 = std::partition(middle1, last, [&](const auto& val) { return !cmp(pivot, val); });

    quick_sort(first, middle1, cmp);
    quick_sort(middle2, last, cmp);
}

template <class It, class Compare = std::less<>>
void insertion_sort(It first, It last, Compare cmp = Compare{}) {
    if (first == last) return;

    for (auto i = std::next(first); i != last; ++i) {
        auto key = std::move(*i);
        auto j = i;

        while (j != first && cmp(key, *std::prev(j))) {
            *j = std::move(*std::prev(j));
            --j;
        }

        *j = std::move(key);
    }
}