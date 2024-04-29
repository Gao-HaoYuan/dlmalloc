test_dir="/data/local/tmp/ghy"

rm -rf build
mkdir build && cd build

CMAKE_PARA_ANDROID="-DCMAKE_TOOLCHAIN_FILE=${ANDROID_NDK_HOME}/build/cmake/android.toolchain.cmake \
	-DANDROID_NDK=${ANDROID_NDK_HOME} \
    -DANDROID_ABI=arm64-v8a \
    -DANDROID_TOOLCHAIN=clang \
    -DANDROID_PLATFORM=android-28 \
    -DANDROID_ARM_NEON=1\
    -DCMAKE_BUILD_TYPE=Release"
cmake ${CMAKE_PARA_ANDROID} ..
# make -j VERBOSE=1
make -j8
cd ..

adb root
adb remount
# 最大频
adb shell "echo performance > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor"
adb shell "echo performance > /sys/devices/system/cpu/cpu1/cpufreq/scaling_governor"
adb shell "echo performance > /sys/devices/system/cpu/cpu2/cpufreq/scaling_governor"
adb shell "echo performance > /sys/devices/system/cpu/cpu3/cpufreq/scaling_governor"
adb shell "echo performance > /sys/devices/system/cpu/cpu4/cpufreq/scaling_governor"
adb shell "echo performance > /sys/devices/system/cpu/cpu5/cpufreq/scaling_governor"
adb shell "echo performance > /sys/devices/system/cpu/cpu6/cpufreq/scaling_governor"
adb shell "echo performance > /sys/devices/system/cpu/cpu7/cpufreq/scaling_governor"

adb shell rm -rf ${test_dir}
adb shell mkdir -p ${test_dir}
adb push ./build/main ${test_dir}

echo "---------------------------------------------------------------"
adb exec-out "cd ${test_dir}; \
              ./main;"
