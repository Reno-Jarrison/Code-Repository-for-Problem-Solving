def is_leap(x):
    return x % 4 == 0 and (x % 100 != 0 or x % 400 == 0)
    
year = int(input())
print(is_leap(year))
