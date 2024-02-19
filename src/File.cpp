#include "File.h"

bool FileExists(const char *filePath)
{
	FILE *file;
	return (file = fopen(filePath, "r")) && !fclose(file);
}
