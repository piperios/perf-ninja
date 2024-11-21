#include <cstddef>

// Simplest one-time arena allocator
// T - type of objects.
// N - size in bytes.
// Allocate objects of T consecutively.
template<class T, size_t N> class arena
{
public:
    arena() : _curr_ptr(_arena) {}

    arena(arena const&) = delete;
    arena& operator=(arena const&) = delete;

    T* allocate()
    {
        auto end_ptr = _arena + N;
        if (end_ptr - _curr_ptr < sizeof(T)) return nullptr;

        T* save_ptr = (T*)_curr_ptr;
        _curr_ptr += sizeof(T);
        return save_ptr;
    }

    // no dealloc method - rely on RAII to dealloc arena

private:
    alignas(128) std::byte _arena[N];
    std::byte* _curr_ptr = nullptr;
};
