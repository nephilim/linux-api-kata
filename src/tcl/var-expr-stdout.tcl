# 변수 할당
set ::creator "nephilim";        # 같은 줄 주석에는 반드시 세미콜론이 필요

puts "{hello, world. ${creator} is the \$creator}"

# {}: 대체 금지
puts {the content in curly braces disables substitution. - ${creator} }

# []: 평가 (like backtick(`) in linux)
puts "[set ::assistant "bamsae"] is \$assistant";   # 대입 결과는 할당한 value

# expr {}
