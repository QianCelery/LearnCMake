# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.10)

# 项目信息
project(Demo6)

set(Demo_VERSION_MAJOR 1)
set(Demo_VERSION_MINOR 0)

message(STATUS "${CMAKE_ROOT}")
# 检查系统是否支持pow函数
include(CheckLibraryExists)
set(CMAKE_EXTRA_INCLUDE_FILES math.h)
CHECK_LIBRARY_EXISTS(m pow "math.h" HAVE_POW)


include_directories("${PROJECT_BINARY_DIR}")

# 加入一个配置文件，用于处理CMake对源码的设置
configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in" # 工程的根目录
    "${PROJECT_BINARY_DIR}/config.h"    # 运行 cmake 命令的目录,通常是 ${PROJECT_SOURCE_DIR}/build
)

# # 是否使用自己的MathFunction库
# option (USE_MYMATH "Use provided math implementation" ON)

# 是否加入MathFunctions库
if(NOT HAVE_POW)
    include_directories("${PROJECT_SOURCE_DIR}/math")
    add_subdirectory(math)
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctinos)
endif (NOT HAVE_POW)

# 查找当前目录下的所有源文件
# 并将名称保存到DIR_SRCS变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(Demo ${DIR_SRCS})

# 添加链接库
target_link_libraries(Demo ${EXTRA_LIBS})

# 指定安装路径
install(TARGETS Demo DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/config.h" DESTINATION include)

# 启用测试
enable_testing()

# 测试程序是否成功运行
add_test(test_run Demo 5 2)

# 测试帮助信息是否可以正常提示
add_test(test_usage Demo)
set_tests_properties(test_usage PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")   

# # 测试5的平方
# add_test(test_5_2 Demo 5 2)
# set_tests_properties(test_5_2 PROPERTIES PASS_REGULAR_EXPRESSION "is 25")

# # 测试10的平方
# add_test(test_10_2 Demo 10 2)
# set_tests_properties(test_10_2 PROPERTIES PASS_REGULAR_EXPRESSION "is 100")
# 定义一个宏，用来简化测试工作
macro(do_test arg1 arg2 result)
    add_test(test_${arg1}_${arg2} Demo ${arg1} ${arg2})    
    set_tests_properties(test_${arg1}_${arg2} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro(do_test arg1 arg2 result)

# 使用该宏进行一系列的数据测试
do_test(5 2 "is 25")
do_test(10 2 "is 100")
do_test(11 2 "is 121")

# 支持gdb
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall  -g -ggdb")
set(CMAKE_CXXFLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall ")


# 构建一个CPack安装包
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_SOURCE_DIR}/License.txt)
set(CPACK_PACKAGE_VERSION_MAJOR ${Demo_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${Demo_VERSION_MINOR})
include(CPack)

