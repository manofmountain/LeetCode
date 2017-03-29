#28.91%
class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        dirList = path.split('/');
        resList = list()
        res = '/'
        for dir in dirList:
            if dir == '.' or dir == ' ':
                continue
            elif dir == '..':
                if resList:
                    resList.pop()
            else:
                resList.append(dir)
        return res + '/'.join(resList)

#A better solution but hs the same principle with mine		
class Solution(object):
    def simplifyPath(self, path):
        places = [p for p in path.split("/") if p!="." and p!=""]
        stack = []
        for p in places:
            if p == "..":
                if len(stack) > 0:
                    stack.pop()
            else:
                stack.append(p)
        return "/" + "/".join(stack)
                