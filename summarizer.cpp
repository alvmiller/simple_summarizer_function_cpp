#include <cassert>
#include <utility>

constexpr int sum()
{
    return 0;
}

template <typename T, typename ... Ts>
constexpr auto sum(T&& arg, Ts&& ... args) {
// constexpr decltype(auto) sum_st(T&& arg, Ts&& ... args) {
// constexpr T sum_st(T&& arg, Ts&& ... args) {
    return arg + sum(std::forward<Ts>(args)...);
    // return arg + sum_st((args)...);
}


int main()
{
    constexpr int res = sum(1,2,3);
    static_assert(res == 6, "Bad compile time summary");
    assert(res == 6);

    return 0;
}
