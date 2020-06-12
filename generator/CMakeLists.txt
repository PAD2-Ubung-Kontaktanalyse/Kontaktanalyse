set(generator_source_files
  generator.c
  generator.h
)
add_library(generator ${generator_source_files})
target_link_libraries(generator)
