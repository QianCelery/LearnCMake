# 查找当前目录下的所有源文件
# 并将名称保存到DIR_LIB_SRCS
aux_source_directory(. DIR_LIB_SRCS)

# 生成链接库
add_library(MathFunctinos SHARED ${DIR_LIB_SRCS})