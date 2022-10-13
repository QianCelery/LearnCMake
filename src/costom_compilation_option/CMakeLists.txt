# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.10)

# 项目信息
project(Demo4)

# 加入一个配置文件，用于处理CMake对源码的设置
configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in" # 工程的根目录
    "${PROJECT_SOURCE_DIR}/config.h"    # 运行 cmake 命令的目录,通常是 ${PROJECT_SOURCE_DIR}/build
)

# 是否使用自己的MathFunction库
option (USE_MYMATH "Use provided math implementation" ON)

# 是否加入MathFunctions库
if(USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/math")
    add_subdirectory(math)
    message(STATUS "${MathFunctinos}")
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctinos)
endif (USE_MYMATH)

# 查找当前目录下的所有源文件
# 并将名称保存到DIR_SRCS变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(Demo ${DIR_SRCS})

# 添加链接库
target_link_libraries(Demo ${EXTRA_LIBS})