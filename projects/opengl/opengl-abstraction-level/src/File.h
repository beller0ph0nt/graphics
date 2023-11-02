#pragma once

#include <cerrno>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace fs = std::filesystem;

class File {
public:
    static std::string ReadAll(fs::path&& path);
};