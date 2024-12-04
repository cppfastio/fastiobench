#include <string>
#include <fast_io.h>
#include <version>

struct benchmark_return {
  std::size_t total_size{};
  fast_io::unix_timestamp timestamp{};
};

template <typename Func> inline benchmark_return benchmark(Func meth) {
  std::size_t total_size{};
  auto start{
      fast_io::posix_clock_gettime(fast_io::posix_clock_id::monotonic_raw)};
  for (std::uint_least16_t r{}; r != 256; ++r) {
    for (std::uint_least16_t g{}; g != 256; ++g) {
      for (std::uint_least16_t b{}; b != 256; ++b) {
        total_size += meth(static_cast<::std::uint_least8_t>(r),
                           static_cast<::std::uint_least8_t>(g),
                           static_cast<::std::uint_least8_t>(b))
                          .size();
      }
    }
  }
  return {total_size,
          fast_io::posix_clock_gettime(fast_io::posix_clock_id::monotonic_raw) -
              start};
}

inline auto color_concat(std::uint_least8_t r, std::uint_least8_t g,
                         std::uint_least8_t b) {
  return ::fast_io::concat_std("Red: ", r, ", Green: ", g, ", Blue: ", b);
}

int main() {
  auto concat_time = benchmark(color_concat);
  using namespace fast_io::io;
  perrln("concat_string:", concat_time.timestamp, "s");
  print("fast_io::concat_std (total size: ", concat_time.total_size, ") took ",
        concat_time.timestamp, "s.\n");
}
