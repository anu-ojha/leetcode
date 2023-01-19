
import collections


class Solution(object):
    def subarraysDivByK(self, A, K):
        
        count = collections.defaultdict(int)
        count[0] = 1
        result, prefix = 0, 0
        for a in A:
            prefix = (prefix+a) % K
            result += count[prefix]
            count[prefix] += 1
        return result