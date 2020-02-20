cmake_minimum_required(VERSION 3.0)

project(stduy_note)

# 当前目录下所有文件
file(GLOB CPP_SRC_LIST ${CMAKE_CURRENT_LIST_DIR}/*/*.cpp)
# 设置id
set(ID 0)
foreach(FILE_PATH ${CPP_SRC_LIST})

    # 当前文件路径
    message(STATUS  "FILE_PATH               :   ${FILE_PATH}  ")
    string(REGEX MATCH "/.*cpp" relative_path ${FILE_PATH})

    message(STATUS  "relative_path   :   ${relative_path}  ")

    STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" FILE_NAME_NO_SUFFIX ${FILE_PATH})
    message(STATUS  "FILE_NAME_NO_SUFFIX               :   ${FILE_NAME_NO_SUFFIX}  ")



    message(STATUS  "CMAKE_CURRENT_SOURCE_DIR               :   ${CMAKE_CURRENT_SOURCE_DIR}  ")


    STRING( REGEX REPLACE ".*/(.*)/.*.cpp" "\\1" UPPER_FOLDER ${FILE_PATH} )
    message(STATUS  "UPPER_FOLDER               :   ${UPPER_FOLDER}  ")

    STRING( REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR} )
    message(STATUS  "CURRENT_FOLDER               :   ${CURRENT_FOLDER}  ")




    math(EXPR ID "${ID} + 1")

    set(EVERY_EXECUTABLE_NAME   ${ID}_${UPPER_FOLDER}_${FILE_NAME_NO_SUFFIX}.temp)
    message(STATUS  "EVERY_EXECUTABLE_NAME               :   ${EVERY_EXECUTABLE_NAME} ")

    set(EVERY_EXECUTABLE_FILE   "./${UPPER_FOLDER}/${FILE_NAME_NO_SUFFIX}.cpp")
    message(STATUS  "EVERY_EXECUTABLE_FILE               :   ${EVERY_EXECUTABLE_FILE} ")

    add_executable(${EVERY_EXECUTABLE_NAME} ${EVERY_EXECUTABLE_FILE} )
endforeach()
