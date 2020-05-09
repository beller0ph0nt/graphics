#pragma once

#include <cerrno>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <experimental\filesystem>

namespace fs = std::experimental::filesystem;

class File {
public:
	static std::string ReadAll(fs::path&& path);
};