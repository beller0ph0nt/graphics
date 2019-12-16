#include "File.h"

string File::ReadAll(fs::path&& path)
{
	stringstream ss;
	try
	{
		ifstream file(path);
		file.exceptions(std::iostream::badbit | std::iostream::failbit);
		ss << file.rdbuf();
	}
	catch (exception ex)
	{
		perror("errno: ");
		throw ex;
	}

	return ss.str();
}