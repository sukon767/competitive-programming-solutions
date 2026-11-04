import sys
sys.set_int_max_str_digits(0)
 
line = input()
a, b = line.strip().split(" ")
 
b_dig = len(b)
a_dig = len(a)
 
b = int(b)
 
for i in range(max(1, (a_dig + b_dig) // 2 - 10), min(a_dig, (a_dig + b_dig) // 2 + 10)):
    if a[i] == '0':
        continue
    x = int(a[:i])
    y = int(a[i:])
    if x % y == 0 and x // y == b:
        print(f"{x} {y}")
        exit(0)
 
assert(False)