#include <cassert>
#include <utility>

// -----------------------------------------------------------------------------

constexpr auto sumi()
{
    return 0;
}

template <typename T, typename ... Ts>
constexpr auto sumi(T arg, Ts ... args) {
    static_assert(std::is_integral<T>::value, "Integral required");
    return arg + sumi((args)...);
}


// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

constexpr auto sum()
{
    return 0;
}

template <typename T, typename ... Ts>
constexpr auto sum(T&& arg, Ts&& ... args) {
// constexpr auto sum(T arg, Ts ... args) {
// constexpr decltype(auto) sum(T&& arg, Ts&& ... args) {
    // return arg + sum((args)...);
    return arg + sum(std::forward<Ts>(args)...);
}

// -----------------------------------------------------------------------------

int main()
{
    constexpr int res = sum(1,2,3);
    static_assert(res == 6, "Bad compile time summary");
    assert(res == 6);
    
    constexpr int resi = sumi(1,2,3);
    static_assert(resi == 6, "Bad compile time summary");
    assert(resi == 6);

    return 0;
}
