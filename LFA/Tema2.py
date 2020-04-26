# INPUT
# variabile
# lungimea cuvintelor generate
# reg_prod_1
# reg_prod_2
# ...
# reg_prod_k

with open("data.in") as fin:
    N = fin.readline().split()
    generators = {n: [] for n in N}
    length = int(fin.readline())
    for line in fin:
        line = line.strip()
        parts = line.split('->')
        generators[parts[0]].append(parts[1])


# eliminam relatiile de forma Gen->lambda

#gasim generatorii care au tranzitie in lambda
lambdaGen = []
for gen, lst in generators.items():
    if '#' in lst:
        lst.remove('#')
        lambdaGen.append(gen)

for lst in generators.values():
    for state in lst:
        positions = [(state[i], i) for i in range(len(state)) if state[i] in lambdaGen]
        for gen, index in positions:
            lst.append(state[:index] + state[index+1:])


# generam cuvintele
prevStates = ["S"]
rez = set()
ok = True
while ok:
    newStates = []
    tmpRez = set()
    for state in prevStates:
        uppers = [(state[i], i) for i in range(len(state)) if state[i] in N]
        for upper, index in uppers:
            leadingStr = state[:index]
            trailingStr = state[index+1:]
            for newState in generators[upper]:
                newStates.append(leadingStr+newState+trailingStr)
    prevStates = []
    for state in newStates:
        state = state.replace('#', '')  # eliminam eventuale lambda-uri din cuvinte
        if not any((x in N) for x in state):  # daca este un cuvant final (i.e. nu mai avem generator)
            if len(state) <= length:
                tmpRez.add(state)
                rez.add(state)
        elif len(state) <= length:
            prevStates.append(state)

    if not prevStates:
        ok = False
print(sorted(list(rez), key=lambda x: (len(x), x)))
