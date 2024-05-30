option(USE_GETLINE "Use my own version of getline" ON)


if (USE_GETLINE)
	add_library(math constants.c operations.c)
	target_compile_definitions(math PRIVATE "USE_GETLINE")
endif()


