#pragma once

#ifdef __cplusplus 
	extern const char* const HRON_CONNECTION;
#else
	// please, DON'T do this in production code!
	#define HRON_CONNECTION "hron/password@localhost:5432/hron"
#endif
