beyond_module(
        entities
        "include/beyond/entities/entity.h"
)
find_package(glm REQUIRED)
target_link_libraries(
        entities
        application
        glm
)