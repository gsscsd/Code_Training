import sys


# money = int(sys.stdin.readline().strip())
# price = list(map(int,sys.stdin.readline().strip().split(" ")))
# hot = list(map(int,sys.stdin.readline().strip().split(" ")))

money = 10
price = [2, 2, 6, 5, 4]
hot = [6, 3, 5, 4, 6]


#　定义的dp[i][j]代表什么
def solve(price,hot,money):
    n = len(price)
    # 生成二维的数组
    dp = [[0 for i in range(money+1)] for j in range(n + 1)]
    for i in range(1,n+1):
        for j in range(1,money + 1):
            if j < price[i - 1]:
                dp[i][j] = dp[i - 1][j]
            else:
                # 不理解这里为啥是price i-1 和 hot i-1呢？
                # 原因在于price和hot都是从下标0开始的
                dp[i][j] = max(dp[i - 1][j - price[i - 1]] + hot[i - 1],dp[i - 1][j])
    for i in range(n+1):
        for j in range(money + 1):
            print(str(dp[i][j]),end = '\t')
        print()
    return dp[-1][-1]

result = solve(price,hot,money)
print(result)
