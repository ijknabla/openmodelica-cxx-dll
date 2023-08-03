
cmake_minimum_required (VERSION 3.8)

project (Mock)

add_library (mock SHARED mock.cc)

target_compile_definitions(mock PRIVATE MOCK_EXPORTS)

target_include_directories(
	mock
	INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}
)
