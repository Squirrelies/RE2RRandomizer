#include "File.h"
#include "sha-256.h"

namespace RE2RR::Common::File
{
	bool FileExists(const char *filePath)
	{
		FILE *file;
		return (file = fopen64(filePath, "rb")) && !fclose(file);
	}

	size_t GetFileSizeT(const char *filePath)
	{
		FILE *file = fopen64(filePath, "rb");

		if (file == nullptr)
			return -1LL; // Unable to open!

		if (fseeko64(file, 0LL, SEEK_END) < 0LL)
		{
			fclose(file);
			return -1LL; // Unable to seek!
		}

		size_t size = ftello64(file);
		fclose(file);
		return size;
	}

	std::unique_ptr<uint8_t[]> GetFileHashSHA256(const char *filePath)
	{
		const int bufferSize = SIZE_OF_SHA_256_CHUNK * SIZE_OF_SHA_256_CHUNK;

		FILE *file = fopen64(filePath, "rb");
		if (file == nullptr)
			return nullptr;

		std::unique_ptr<uint8_t[]> hash = std::make_unique<uint8_t[]>(SIZE_OF_SHA_256_HASH);
		struct Sha_256 sha_256;
		sha_256_init(&sha_256, hash.get());

		size_t fileSize = GetFileSizeT(filePath);
		std::unique_ptr<uint8_t[]> fileData = std::make_unique<uint8_t[]>(bufferSize);
		size_t totalBytesRead = 0;
		size_t bytesRead = 0;
		int error = 0;
		int eof = 0;
		do
		{
			bytesRead = fread(fileData.get(), sizeof(uint8_t), bufferSize, file);
			sha_256_write(&sha_256, fileData.get(), bytesRead);
			totalBytesRead += bytesRead;
			error = ferror(file);
			eof = feof(file);
			clearerr(file);
		} while ((totalBytesRead < fileSize) && !error && !eof);
		fclose(file);
		sha_256_close(&sha_256);

		if (error)
			return nullptr;

		return hash;
	}

	std::vector<uint8_t> HashSHA256ToVector(const uint8_t *hash)
	{
		return std::vector<uint8_t>(hash, hash + SIZE_OF_SHA_256_HASH);
	}

	std::unique_ptr<std::string> VectorToHexString(std::vector<uint8_t> &vector)
	{
		size_t vectorSize = vector.size();
		size_t bufferSize = (vectorSize * 6) - 2 + 1;

		std::unique_ptr<char[]> toString = std::make_unique<char[]>(bufferSize);
		memset(toString.get(), 0, bufferSize);

		for (size_t i = 0; i < vectorSize; ++i)
		{
			if (i < vectorSize - 1)
				snprintf(toString.get() + (i * 6), 7, "0x%02X, ", vector[i]);
			else
				snprintf(toString.get() + (i * 6), 5, "0x%02X", vector[i]);
		}

		return std::make_unique<std::string>(toString.get());
	}
}
