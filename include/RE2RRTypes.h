#ifndef RE2RR_RE2RRTYPES_H
#define RE2RR_RE2RRTYPES_H

#ifdef __GNUC__
#define UNUSED(x) UNUSED_##x __attribute__((__unused__))
#else
#define UNUSED(x) UNUSED_##x
#endif

#ifdef __GNUC__
#define UNUSED_FUNCTION(x) __attribute__((__unused__)) UNUSED_##x
#else
#define UNUSED_FUNCTION(x) UNUSED_##x
#endif

enum RE2RRCharacter
{
	Leon = 0,
	Claire = 1
};

enum RE2RRScenario
{
	A = 0,
	B = 1
};

enum RE2RRDifficulty
{
	Assisted = 0,
	Standard = 1,
	Hardcore = 2
};

#endif