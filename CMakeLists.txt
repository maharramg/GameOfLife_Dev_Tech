cmake_minimum_required(VERSION 3.10.2)
cmake_policy(SET CMP0076 NEW)

project(Game_of_Life_v3.0 LANGUAGES C)

add_subdirectory(game)
add_subdirectory(console)
add_subdirectory(sdl)

add_executable(${PROJECT_NAME} main.c)

# Documentation
find_package(Doxygen)
if(DOXYGEN_FOUND)

  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/dconfig ${CMAKE_CURRENT_BINARY_DIR}/dconfig @ONLY)

  add_custom_target(doc
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/dconfig
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND xdg-open ${CMAKE_CURRENT_SOURCE_DIR}/docs/html/index.html
  )
else (DOXYGEN_FOUND)
  message("Doxygen needs to be installed to generate the doxygen documentation")
endif(DOXYGEN_FOUND)

add_custom_target(doc_pdf
    COMMAND make
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs/latex
    COMMAND xdg-open ${CMAKE_CURRENT_SOURCE_DIR}/docs/latex/refman.pdf
  )

# Dist
add_custom_target(dist
    COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_NAME}
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_NAME}
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${PROJECT_NAME}/${PROJECT_NAME}
    COMMAND ${CMAKE_COMMAND} -E tar -czvf ${PROJECT_NAME}.tar.gz ${PROJECT_NAME}
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} PUBLIC game console sdl)

# CUnit
set(TEST_PROJECT libtest)
add_executable(${TEST_PROJECT})
target_sources(${TEST_PROJECT} PUBLIC cunit_test.c)
target_link_libraries(${TEST_PROJECT} PUBLIC game console sdl cunit)

enable_testing()
add_test(NAME "MyTest" COMMAND ${TEST_PROJECT})

add_custom_target(cover
COMMAND cmake --build . --target test
COMMAND gcovr -r ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} $<TARGET_FILE:${TEST_PROJECT}>
WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

add_custom_target(cover_html
COMMAND cmake --build . --target test
COMMAND gcovr --html --html-detail -o index.html -r ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} $<TARGET_FILE:${TEST_PROJECT}>
COMMAND xdg-open ${CMAKE_SOURCE_DIR}/build/index.html
WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
