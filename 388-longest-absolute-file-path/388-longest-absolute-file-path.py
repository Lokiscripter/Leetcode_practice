class Solution:
    '''
    1、用 depth_length_map 保留每层路径的长度， input.split('\n') 切分为每行分析每行长度与文件
    2、line.count('\t') 的个数来判断是第几层
    3、line.count('.') 的个数判断是否有文件，有文件获取当前最长路径值
    4、每层都要添加depth个 / ， 长度需要修改
    '''
    def lengthLongestPath(self, input: str) -> int:
        res = 0
        depth_length_map={-1:0}
        for line in input.split('\n'):
            depth = line.count('\t')
            #每行空格最后要被去掉(\t)
            depth_length_map[depth] = depth_length_map[depth-1] + len(line) - depth
            if line.count('.'):
                res = max(res,depth_length_map[depth]+depth)
        return res