
#include <array>
#include <cstddef>
#include <iostream>
#include <string>
#include <string_view> // c++17
// constexpr function
constexpr int pow(int base, int exp) noexcept {
  auto result = 1;
  for (size_t i = 0; i < exp; ++i) {
    result *= base;
  }
  return result;
}

// constexpr class
class Point {
public:
  constexpr Point(double x_val = 0, double y_val = 0) noexcept
      : x(x_val), y(y_val) {}

  constexpr double XVal() const noexcept { return x; }

  constexpr double YVal() const noexcept { return y; }

  constexpr void SetX(double new_x) noexcept { x = new_x; }

  constexpr void SetY(double new_y) noexcept { y = new_y; }

private:
  double x;
  double y;
};

constexpr Point MidPoint(const Point &p1, const Point &p2) {
  Point mid{(p1.XVal() + p2.XVal()) / 2, (p1.YVal() + p2.YVal()) / 2};
  return mid;
}

constexpr Point Reflection(const Point &p1) {
  Point result;

  result.SetX(-p1.XVal());
  result.SetY(-p1.YVal());

  return result;
}

int main(void) {
  constexpr auto num_exp = 5;

  std::array<int, pow(3, num_exp)> results;

  std::cout << results.size() << "\n";

  constexpr Point p1{0.1, 0.9};
  constexpr Point p2{0.2, 0.7};

  auto mid_point = MidPoint(p1, p2);
  auto reflect_mid = Reflection(mid_point);

  std::cout << p1.XVal() << " " << p1.YVal() << "\n";
  std::cout << p2.XVal() << " " << p2.YVal() << "\n";


  std::cout << mid_point.XVal() << " " << mid_point.YVal() << "\n";
  std::cout << reflect_mid.XVal() << " " << reflect_mid.YVal() << "\n";

  return 0;
}