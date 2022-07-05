cmake_minimum_required(VERSION 3.21)

add_executable("module_27_task_3"
        main.cpp
        human.cpp
        main_worker.cpp
        middle_manager.cpp
        head_of_the_company.cpp)

target_include_directories("module_27_task_3" PUBLIC ${MY_INCLUDE_DIR})
