cmake_minimum_required(VERSION 3.22.1)
project(Meshell C)


add_executable(meshell src/utils.c src/parser.c src/meshellcfg.c src/main.c)


if (USE_GETLINE)
	add_subdirectory(include/custom_math)
	target_include_directories(math PUBLIC
		"${PROJECT_BINARY_DIR}"
		"${PROJECT_SOURCE_DIR}/lib/math"
	)
	
	target_link_libraries(meshell math)
endif()



