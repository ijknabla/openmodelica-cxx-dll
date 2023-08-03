
cmake_minimum_required (VERSION 3.8)

project (Mock)

set(
	OPENMODELICA_VERSION
	"1.21.0"
	CACHE STRING
	"OpenModelica version s.t. `1.21.0`"
)
set(
	OPENMODELICA_HOME
	"C:/Program Files/OpenModelica${OPENMODELICA_VERSION}-64bit"
	CACHE PATH
	"OPENMODELICAHOME environ"
)

add_library (mock SHARED mock.cc)

target_compile_definitions(mock PRIVATE MOCK_EXPORTS)

target_include_directories(
	mock
	INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}
)

set(
	LIBRARY_MINGW64 ${CMAKE_SOURCE_DIR}/../modelica/Resources/Library/mingw64
)

set_target_properties(
	mock
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY_DEBUG ${LIBRARY_MINGW64}
	RUNTIME_OUTPUT_DIRECTORY_RELEASE ${LIBRARY_MINGW64}
	RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${LIBRARY_MINGW64}
)

set(MINGW64_BIN ${OPENMODELICA_HOME}/tools/msys/mingw64/bin)

add_custom_target(
	mock_def ALL
	COMMAND ${MINGW64_BIN}/gendef ${LIBRARY_MINGW64}/mock.dll
	DEPENDS mock
)
