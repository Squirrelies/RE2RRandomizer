#include "Hashes.h"

namespace RE2RRHashes
{
	const static std::vector<uint8_t> WW_DX11_20230421_1 = {0xF2, 0x6C, 0xDE, 0xBF, 0xFE, 0x66, 0x55, 0xD0, 0x5B, 0xF0, 0x04, 0x7F, 0x79, 0x39, 0xEA, 0x5E, 0x38, 0x36, 0x08, 0xAF, 0xF4, 0x60, 0x3C, 0xA3, 0xF0, 0xF3, 0x6A, 0x12, 0xDC, 0x56, 0x23, 0xCA};
	const static std::vector<uint8_t> WW_DX12_20230814_1 = {};
	const static std::vector<uint8_t> CEROZ_DX11_20230421_1 = {};
	const static std::vector<uint8_t> CEROZ_DX12_20230814_1 = {};

	RE2RREnums::RE2RGameVersion DetectVersion(const char *filePath)
	{
		uint8_t *gameExeSHA256Hash = RE2RRFile::GetFileHashSHA256(filePath);
		std::vector<uint8_t> hashVector = RE2RRFile::HashSHA256ToVector(gameExeSHA256Hash);
		free(gameExeSHA256Hash);

		printf("[RE2R-R] Game hash: { %s }\n", RE2RRFile::VectorToHexString(hashVector).c_str());

		RE2RREnums::RE2RGameVersion returnValue = RE2RREnums::RE2RGameVersion::Unknown;
		if (hashVector == WW_DX11_20230421_1)
			returnValue = RE2RREnums::RE2RGameVersion::WW_DX11_20230421_1;
		else if (hashVector == WW_DX12_20230814_1)
			returnValue = RE2RREnums::RE2RGameVersion::WW_DX12_20230814_1;
		else if (hashVector == CEROZ_DX11_20230421_1)
			returnValue = RE2RREnums::RE2RGameVersion::CEROZ_DX11_20230421_1;
		else if (hashVector == CEROZ_DX12_20230814_1)
			returnValue = RE2RREnums::RE2RGameVersion::CEROZ_DX12_20230814_1;

		printf("[RE2R-R] Game version: %s\n", RE2RREnums::EnumRE2RGameVersionToString(returnValue).c_str());

		return returnValue;
	}
}
