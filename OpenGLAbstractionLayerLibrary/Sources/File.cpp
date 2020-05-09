#include "File.h"

std::string File::ReadAll(fs::path&& path) {
	std::stringstream ss;
	try
	{
		std::ifstream file(path);
		file.exceptions(std::iostream::badbit | std::iostream::failbit);
		ss << file.rdbuf();
	}
	catch (std::exception& ex)
	{
		perror("file read error");
		throw ex;
	}

	return ss.str();
}