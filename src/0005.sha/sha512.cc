#include <fast_io_dsal/vector.h>
#include <fast_io.h>
#include <fast_io_device.h>
#include <fast_io_crypto.h>

int main()
{
	using namespace fast_io::mnp;
	::fast_io::vector<::std::size_t> vec(10000000,5);
	{
		auto t0{fast_io::posix_clock_gettime(fast_io::posix_clock_id::realtime)};
		fast_io::sha512_context ctx;
		::fast_io::operations::write_all_range(as_file(ctx),vec);
		ctx.do_final();
		println(hash_digest(ctx), "\nElapsed Time:", fast_io::posix_clock_gettime(fast_io::posix_clock_id::realtime) - t0);
	}
}
