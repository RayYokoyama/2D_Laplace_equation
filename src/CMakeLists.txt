# CMakeのバージョンを設定
cmake_minimum_required(VERSION 2.8)
# プロジェクト名と使用する言語を設定
project(simulation CXX)
# 2d_diffという実行ファイルをmain.cppとhello.cppから作成
add_executable(2d_diff main.cpp output.cpp hedder.hpp)