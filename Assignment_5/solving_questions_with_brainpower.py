class Solution(object):
    def mostPoints(self, questions):
        optim = []
        n = len(questions)
        for i in range(n + 1):
            optim.append(0)
        for i in range(n - 1, -1, -1):
            if(questions[i][1] + i + 1 < n):
                optim[i] = max(questions[i][0] + optim[i + questions[i][1] + 1],optim[i+1])
            else:
                optim[i] = max(questions[i][0],optim[i+1])
        ans = 0
        for i in range(n):
            if(ans < optim[i]):
                ans = optim[i]
        return ans

# questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
# obj1 = Solution()
# print(obj1.mostPoints(questions))