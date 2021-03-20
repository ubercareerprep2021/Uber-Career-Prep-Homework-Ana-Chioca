def isStringPermutation(s1: str, s2: str) -> bool:
    s1 = sorted(s1)
    s2 = sorted(s2)
    if s1 == s2: return True
    else: return False 

def pairsThatEqualSum(inputArray: list, targetSum: int) -> list:
    lista = []
    for n in inputArray:
        if (targetSum - n) in inputArray: 
            lista.append((n, targetSum-n))
            inputArray.remove(targetSum-n)
    return lista

# testing isStringPermutation function:
s1 = "asdf"
s2 = "fdsa"
if isStringPermutation(s1, s2): print('They are a permutation!')
else: print('They are NOT a permutation')

# testing pairsThatEqualSum function:
inputArray = [1, 2, 3, 4, 5]
print(pairsThatEqualSum(inputArray, 7))