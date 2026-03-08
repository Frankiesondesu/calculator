# CMake Toolchain File for AArch64 Dictpen Linux
# 用于词典笔的 AArch64 交叉编译工具链文件

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

# 设置工具链路径
set(TOOLCHAIN_ROOT "${CMAKE_CURRENT_LIST_DIR}/aarch64-dictpen-linux-gnu-gcc-toolchain")

# 交叉编译器
set(CMAKE_C_COMPILER "${TOOLCHAIN_ROOT}/aarch64-dictpen-linux-gnu/bin/aarch64-dictpen-linux-gnu-gcc")
set(CMAKE_CXX_COMPILER "${TOOLCHAIN_ROOT}/aarch64-dictpen-linux-gnu/bin/aarch64-dictpen-linux-gnu-g++")

# Sysroot 设置
set(CMAKE_SYSROOT "${TOOLCHAIN_ROOT}/aarch64-dictpen-linux-gnu/sysroot")

# 查找目标环境的库和头文件
set(CMAKE_FIND_ROOT_PATH "${CMAKE_SYSROOT}")

# 只在目标环境中查找库和头文件
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# Qt5 相关设置
set(Qt5Core_EXECUTABLE_COMPILE_FLAGS "")
set(Qt5Gui_EXECUTABLE_COMPILE_FLAGS "")
set(Qt5Widgets_EXECUTABLE_COMPILE_FLAGS "")

# 链接器标志
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath,\\$ORIGIN/../lib")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-rpath,\\$ORIGIN/../lib")

# 编译标志优化（针对嵌入式设备）
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -pipe")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -pipe")

# 禁用某些特性以减小二进制大小
option(DISABLE_TESTS "Disable building tests" ON)
