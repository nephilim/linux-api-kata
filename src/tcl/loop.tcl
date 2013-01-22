# 10 to 1 loop. print odd numbers

set size 10
while { $size > 0 } {
    puts "\$size is $size "
    if { $size % 2 == 0 } {
        puts "and it is even"
    }
    if [set condition "$size > 5"] {
        puts "size is over 5"
    }
    incr size -1 
} 
