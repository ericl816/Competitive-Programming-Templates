import sys
raw_input = sys.stdin.readline

###################### FAST IO ######################################

OUT = []

def write(item, sep=" "):
    if type(item) is int:
        OUT.append(str(item))
    elif type(item) is list:
        if type(item[0]) is int:
            OUT.append(sep.join(map(str, item)))
        else:
            OUT.append(sep.join(item))
    else:
        OUT.append(item)

def PRINT(sep = "\n"):
    print(sep.join(OUT))

gi = lambda: list(map(int, input().split()))

###################### End of FAST IO ######################################

# Using solution to: A Greedy Problem as code for template

MOD = 1000000007
MAXN = 2010
read = lambda: list(map(int, raw_input().split()))

N, T, Q = read()
DP = [0 for _ in range(MAXN)]
DP[0] = 1
t = read()
for i in range(0, N):
  for j in range(MAXN - 1, t[i] - 1, -1):
    DP[j] += DP[j - t[i]]
    DP[j] %= MOD
for i in range(Q):
  a, b, q = map(int, raw_input().split())
  ans = 0
  for j in range(t[a - 1], MAXN):
    DP[j] -= DP[j - t[a - 1]]
    DP[j] %= MOD
  for j in range(t[b - 1], MAXN):
    DP[j] -= DP[j - t[b - 1]]
    DP[j] %= MOD
  for j in range(0, q - t[a - 1] - t[b - 1] + 1):
    ans += DP[j]
    ans %= MOD
  for j in range(MAXN - 1, t[a - 1] - 1, -1):
    DP[j] += DP[j - t[a - 1]]
    DP[j] %= MOD
  for j in range(MAXN - 1, t[b - 1] - 1, -1):
    DP[j] += DP[j - t[b - 1]]
    DP[j] %= MOD
  write(ans)
PRINT()