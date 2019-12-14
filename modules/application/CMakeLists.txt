
set(
        BEYOND_APP_ALL
        include/beyond/application.h
        include/beyond/extension.h
        include/beyond/event.h
        src/beyond/application.cpp
        src/beyond/utilities/layout.cpp
)
beyond_module(
        application
        "${BEYOND_APP_ALL}"
)
