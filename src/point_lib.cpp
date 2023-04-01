module;

#include <array>
#include <iostream>
#include <concepts>
#include <type_traits>
#include <iterator>
#include <random>
#include <algorithm>
#include <ranges>

export module point_lib;

export
template <std::floating_point Real>
struct Point2
{
    Real x, y;

    template <int min, int max>
    static Point2<Real> random_point ()
    {
        return {
            static_cast<Real> (rand()) / static_cast<Real> (RAND_MAX / (max - min)) + min,
            static_cast<Real> (rand()) / static_cast<Real> (RAND_MAX / (max - min)) + min
        };
    }
};

export
template <std::floating_point Real>
void normalize_points(auto start, auto end, auto out)
{
    const auto subrange = std::ranges::subrange(start, end);
    const auto xs = subrange | std::views::transform([] (auto pt) { return pt.x; });
    const auto ys = subrange | std::views::transform([] (auto pt) { return pt.y; });

    const auto boundsX = std::ranges::minmax(xs);
    const auto boundsY = std::ranges::minmax(ys);
    const auto maxD = std::max(boundsX.max - boundsX.min, boundsY.max - boundsY.min);

    std::transform(start, end, out, [&] (auto pt) -> Point2<Real>
    {
        return {(pt.x - boundsX.min) / maxD, (pt.y - boundsY.min) / maxD};
    });
}


