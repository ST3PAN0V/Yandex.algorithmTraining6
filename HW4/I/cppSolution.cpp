def getAns(path, r_path, pre_res):
    lmp, left_max = 0, 0
    sz = len(path)
    for i in range(1, sz-2):
        r0 = r_path[-(i+1)][0]
        r1 = r_path[-(i+1)][1]
        lmp = max(lmp + 1, r0, r1)
        left_max = max(left_max, r0 + r1, lmp + r1, lmp + r0)
        pre_res = max(pre_res, left_max * r_path[-(i+2)][3])
    return pre_res

def pre_calc(tree, path_nodes, root, r_path, o_path, is_start=False):
    stack, res = [], {}
    stack.append((root, None, is_start, False))
    while len(stack) != 0:
        node, par, start, vis = stack.pop()
        if not vis:
            stack.append((node, par, start, True))
            for neir_top in tree[node]:
                if neir_top != par:
                    stack.append((neir_top, node, False, False))
        else:
            deeps = [0, 0, 0, 0]
            
            if len(tree[node]) == 1 and not start:
                tree[node] = []
                res[node] = (1, node, o_path, 0)
                continue
            
            for neir_top in tree[node]:
                if neir_top != par:
                    r = res[neir_top]
                    if r[1] in path_nodes:
                        deeps[2] = r[0]
                    elif r[0] > deeps[0]:
                        deeps[1] = deeps[0]
                        deeps[0] = r[0]
                    elif r[0] > deeps[1]:
                        deeps[1] = r[0]
            tree[node] = []
            if deeps[2] == 0:
                o_path = max(o_path, deeps[0] + deeps[1])
            else:
                deeps[3] = max(res.get(node, (0, 0, 0, 0))[3], deeps[0] + deeps[1], deeps[2] + deeps[0], deeps[2] + deeps[1])
                r_path.append(deeps)
            res[node] = (max(deeps[0:3]) + 1, node, o_path, deeps[3])
    return res[root]

def max_depth(tree, root):
    stack, parent = [(root, None, 0)], {root: None}
    max_d, deep_node = 0, root
    while stack:
        node, par, depth = stack.pop()
        if depth > max_d:
            max_d, deep_node = depth, node
        for neir_top in tree[node]:
            if neir_top != par:
                parent[neir_top] = node
                stack.append((neir_top, node, depth + 1))
    path, cur = [], deep_node
    while cur is not None:
        path.append(cur)
        cur = parent[cur]
    path.reverse()
    return deep_node, max_d, path

def solution(n, graph):
    if n < 3:
        return 0
    tree = [[] for _ in range(n+1)]
    for top1, top2 in graph:
        tree[top1].append(top2)
        tree[top2].append(top1)
    root, _, _ = max_depth(tree, 1)
    _, _, path = max_depth(tree, root)
    if len(path) < 4:
        return 0
    path_nodes, r_path, o_path = set(path), [], 0
    _, _, o_path, _ = pre_calc(tree, path_nodes, root, r_path, o_path, is_start=True)
    pre_res = o_path * (len(path)-1)
    return getAns(path, r_path, pre_res)

def main():
    n = int(input())
    graph = [list(map(int, input().split())) for _ in range(n-1)]
    print(str(solution(n,graph)))

if __name__ == "__main__":
    main()

