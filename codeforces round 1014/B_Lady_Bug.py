def solve():
    n = int(input())
    a = input()
    b = input()
    
    ones1, ones2 = 0, 0
    for i in range(n):
        if i % 2 == 0:
            if a[i] == '1':
                ones1 += 1
            if b[i] == '1':
                ones2 += 1
        else:
            if a[i] == '1':
                ones2 += 1
            if b[i] == '1':
                ones1 += 1
    
    c1 = n // 2
    c2 = (n + 1) // 2
    
    if ones1 <= c1 and ones2 <= c2:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()