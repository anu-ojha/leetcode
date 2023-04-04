class Solution(object):
    def subtractProductAndSum(self, n):
        
        p = 1
        s = 0
        while(n != 0):
            d = n%10
            p = p*d
            s = s+d
            
            n = n/10
        ans = p - s
        return ans