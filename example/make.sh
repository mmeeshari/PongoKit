cd "$(dirname $0)"
xcrun -sdk iphoneos gcc main.c -o test_module -arch arm64 -Xlinker -kext -nostdlib -Xlinker -fatal_warnings -I../include -D_SECURE__STRING_H_ -O3
