
def isFibonacciNumber(n):
    a = 0
    b = 1
    while (b < n):
        temp = b
        b += a
        a = temp

    if (b == n) or (b == 0):
        return True
    else:
        return False