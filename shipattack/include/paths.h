//Header file to contain paths
#include <string>
#include <boost/filesystem.hpp>



namespace paths {
	using namespace boost::filesystem;
	path PROJ_DIRECTORY = path(__FILE__);
	path PATH_IMG = path(PROJ_DIRECTORY).parent_path().parent_path().append("img");
	const std::string IMG_BACKGROUND = path(PATH_IMG).append("background.jpg").string();
};
