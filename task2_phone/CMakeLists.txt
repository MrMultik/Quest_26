add_executable(Phone26
    main.cpp
    phone.cpp
    contact.cpp
)

target_include_directories(Phone26 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})