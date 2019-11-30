macro(beyond_module NAME SOURCES)
    message("${NAME} @ ${SOURCES}")
    add_library(
            ${NAME}
            STATIC
            "${SOURCES}"
    )
    set_target_properties(
            ${NAME}
            PROPERTIES
            LINKER_LANGUAGE CXX
    )
    target_include_directories(
            ${NAME}
            PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>
    )
    message("Include at ${CMAKE_CURRENT_SOURCE_DIR}/include")
endmacro()