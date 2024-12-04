#include<fast_io.h>
#include<fast_io_dsal/vector.h>
#include<fast_io_driver/timer.h>

int main()
{
	constexpr ::std::size_t N{5000000};
	::std::size_t capacity{};
	{
		::fast_io::timer timer_total(u8"::fast_io::vector<::std::size_t>");
		::fast_io::vector<::std::size_t> vec;
		{
			::fast_io::timer timer_push_back(u8"::fast_io::vector<::std::size_t> push_back");
			for(::std::size_t i{};i!=N;++i)
			{
				vec.push_back(i);
			}
		}
		capacity = vec.capacity();
	}
	::fast_io::io::println("vec capacity:",capacity);
}

