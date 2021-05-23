add_executable(benchmarks benchmarks.cpp)

target_link_libraries(benchmarks PRIVATE project_paths project_warnings ${PROJECT_NAME})
