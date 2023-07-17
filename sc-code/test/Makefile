LIB_DIR=-L$(SYSTEMC_HOME)/lib-linux64
INC_DIR=-I$(SYSTEMC_HOME)/include
LIB=-lsystemc -Wl,-rpath,$(SYSTEMC_HOME)/lib-linux64

# 检查默认 g++ 版本是否大于等于 11
GCC_VERSION := $(shell g++ -dumpversion)
GE_GCC_11 := $(shell expr $(GCC_VERSION) \>= 11)
# 设置 g++ 路径
ifeq ($(GE_GCC_11), 1)
    # 默认 g++ 版本大于等于 11，直接使用 g++
    GCC := g++
else
    # 默认 g++ 版本小于 11，使用指定路径下的 g++
    GCC_PATH := $(GCC11_PATH)
    GCC := $(GCC_PATH)/bin/g++ -L$(GCC_PATH)/lib64 -I$(GCC_PATH)/include -Wl,-rpath,$(GCC_PATH)/lib64
endif

App=main

.PHONY:all new

all:
	$(GCC) -o $(App) main.cpp -std=c++20

new:
	g++ -o $(App) new.cpp $(LIB_DIR) $(INC_DIR) $(LIB) -std=c++20


clean:                                                                                                           
	RM -RF $(App)
