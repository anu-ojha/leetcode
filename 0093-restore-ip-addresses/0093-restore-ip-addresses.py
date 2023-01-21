
class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        ans = []
        self._restoreIpAddresses(0, s, [], ans)
        return ans

    def _restoreIpAddresses(self, l, s, cur, ans):
        if len(s) == 0:
            if l == 4:
                ans.append(".".join(cur))
            return
        if l == 4:
            return
        self._restoreIpAddresses(l + 1, s[1:], cur + [s[:1]], ans)
        if s[0] != "0":
            if len(s) >= 2:
                self._restoreIpAddresses(l + 1, s[2:], cur + [s[:2]], ans)
            if len(s) >= 3 and int(s[:3]) <= 255:
                self._restoreIpAddresses(l + 1, s[3:], cur + [s[:3]], ans)
