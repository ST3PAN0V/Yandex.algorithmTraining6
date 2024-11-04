def trim_val(arr, val):
    start = 0
    end = len(arr) - 1

    while start < end and arr[start] == val:
        start += 1

    while end > start and arr[end] == val:
        end -= 1

    return arr[start:end + 1]

def unique(arr):
 
    unique_elements = []
    for element in arr:
        if element not in unique_elements:
            unique_elements.append(element)
    return unique_elements

def count_of_elements(arr):

    element_counts = {}
    for element in arr:
        if element in element_counts:
            element_counts[element] += 1
        else:
            element_counts[element] = 1
    unique_elements = list(element_counts.keys())
    counts = [element_counts[element] for element in unique_elements]
    return counts

def sum_axis(arr, n):
    arr_f=[]
    for j in range(n):
        sum_s = 0
        for i in range(n):
            sum_s += arr[j][i]
        arr_f.append(sum_s)
    return arr_f

n = int(input())

val = []

for i in range(n):
    str =[]
    for char in input():
        if char == '#':
            str.append(1)
        else:
            str.append(0)
    val.append(str)
   
sum_stolb = sum_axis(list(zip(*val)), n)
sum_str = sum_axis(val, n)
sum_stolb = trim_val(sum_stolb, 0)
sum_str = trim_val(sum_str, 0)
counter_entry_stolb=count_of_elements(sum_stolb)
counter_entry_str=count_of_elements(sum_str)
uniq_stolb = unique(sum_stolb)
uniq_str = unique(sum_str)

if len(uniq_stolb)==1 and uniq_stolb[0]!=0 and counter_entry_stolb[0]==len(sum_stolb) and len(uniq_str)==1 and uniq_str[0] !=0 and counter_entry_str[0]==len(sum_str) and len(sum_str)==uniq_stolb[0]:
    print('I')
elif len(uniq_stolb)==2 and counter_entry_stolb[0]==len(sum_stolb)-counter_entry_stolb[1] and len(uniq_str)==2 and counter_entry_str[0]==len(sum_str)-counter_entry_str[1] and sum_str[0]==sum_str[-1] and len(sum_str)==(sum_stolb[0]):
    if sum_stolb[0]==sum_stolb[-1]:
        if sum_str[0]==max(sum_str):
            sum_str = trim_val(sum_str, max(sum_str))
            sum_stolb = trim_val(sum_stolb, max(sum_stolb))
            uniq_stolb = unique(sum_stolb)
            uniq_str = unique(sum_str)
            if len(uniq_stolb)== 1 and len(uniq_str)==1:
                print('O')
            else: 
                print('X')
        elif sum_str[0]!=max(sum_str):
            sum_str = trim_val(sum_str, min(sum_str))
            sum_stolb = trim_val(sum_stolb, max(sum_stolb))
            uniq_stolb = unique(sum_stolb)
            uniq_str = unique(sum_str)
            if len(uniq_stolb)== 1 and len(uniq_str)==1:
                print('H')
    elif sum_str[0]==sum_str[-1]:
        sum_str = trim_val(sum_str, max(sum_str))
        sum_stolb = trim_val(sum_stolb, max(sum_stolb))
        uniq_stolb = unique(sum_stolb)
        uniq_str = unique(sum_str)
        if len(uniq_stolb)== 1 and len(uniq_str)==1:
            print('C')
        else: 
            print('X')
elif len(uniq_stolb)==2 and counter_entry_stolb[0]==len(sum_stolb)-counter_entry_stolb[1] and len(uniq_str)==2 and counter_entry_str[0]==len(sum_str)-counter_entry_str[1] and sum_str[0]<sum_str[-1] and len(sum_str)==(sum_stolb[0]) and sum_str[0]!=sum_str[-1] and sum_stolb[0]!=sum_stolb[-1]:
        sum_str = trim_val(sum_str, max(sum_str))
        sum_stolb = trim_val(sum_stolb, max(sum_stolb))
        uniq_stolb = unique(sum_stolb)
        uniq_str = unique(sum_str)
        if len(uniq_stolb)== 1 and len(uniq_str)==1:
            print('L')
        else: 
            print('X')
elif len(uniq_stolb)==3 and counter_entry_stolb[0]==len(sum_stolb)-counter_entry_stolb[1]-counter_entry_stolb[2] and len(uniq_str)==3 and counter_entry_str[0]==len(sum_str)-counter_entry_str[1]-counter_entry_str[2] and len(sum_str)==(sum_stolb[0]):
    sum_str = trim_val(sum_str, max(sum_str))
    sum_stolb = trim_val(sum_stolb, max(sum_stolb))
    uniq_stolb = unique(sum_stolb)
    uniq_str = unique(sum_str)
    if len(uniq_stolb)==2 and len(uniq_str)==3 and uniq_stolb[-1] > min(uniq_stolb):
        sum_str = trim_val(sum_str, min(sum_str))
        sum_stolb = trim_val(sum_stolb, max(sum_stolb))
        uniq_stolb = unique(sum_stolb)
        uniq_str = unique(sum_str)
        if len(uniq_stolb)== 1 and len(uniq_str)==2:
            sum_str = trim_val(sum_str, max(sum_str))
            uniq_str = unique(sum_str)
            if len(uniq_str)==1:
                print('P')
            else:
                print('X')
        else: 
            print('X')
    else: 
        print('X')
else:
    print('X')
