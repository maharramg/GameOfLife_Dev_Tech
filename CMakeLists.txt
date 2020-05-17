cmake_minimum_required(VERSION 3.10.2)

project(Game_Of_Life_Local_v3.0_Circular LANGUAGES C)

add_subdirectory(game)
add_subdirectory(console)
add_subdirectory(sdl)

add_executable(${PROJECT_NAME} main.c)

find_package(Doxygen)
if(DOXYGEN_FOUND)

  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/dconfig ${CMAKE_CURRENT_BINARY_DIR}/dconfig @ONLY)

  add_custom_target(doc
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/dconfig
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND google-chrome ${CMAKE_CURRENT_SOURCE_DIR}/docs/html/index.html
  )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif(DOXYGEN_FOUND)

add_custom_target(doc_pdf
    COMMAND make
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs/latex
    COMMAND xdg-open ${CMAKE_CURRENT_SOURCE_DIR}/docs/latex/refman.pdf
  )

add_custom_target(dist
    COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_NAME}
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_NAME}
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${PROJECT_NAME}/${PROJECT_NAME}
    COMMAND ${CMAKE_COMMAND} -E tar -czvf ${PROJECT_NAME}.tar.gz ${PROJECT_NAME}
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} PUBLIC game console sdl)
