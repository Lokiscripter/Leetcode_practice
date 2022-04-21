class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        words = sentence.split(' ')
        ans = ""
        transfered_sentence = ['a','e','i','o','u']
        for index,word in enumerate(words):
            temp = ""
            if word[0].lower() in transfered_sentence:
                temp = word + "ma"
            else:
                temp = word[1:] + word[0] + "ma"
            for i in range(0,index+1):
                temp += 'a'
            ans = ans + temp + ' '
        return ans[:len(ans)-1]