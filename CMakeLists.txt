cmake_minimum_required(VERSION 3.22.1)
project(Meshell C)


add_subdirectory(include/custom_math)
add_executable(meshell src/utils.c src/parser.c src/meshellcfg.c src/main.c)
target_include_directories(math PUBLIC
	"${PROJECT_BINARY_DIR}"
	"${PROJECT_SOURCE_DIR}/lib/math"
)


target_link_libraries(meshell math)

