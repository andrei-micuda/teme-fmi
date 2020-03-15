# INPUT:
# nr stari
# stare initiala
# stari finale
# nr tranzitii
# stare1 stare2 litera
# ..
# nr teste
# sir de testat
# ..
# NOTA: Lambda va fi desemnat cu # in input

def validate(str, st_curr):
    global st_fin, cases
    if str == '':
        if st_curr in st_fin:
            cases.append(True)
            return
        else:
            cases.append(False)
            return
    curr = str[0]
    next_tranz = [tranz[0] for tranz in tranzitii[st_curr] if tranz[1] == curr]
    if not next_tranz:
        cases.append(False)
        return
    for st_next in next_tranz:
        validate(str[1:], st_next)


with open("data.in") as fin:
    nr_stari = int(fin.readline())
    st_init = int(fin.readline())
    st_fin = [int(x) for x in fin.readline().split()]

    tranzitii = [[] for i in range(nr_stari)]
    nr_tranz = int(fin.readline())
    for i in range(nr_tranz):
        st1, st2, word = fin.readline().strip().split()
        tranzitii[int(st1)].append((int(st2), word))

    teste = []
    nr_teste = int(fin.readline())
    for i in range(nr_teste):
        teste.append(fin.readline().strip())


for str in teste:
    cases = []
    str = ''.join([x for x in str if x != '#'])
    validate(str, st_init)
    if True in cases:
        print(True)
    else:
        print(False)