class Solution(object):
    def minimumPushes(self, word):
        """
        :type word: str
        :rtype: int
        """
        n = len(word)
        result = 0
        for i in range(1,n+1):
            if i<=8 :
                result+=1
            elif i>8 and i<=16:
                result+=2
            elif i>16 and i<=24:
                result+=3
            elif i>24 and i<=n:
                result+=4
        return result 