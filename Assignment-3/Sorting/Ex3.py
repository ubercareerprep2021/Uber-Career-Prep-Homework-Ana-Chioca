# Sorted Merge

# given two arrays A and B of sizes n+m and m 
# Time Complexity:
# Space Complexity: O(1)

def mergeArrays(A, B):
    indexB = 0
    indexA = 0
    while indexA < (len(A) + len(B)):

        if indexA >= len(A):
            break

        while A[indexA] > B[indexB]:
            A.insert(indexA, B[indexB])
            if indexB + 1 < len(B): indexB += 1

        indexA += 1

    j = len(A)
    for i in range(indexB, len(B)):
        A.insert(j, B[i])
        j+=1
    
    
A = [3,5,7,9]
B = [0,1,2,4,6,8,10,12,13]
mergeArrays(A, B)
print(A)
        