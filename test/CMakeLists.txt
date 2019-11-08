file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cc)
add_executable(
    unit_tests
    ${TEST_SRC_FILES}
    )

target_link_libraries(
    unit_tests
    gtest_main
    knowledge_base
    )

add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
  )
