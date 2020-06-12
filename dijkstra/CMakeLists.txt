set(dijkstra_source_files
  interp.c
  interp.h
  js.c
  js.h
)
add_library(dijkstra ${dijkstra_source_files})

target_link_libraries(dijkstra)
