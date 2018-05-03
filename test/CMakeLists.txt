add_executable(ac_compile_test ac_compile_test.cpp)
add_executable(ac_test_entry ac_tests.cpp)

add_test(ac_compile_time_test ac_compile_test)
add_test(ac_test ac_test_entry)
