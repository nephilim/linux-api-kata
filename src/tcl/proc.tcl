proc run_code_with_wrapper { code } {
    puts "----------------"
    puts [$code];       # 실패 원인은 무엇일까
    puts "----------------"
}

run_code_with_wrapper {set msg "run this"}

