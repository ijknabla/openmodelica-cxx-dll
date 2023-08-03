
#pragma once

#ifdef MOCK_EXPORTS
#define MOCK_DECLSPEC __declspec(dllexport)
#else
#define MOCK_DECLSPEC __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

MOCK_DECLSPEC void hello_world(void);

#ifdef __cplusplus
}
#endif

#undef MOCK_DECLSPEC
