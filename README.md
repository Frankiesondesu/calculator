# 词典笔计算器 (Dictpen Calculator)

一个专为词典笔设备设计的 Qt5 计算器应用程序，支持 AArch64 架构。

## 项目特性

- 📱 针对触摸屏优化的大按钮设计
- ➕➖✖️➗ 支持加减乘除四则运算
- 🎨 简洁直观的界面
- 🔧 使用词典笔专用 Qt5 工具链编译

## 依赖的仓库

本项目依赖以下三个词典笔专用仓库：

1. [Qt5 for AArch64 Dictpen](https://github.com/Lyrecoul/qt-5.15.2-for-aarch64-dictpen-linux.git) - 词典笔专用 Qt5.15.2
2. [AArch64 GCC Toolchain](https://github.com/Lyrecoul/aarch64-dictpen-linux-gnu-gcc-toolchain.git) - 交叉编译工具链
3. [Dictpen Libs](https://github.com/Lyrecoul/dictpen-libs.git) - 词典笔系统库

## 本地编译（x64 Linux 测试）

```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
./bin/calculator
```

## 交叉编译（用于词典笔）

### 方法一：使用 CMake 工具链文件

```bash
# 克隆依赖仓库
git clone https://github.com/Lyrecoul/qt-5.15.2-for-aarch64-dictpen-linux.git
git clone https://github.com/Lyrecoul/aarch64-dictpen-linux-gnu-gcc-toolchain.git
git clone https://github.com/Lyrecoul/dictpen-libs.git

# 创建构建目录并配置
mkdir build-dictpen && cd build-dictpen
cmake .. \
  -DCMAKE_TOOLCHAIN_FILE=../aarch64-dictpen-linux-gnu-gcc-toolchain.cmake \
  -DCMAKE_PREFIX_PATH=../dictpen-libs \
  -DQt5Core_DIR=../dictpen-libs/lib/cmake/Qt5Core \
  -DQt5Gui_DIR=../dictpen-libs/lib/cmake/Qt5Gui \
  -DQt5Widgets_DIR=../dictpen-libs/lib/cmake/Qt5Widgets

# 编译
make -j$(nproc)
```

### 方法二：使用环境变量

```bash
export DICTPEN_TOOLCHAIN=1
export DICTPEN_SYSROOT=/path/to/aarch64-dictpen-linux-gnu-gcc-toolchain/aarch64-dictpen-linux-gnu/sysroot
export DICTPEN_CC=/path/to/aarch64-dictpen-linux-gnu-gcc-toolchain/aarch64-dictpen-linux-gnu/bin/aarch64-dictpen-linux-gnu-gcc
export DICTPEN_CXX=/path/to/aarch64-dictpen-linux-gnu-gcc-toolchain/aarch64-dictpen-linux-gnu/bin/aarch64-dictpen-linux-gnu-g++

mkdir build-dictpen && cd build-dictpen
cmake .. -DCMAKE_PREFIX_PATH=/path/to/dictpen-libs
make -j$(nproc)
```

## GitHub Actions 自动编译

本项目配置了 GitHub Actions，每次 push 或 PR 时会自动：

1. **build-native**: 编译 x64 Linux 版本（用于测试）
2. **build-dictpen**: 交叉编译 AArch64 词典笔版本

编译产物会作为 artifact 上传，可在 Actions 页面下载。

## 部署到词典笔

1. 从 GitHub Actions 下载 `calculator-dictpen-aarch64` artifact
2. 将 `calculator` 可执行文件和所需的 `.so` 库复制到词典笔
3. 在词典笔上运行：
   ```bash
   export LD_LIBRARY_PATH=/path/to/libs:$LD_LIBRARY_PATH
   ./calculator
   ```

## 项目结构

```
.
├── src/
│   └── main.cpp              # 主程序源码
├── CMakeLists.txt            # CMake 构建配置
├── aarch64-dictpen-linux-gnu-gcc-toolchain.cmake  # 交叉编译工具链
├── .github/workflows/
│   └── build.yml             # GitHub Actions 配置
├── qt-5.15.2-for-aarch64-dictpen-linux/  # Qt5 库（需克隆）
├── aarch64-dictpen-linux-gnu-gcc-toolchain/  # GCC 工具链（需克隆）
└── dictpen-libs/             # 系统库（需克隆）
```

## 许可证

MIT License
