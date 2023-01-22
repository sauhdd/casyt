#   /tools/CMakeLists.txt
#
#  Created at 2023-01-22 by @sauhd.
#  Licensed under the MPL-2.0 license.

add_executable(.-casyt
    main.cpp)

target_link_libraries(.-casyt PUBLIC
    casyt.driver
    Threads::Threads)

target_include_directories(.-casyt PUBLIC
    ${CASYT_INCLUDE_DIR})
