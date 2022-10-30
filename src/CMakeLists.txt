include_directories(${CMAKE_CURRENT_SOURCE_DIR})

aux_source_directory(./pipeline pipeline_src)

add_library(media_server ${pipeline_src})
