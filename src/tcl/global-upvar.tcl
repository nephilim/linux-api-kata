set first "James"
set last "Bond"

# 인자 출력 예제. tcl에서 인자는 
# 외부 변수명을 나타내는 문자열 일 수도 있다.
# (tcl은 string을 기반으로 하는 언어이므로)

proc simple_command { arg1 arg2 } {

    puts "$arg1 $arg2";         # arg1의 값은 first
}

simple_command first last

# 절대값을 계산하는 함수 내에서 
# 인자로 전달한 외부 변수를 upvar로 참조하여 변경

proc absolute { var value } {
    upvar $var myvar
    if {$value < 0} {
        set myvar [expr {-$value}]
    } else { 
        set myvar $value
    }
    return $myvar
}

puts "abs(\$x) = [absolute x 5] abs(\$y) = [absolute y 5]"

# 1단계/2단계 위(callee) 스코프를 참조하여 
# 다른 스코프의 변수를 변경하는 예제

proc second {arg1} {
    upvar 1 $arg1 outer_outer
    upvar 2 original grandparent
    puts "grandchild-func(): outerouter: $outer_outer GRANDP: $grandparent"
    set outer_outer 1
    set grandparent 2
}

proc first {arg1} {
    upvar $arg1 outer
    puts "child-func(): outer: $arg1"
    second arg1
}

set original 100
first original
puts "original: $original"

