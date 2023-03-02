class Solution:
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        result, cnt = 0, 1
        j = 0
        for i in range(1, len(chars)+1): 
            if i < len(chars) and chars[i] == chars[i-1]:
                cnt += 1
            else:
                # 1) update letter
                chars[j] = chars[i-1]
                j += 1
                # 2) update cnt
                if cnt == 1:
                    continue
                for ch in str(cnt):
                    chars[j] = ch
                    j += 1
                # 3) reset cnt
                cnt = 1
        return j