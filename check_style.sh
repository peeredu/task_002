#!/bin/bash

# Копирование файла .clang-format в текущую директорию
cp clang/.clang-format .

# Проверка стиля для файлов с расширением .c
if [ -n "$(clang-format -output-replacements-xml -n -style=file *.c)" ]; then
    echo "Code style issues found in .c files. Please run clang-format to fix them."
    exit 1
fi

# Проверка стиля для файлов с расширением .h
if [ -n "$(clang-format -output-replacements-xml -n -style=file *.h)" ]; then
    echo "Code style issues found in .h files. Please run clang-format to fix them."
    exit 1
fi

echo "Code style check passed."