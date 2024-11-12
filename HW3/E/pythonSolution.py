def isCorrect(s):  
    counter1 = 0
    counter2 = 0
    flag = True
    if s[0] == '-':
        ls = [0]  
        num = '0'

    else:
        ls = []
        num = ''

    if s[0] not in '+*/)' and s[-1] not in '*-+/(':
        for i in s:
            if ls:
                if i.isdigit() and not type(ls[-1]) is int and ls[-1] != ')':
                    num += i
                elif i in '+*/':
                    if num:
                        ls.append(int(num))
                        num = ''
                    elif ls[-1] == '(':
                        flag  = False
                        break

                    ls.append(i)
                elif i == '-':
                    if num:
                        ls.append(int(num))
                        num = ''
                    elif ls[-1] == '(':
                        ls.append(0)
                    ls.append(i)
                    
                elif i == '(' and ls[-1] in '+-*/(':
                    counter1 += 1
                    ls.append(i)
                    
                elif i == ')' and counter1 > counter2 and ((type(ls[-1]) is int or ls[-1] == ')') or (ls[-1] in '-+*/(' and num)):
                    counter2 += 1
                    if num:
                        ls.append(int(num))
                        num = ''
                    ls.append(i)
                elif i == ' ':
                    if num:
                        ls.append(int(num))
                        num = ''
                    continue
                else:
                    flag = False
                    break
            else:
                if (num or num == '') and i.isdigit():
                    num += i
                elif i == '(':
                    if num:
                        ls.append(int(num))
                        num = ''
                    ls.append(i)
                    counter1 += 1
                elif num and i == ' ':
                    ls.append(int(num))
                    num = ''
                elif i in '+-*/':
                    ls.append(int(num))
                    num = ''
                    ls.append(i)
                
    else:
        flag = False

    if num:
        ls.append(int(num))
    if counter1 != counter2:
        flag = False
    if flag:
        return ls
    else:
        return 'WRONG'

    

def normalize(s):
    stack = []
    ans = []
    dict = {
        '-': 0,
        '+': 0,
        '*': 1,
        '/': 1
    }
    
    for i in s:
        if type(i) is int:
            ans.append(i)
        else:
            if i == '(':
                stack.append(i)
            elif i == ')':
                while len(stack) != 0 and stack[-1] != '(':
                    ans.append(stack.pop())
                stack.pop()
            else:
                while len(stack) != 0 and stack[-1] != '(' and dict[stack[-1]] >= dict[i]:
                    ans.append(stack.pop())
                stack.append(i)
    if stack:
        while stack:
            ans.append(stack.pop())
    return ans


def solve(vr):
    ls = []
    for i in vr:
        if type(i) is int:
            ls.append(i)
        else:
            y = ls.pop()
            x = ls.pop()
            z = {'+': lambda x, y: x + y, '-': lambda x, y: x - y, '*': lambda x, y: x * y, '/': lambda x, y: x // y }[i](x, y)
            
            ls.append(z)
    return ls.pop()

def main():
    inp = str(input())
    tmp = isCorrect(inp)
    
    if tmp != 'WRONG':
        inp = normalize(tmp)
        print(solve(inp))
    else:
        print("WRONG")
    
if __name__ == '__main__':
    main()
