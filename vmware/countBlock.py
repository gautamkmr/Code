'''
mxn matrix of occupied and fee cells (1 and 0s). 

1) Find the number of contiguous blocks of occupied cells.

A contiguous block of occupied cells is any 1 that is connected to another 1 in the horizontal or vertical direction.


Example 1:

Input:
11110
11010
11000
00000

Output: 1, 9


Example 2:

Input:
11000
11000
00100
00011

Output: 3, 4

'''

def dfs(arr, i, j, r, c):
    if i < 0 or j < 0 or i >= r or j >= c or arr[i][j]==0:
        return 0
    arr[i][j] = 0 #turnning off the bit 
    count = 1
    count += dfs(arr, i + 1, j, r, c)
    count += dfs(arr, i - 1, j, r, c)
    count += dfs(arr, i, j + 1, r, c)
    count += dfs(arr, i, j - 1, r, c)
    return count 

def countBlock(arr):
    if arr is None:
        return 0
    r = len(arr)
    if r == 0:
        return 0
    c = len(arr[0])
    ans =  0 
    for i in range(r):
        for j in range(c):
            if arr[i][j] == 1:
                tmp = dfs(arr, i, j, r, c)
                ans = max(tmp, ans)
    return ans
                
    
def main():
    arr = [[1, 1, 1, 1, 0], [1, 1, 0, 1, 0], [1, 1, 0, 0, 0], [0, 0, 0, 0, 0]]
    print(countBlock(arr))
    arr = [[1, 1, 0, 0, 0], [1, 1, 0, 0, 0], [0, 0, 1, 0, 0], [0, 0, 0, 1, 1]]
    print(countBlock(arr))    
main()
