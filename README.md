# Qt Calculator for Dictionary Pen

一个基于Qt的计算器程序，专为词典笔设备设计。

## 功能特点

- 基本四则运算（加、减、乘、除）
- 简洁直观的界面设计
- 适合触摸屏操作的大按钮
- 轻量级，适合嵌入式设备

## 项目结构

参考了以下两个项目的设计模式：
- [QtVideoPlayer](https://github.com/Lyrecoul/QtVideoPlayer) - Qt视频播放器项目
- [QtFileManager](https://github.com/Lyrecoul/QtFileManager) - Qt文件管理器项目

```
calculator/
├── .github/workflows/
│   └── build.yml       # GitHub Actions 自动编译配置
├── src/
│   └── main.cpp        # 主程序源代码
├── CMakeLists.txt      # CMake 构建配置
└── README.md           # 项目说明文档
```

## 编译要求

- Qt 5.x
- CMake 3.16+
- C++17 兼容编译器

## 本地编译

```bash
# 创建构建目录
mkdir build
cd build

# 配置项目
cmake ..

# 编译
make -j$(nproc)

# 运行
./bin/calculator
```

## GitHub Actions 自动编译

本项目配置了GitHub Actions，每次推送到main/master分支或创建Pull Request时会自动编译。

编译产物会作为artifact上传，保留7天。

## 许可证

MIT License