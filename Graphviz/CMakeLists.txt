set(graphviz_source_files
  create_list_interactions.c
  create_list_interactions.h
  generate_list_persons.c
  generate_list_persons.h
  generate_txt_file.c
  generate_txt_file.h
)
add_library(graphviz ${js_source_files})
target_link_libraries(graphviz)
