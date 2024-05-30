option(USE_GETLINE "Use my own version of getline" ON)

add_library(math constants.c)
if (USE_GETLINE)
	target_sources(math PUBLIC operations.c)
	target_compile_definitions(math PUBLIC USE_GETLINE)
endif()


