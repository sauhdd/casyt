#   /lib/casyt/parse/CMakeLists.txt
#
#  Created at 2023-02-06 by @sauhd.
#  Licensed under the MPL-2.0 license.

add_library(casyt.parse STATIC
    parser.cpp)

target_include_directories(casyt.parse PUBLIC
    ${CASYT_INCLUDE_DIR})

# add_executable(casyt.parse-driver
#     parser.driver.cpp)
#
# target_include_directories(casyt.parse-driver PUBLIC
#     ${CASYT_INCLUDE_DIR})
#
# target_link_libraries(casyt.parse-driver PUBLIC
#     casyt.parse)
