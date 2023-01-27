
from typing import List
from collections import defaultdict


class Solution:
    def __init__(self):
        TrieNode = lambda: defaultdict(TrieNode)  # not defaultdict(lambda: TrieNode)
        self.root = TrieNode()  # root of tire

    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        """
        Trie + DFS
        """
        words.sort(key=len)
        ret = []
        for w in words:
            if self.can_concat(w, 0):
                ret.append(w)

            cur = self.root
            for c in w:
                cur = cur[c]
            cur["end"] = True

        return ret

    def can_concat(self, word, lo):
        if not word:
            return False

        k = len(word)
        if lo >= k:
            return True

        cur = self.root
        for i in range(lo, k):
            cur = cur[word[i]]
            if cur.get("end", False) and self.can_concat(word, i + 1):
                return True

        return False


