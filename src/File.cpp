#include "File.h"

bool RE2RRFile::FileExists(const char *filePath)
{
	FILE *file;
	return (file = fopen64(filePath, "rb")) && !fclose(file);
}

int64_t RE2RRFile::GetFileSize(const char *filePath)
{
	FILE *file = fopen64(filePath, "rb");

	if (file == nullptr)
		return -1LL; // Unable to open!

	if (fseeko64(file, 0LL, SEEK_END) < 0LL)
	{
		fclose(file);
		return -1LL; // Unable to seek!
	}

	uint64_t size = ftello64(file);
	fclose(file);
	return size;
}

// Test Hash for re2.exe
// { 0xF2, 0x6C, 0xDE, 0xBF, 0xFE, 0x66, 0x55, 0xD0, 0x5B, 0xF0, 0x04, 0x7F, 0x79, 0x39, 0xEA, 0x5E, 0x38, 0x36, 0x08, 0xAF, 0xF4, 0x60, 0x3C, 0xA3, 0xF0, 0xF3, 0x6A, 0x12, 0xDC, 0x56, 0x23, 0xCA };
// or
// { 242, 108, 222, 191, 254, 102, 85, 208, 91, 240, 4, 127, 121, 57, 234, 94, 56, 54, 8, 175, 244, 96, 60, 163, 240, 243, 106, 18, 220, 86, 35, 202 };
uint8_t *RE2RRFile::GetFileHashSHA256(const char *filePath)
{
	const int bufferSize = SIZE_OF_SHA_256_CHUNK * SIZE_OF_SHA_256_CHUNK;

	FILE *file = fopen64(filePath, "rb");
	if (file == nullptr)
		return nullptr;

	uint8_t *hash = (uint8_t *)malloc(SIZE_OF_SHA_256_HASH);
	struct Sha_256 sha_256;
	sha_256_init(&sha_256, hash);

	int64_t fileSize = GetFileSize(filePath);
	uint8_t *fileData = (uint8_t *)malloc(bufferSize);
	size_t totalBytesRead = 0;
	size_t bytesRead = 0;
	do
	{
		bytesRead += fread(fileData, sizeof(uint8_t), bufferSize, file);
		sha_256_write(&sha_256, fileData, bytesRead);
		totalBytesRead += bytesRead;
	} while ((totalBytesRead < fileSize) && ferror(file) && feof(file));
	free(fileData);
	fclose(file);
	sha_256_close(&sha_256);

	return hash;
}
