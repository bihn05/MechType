# --- 项目设置 ---
TARGET = mtd
CXX = g++
# 开启 C++20 以支持你可能用到的现代特性，-O3 优化确保样条曲线计算效率
CXXFLAGS = -std=c++20 -O3 -Wall -Iinclude
# 链接 OpenGL 相关库：glfw3, GL, X11, lpthread 等
LDFLAGS = -lglfw -lGLEW -lGL -lX11 -lpthread -lXrandr -lXi -ldl

# --- 目录定义 ---
SRC_DIR = src
INC_DIR = include
OBJ_DIR = build
BIN_DIR = build

# --- 文件搜索 ---
# 自动寻找 src 目录下所有的 .cpp 文件
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# 将 .cpp 的路径转换为 build 目录下的 .o 路径
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# --- 编译规则 ---

# 默认目标
all: $(BIN_DIR)/$(TARGET)

# 链接阶段
$(BIN_DIR)/$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)
	@echo "--- 编译完成: $@ ---"

# 编译阶段 (.cpp -> .o)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理
clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/$(TARGET)
	@echo "--- 已清理编译文件 ---"

# 运行
run: all
	./$(BIN_DIR)/$(TARGET)

.PHONY: all clean run