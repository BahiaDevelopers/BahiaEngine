
set(
        BEYOND_APP_ALL
        include/beyond/application.h
        include/beyond/extension.h
        src/beyond/application.cpp
)
beyond_module(
        application
        "${BEYOND_APP_ALL}"
)
