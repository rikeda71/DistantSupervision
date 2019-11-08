add_library(knowledge_base "")

target_sources(
    knowledge_base
    PRIVATE
        knowledge_base.cc
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/knowledge_base.hh
    )

target_include_directories(
    knowledge_base
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
