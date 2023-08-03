
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
