#include <fast_io_dsal/vector.h>
#include <fast_io.h>
#include <fast_io_device.h>
#include <fast_io_crypto.h>

int main(int argc, char **argv)
{
	using namespace fast_io::mnp;
	::fast_io::vector<::std::size_t> vec(10000000,5);
	{
		auto t0{fast_io::posix_clock_gettime(fast_io::posix_clock_id::realtime)};
		fast_io::sha512_context ctx;
		::fast_io::operations::write_all_range(as_file(ctx),vec);
		ctx.do_final();
		println(hash_digest(ctx), " *", os_c_str(argv[1]), "\nElapsed Time:", fast_io::posix_clock_gettime(fast_io::posix_clock_id::realtime) - t0);
	}
}

