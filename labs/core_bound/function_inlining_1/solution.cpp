
#include "solution.h"

#include <algorithm>
#include <cstdlib>

void solution(std::array<S, N>& arr) {
    std::sort(arr.begin(), arr.end(), [](S const& a, S const& b) -> int { return a.key1 < b.key1 || (a.key1 == b.key1) && (a.key2 < b.key2); });
}
