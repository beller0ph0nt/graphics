#pragma once

#include <cerrno>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

class File {
public:
	static std::string ReadAll(fs::path&& path);
};