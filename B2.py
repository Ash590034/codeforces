def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    from collections import defaultdict
    n = int(data[0])
    m = int(data[1])
    
    mpp = defaultdict(int)
    arr_f = []
    arr_s = []
    
    index = 2
    for i in range(n):
        arr_f.append(int(data[index]))
        index += 1
    
    for i in range(n):
        arr_s.append(int(data[index]))
        index += 1
    
    for i in range(n):
        mpp[arr_f[i]] += arr_s[i]
    
    hash = []
    for k, v in mpp.items():
        hash.append((k, v))
    
    hash.sort()  # Ensure the hash is sorted by the first element, similar to map in C++
    n = len(hash)
    
    ans = 0
    if hash[0][0] > m:
        print(0)
        return
    
    if hash[0][0] * hash[0][1] <= m:
        ans = hash[0][0] * hash[0][1]
    else:
        ans = (m // hash[0][0]) * hash[0][0]
    
    for i in range(1, n):
        if hash[i][0] != hash[i - 1][0] + 1:
            if hash[i][0] * hash[i][1] <= m:
                ans = max(ans, hash[i][0] * hash[i][1])
            else:
                ans = max(ans, (m // hash[i][0]) * hash[i][0])
            continue
        
        sum_val = 0
        if sum_val + hash[i - 1][0] * hash[i - 1][1] <= m:
            sum_val += hash[i - 1][0] * hash[i - 1][1]
        else:
            sum_val += (m // hash[i - 1][0]) * hash[i - 1][0]
            ans = max(ans, sum_val)
            continue
        
        if sum_val + hash[i][0] * hash[i][1] <= m:
            sum_val += hash[i][0] * hash[i][1]
        else:
            diff = m - sum_val
            sum_val += (diff // hash[i][0]) * hash[i][0]
            left = hash[i][1] - (diff // hash[i][0])
            ans = max(ans, sum_val, sum_val + min(left, m - sum_val))
            continue
        
        ans = max(ans, sum_val)
    
    print(ans)

import sys
input = sys.stdin.read

def main():
    t = int(input().strip())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
