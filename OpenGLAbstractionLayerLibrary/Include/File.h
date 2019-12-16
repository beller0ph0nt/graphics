#pragma once

#include <cerrno>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <experimental\filesystem>

using namespace std;
namespace fs = std::experimental::filesystem;

class File
{
public:
	static string ReadAll(fs::path&& path);
};