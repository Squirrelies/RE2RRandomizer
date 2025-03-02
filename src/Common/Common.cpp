#include "Common.h"

namespace RE2RR::Common::Version
{
	const std::string GetVersionString()
	{
		std::string versionCore = std::format("{:d}.{:d}.{:d}", Major, Minor, Patch);
		std::string versionPreRelease;
		std::string versionBuildMetadata;

		if (!PreReleaseTag.empty())
			versionPreRelease = std::format("-{:s}", PreReleaseTag);

		if (Build != 0)
		{
			if (versionBuildMetadata.empty())
				versionBuildMetadata = "+";
			else
				versionBuildMetadata += ".";

			versionBuildMetadata += std::format("{:d}", Build);
		}

		if (!BuildHash.empty())
		{
			if (versionBuildMetadata.empty())
				versionBuildMetadata = "+";
			else
				versionBuildMetadata += ".";

			versionBuildMetadata += std::format("{:s}", BuildHash);
		}

		return versionCore + versionPreRelease + versionBuildMetadata;
	}
}
