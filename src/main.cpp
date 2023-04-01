#include <iostream>
import point_lib;

int main ()
{
    const auto random_point = []() -> Point2<float> {
        return Point2<float>::random_point<0, 5>();
    };

    static std::array<Point2<float>, 10> points {};
    static std::array<Point2<float>, 10> norm {};
    std::generate(points.begin(), points.end(), random_point);

    for (const auto& p : points)
    {
        std::cout << p.x << ", " << p.y << "\n";
    }

    normalize_points<float>(points.begin(), points.end(), norm.begin());

    for (const auto& p : norm)
    {
        std::cout << p.x << ", " << p.y << "\n";
    }

    return 0;
}

