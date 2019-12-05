set(
        ENTITIES_ALL
        include/beyond/entities/entity.h
        include/beyond/entities/transformations.h
        src/beyond/entities/transformations.cpp
)
beyond_module(
        entities
        "${ENTITIES_ALL}"

)
find_package(glm REQUIRED)
target_link_libraries(
        entities
        application
        glm
)