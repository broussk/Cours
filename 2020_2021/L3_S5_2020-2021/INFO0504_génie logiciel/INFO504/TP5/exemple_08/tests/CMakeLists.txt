#add_executable(test_01 ${PROJECT_SOURCE_DIR}/${TEST}/test_01.cxx)
add_executable(test_01 Test_01.cxx)
target_link_libraries (test_01  MyStrlen)

# For making test
enable_testing()

# Add the real test with a name and the corresponding command (<=> exec)
add_test(NAME test_01_size_14 COMMAND test_01)  
