
# --generate-line-info
# --source-in-ptx

verbose=""

# Compile Objects with device relocatable code, like a normal C++ objet but
# contains fatbins containing cuda ptx
nvcc -x cu --relocatable-device-code true --debug --device-debug -std=c++20 --debug --device-debug -gencode=arch=compute_87,code=sm_87 ${verbose}  --relocatable-device-code=true --compiler-options -fPIC source/build_control/tachyon_lib_unity_core.cpp --output-file tachyon_lib_unity_core.o --compile &
tachyon_lib_job=$!

nvcc -x cu --debug --device-debug -std=c++20 --debug --device-debug -gencode=arch=compute_87,code=sm_87 ${verbose}  --relocatable-device-code=true --compiler-options -fPIC source/tests/tachyon_lib_tests_cuda_dll.cu --compile --output-file cuda_dll.o &
entry_point_job=$!

# Device Link Step, does not touch host code
wait -p $tachyon_lib_job $entry_point_job
nvcc --debug --device-debug -std=c++20 --debug --device-debug -gencode=arch=compute_87,code=sm_87 ${verbose} -luuid tachyon_lib_unity_core.o cuda_dll.o --device-link --output-file cuda_dll_linked_device_code.o

nvcc cuda_dll_linked_device_code.o cuda_dll.o tachyon_lib_unity_core.o -luuid -arch=sm_87 -o final.exec
