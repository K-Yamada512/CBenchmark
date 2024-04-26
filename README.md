<!--

This document is written in Markdown.
You can preview on such as VisualStudio Code.
If you want to know more, search with "vscode markdown" or refer to official document https://code.visualstudio.com/Docs/languages/markdown .

-->

# C言語　ベンチマークテスト用コード　2024

使用言語はC言語  
動作環境  
OS:Ubuntu 22.04.4 LTS  
コンパイラ:gcc version 11.4.0 (Ubuntu 11.4.0-1ubuntu1~22.04)  
make:GNU Make 4.3  

## 環境

### gcc

#### バージョン確認
```
gcc -v
```
#### インストール
```
sudo apt install gcc
```

### make
#### バージョン確認
```
make -v
```
#### インストール
```
sudo apt install make
```
### BLAS
#### インストール
- Reference BLAS
```
sudo apt install libblas-dev
```
- BLIS
```
sudo apt install libblis-dev
```
- OpenBLAS
```
sudo apt install libopenblas-base
sudo apt install libopenblas-dev
```
- Intel Math Kernel Library (MKL)
```
sudo apt install intel-mkl
```
※デフォルト設定はoffする

#### ライブラリの切り替え
```
sudo update-alternatives --config libblas.so-x86_64-linux-gnu
```
```
sudo update-alternatives --config libblas.so.3-x86_64-linux-gnu
```

### LAPACK
#### インストール
```
sudo apt install liblapack-dev
```
#### ライブラリの切り替え
```
sudo update-alternatives --config liblapack.so-x86_64-linux-gnu
```
```
sudo update-alternatives --config liblapack.so.3-x86_64-linux-gnu
```

## Makefile
### コンパイル

```
make
```

### 実行

```
make execute
```

### ファイル削除

```
make clean
```

### ヘルプ

```
make help
```

## 目次

1. [フィボナッチ数列](./1_Fibonacci_number/README.md)
2. [OpenMP](./2_OpenMP/README.md)
3. [BLAS](./3_BLAS_dgemm/README.md)


<!-- Written by Croyfet in 2022-->
