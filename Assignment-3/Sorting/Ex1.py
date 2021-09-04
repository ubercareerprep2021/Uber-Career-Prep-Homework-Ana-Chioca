# Three Partition Sort

# Time Complexity: O(n)
# Space Complexity: O(1)

def findMidElement(array):
    max = 0
    mid = 0
    for i in range(len(array)):
        if array[i] > max: 
            aux = max
            max = array[i]
            min = mid
            mid = aux
    return min, mid, max

def threePartitionSort(array):
    min, mid, max = findMidElement(array)
    middle = 0
    smaller = 0
    greater = 0

    for i in array:
        if i > mid: greater += 1
        elif i < mid: smaller += 1
        else: middle += 1
    
    for i in range(smaller):
        array[i] = min
    for j in range(smaller,middle+smaller):
        array[j] = mid
    for i in range(middle+smaller,greater+middle+smaller):
        array[i] = max

array = [5,5,15,5,20,15,5,5,15]
threePartitionSort(array)
print(array)
