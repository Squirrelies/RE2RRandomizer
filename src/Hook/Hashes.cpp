#include "Hashes.h"

namespace RE2RRHashes
{
	const static std::vector<uint8_t> WW_DX11_20230421_1 = {0xF2, 0x6C, 0xDE, 0xBF, 0xFE, 0x66, 0x55, 0xD0, 0x5B, 0xF0, 0x04, 0x7F, 0x79, 0x39, 0xEA, 0x5E, 0x38, 0x36, 0x08, 0xAF, 0xF4, 0x60, 0x3C, 0xA3, 0xF0, 0xF3, 0x6A, 0x12, 0xDC, 0x56, 0x23, 0xCA};
	const static std::vector<uint8_t> WW_DX12_20230814_1 = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	const static std::vector<uint8_t> CEROZ_DX11_20230421_1 = {0x53, 0xF9, 0x2B, 0x0F, 0x4F, 0x45, 0xB0, 0xF6, 0x6A, 0x18, 0xD1, 0xF0, 0xCB, 0xE4, 0xC9, 0x0C, 0x3D, 0x65, 0x53, 0x2E, 0x50, 0x0A, 0xD8, 0x75, 0xC4, 0x64, 0xCD, 0xBB, 0x33, 0xBF, 0x71, 0xF1};
	const static std::vector<uint8_t> CEROZ_DX12_20230814_1 = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

	bool DetectVersion(const char *filePath, RE2RREnums::RE2RGameVersion &gameVersion, RE2RREnums::RE2RGameEdition &gameEdition, RE2RREnums::RE2RGameDXVersion &gameDXVersion, ImmediateLogger &logger)
	{
		std::unique_ptr<uint8_t[]> gameExeSHA256Hash = RE2RRFile::GetFileHashSHA256(filePath);
		std::vector<uint8_t> hashVector = RE2RRFile::HashSHA256ToVector(gameExeSHA256Hash.get());

		logger.LogMessage("[RE2R-R] Game hash: { %s }\n", RE2RRFile::VectorToHexString(hashVector).get()->c_str());

		bool success = false;
		if (hashVector == WW_DX11_20230421_1)
		{
			gameVersion = RE2RREnums::RE2RGameVersion::RE2R_20230421_1;
			gameEdition = RE2RREnums::RE2RGameEdition::WorldWide;
			gameDXVersion = RE2RREnums::RE2RGameDXVersion::DirectX11;
			success = true;
		}
		else if (hashVector == WW_DX12_20230814_1)
		{
			gameVersion = RE2RREnums::RE2RGameVersion::RE2R_20230814_1;
			gameEdition = RE2RREnums::RE2RGameEdition::WorldWide;
			gameDXVersion = RE2RREnums::RE2RGameDXVersion::DirectX12;
			success = true;
		}
		else if (hashVector == CEROZ_DX11_20230421_1)
		{
			gameVersion = RE2RREnums::RE2RGameVersion::RE2R_20230421_1;
			gameEdition = RE2RREnums::RE2RGameEdition::CeroZ;
			gameDXVersion = RE2RREnums::RE2RGameDXVersion::DirectX11;
			success = true;
		}
		else if (hashVector == CEROZ_DX12_20230814_1)
		{
			gameVersion = RE2RREnums::RE2RGameVersion::RE2R_20230814_1;
			gameEdition = RE2RREnums::RE2RGameEdition::CeroZ;
			gameDXVersion = RE2RREnums::RE2RGameDXVersion::DirectX12;
			success = true;
		}

		if (success)
			logger.LogMessage("[RE2R-R] Game version: %s %s (%s)\n",
			                  RE2RREnums::EnumRE2RGameEditionToString(gameEdition).get()->c_str(),
			                  RE2RREnums::EnumRE2RGameDXVersionToString(gameDXVersion).get()->c_str(),
			                  RE2RREnums::EnumRE2RGameVersionToString(gameVersion).get()->c_str());
		else
			logger.LogMessage("[RE2R-R] Game version: Unknown\n");

		return success;
	}
}
