#使用するコンパイラ
CC = g++

#コンパイルオプション
CFLAGS = -llept -ltesseract

#実行ファイル名
TARGET = ocr

#コンパイル対象のソースコード
SRCS = main.cpp

#オブジェクトファイル名
OBJS = $(SRCS)

#インクルードファイルのあるディレクトリパス
INCDIR = 

#ターゲットファイル生成
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

# .oファイル、実行ファイル、.dファイルを削除
clean:
	-rm -f $(TARGET) *.d

# "make all"で make cleanとmakeを同時に実施。
all:
	$(clean) $(CC) -o $(TARGET) $(OBJS) $(CFLAGS)