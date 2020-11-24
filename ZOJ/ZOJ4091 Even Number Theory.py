t = int(input())
for i in range(t):
    x = int(input())
    ans = int(0)
    while x > 0:
        x //= 2
        ans += x
    print(ans)
