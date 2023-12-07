class Solution:
    dp:list
    def solve(self,s:int, e:int,a:list,x:int, dp):

        if(s >= e): 
            return 0

        if(self.dp[s][e] != -1): 
            return dp[s][e]

        ans = min([min(x,a[s+1]-a[s]+self.solve(s+2,e,a,x,self.dp)),min(x,a[e]-a[s]+self.solve(s+1,e-1,a,x,self.dp)),min(x,a[e]-a[e-1]+self.solve(s,e-2,a,x,self.dp))])

        self.dp[s][e] = ans
        return ans

    def minOperations(self, s1: str, s2: str, x: int) -> int:
        
        n = len(s1)
        a = []
        
        for i in range(0,n):
            if(s1[i] != s2[i]):
                a.append(i)
        
        n = len(a)
        if n%2 != 0:
            return -1
        
        if n == 0:
            return 0
        
        self.dp = [[None] * n for _ in range(n)]
        
        for i in range(0,n):
            for j in range(0,n):
                self.dp[i][j] = -1
        
        return self.solve(0,n-1,a,x,self.dp)

sol = Solution()
a = input()
b = input()
x = int(input())
print(sol.minOperations(a,b,x))