# INPUT TEMPLATE PDA ACCEPTANCE
# NOTE: lambda -> #
# s1 s2 ... sn (starile)
# si (starea initiala)
# sf1 sf2 ... sfm (starile finale)
# Z (simbolul pentru stiva vida)
# ds1 df1 lit1 dpop1/dpush1
# ds2 df2 lit2 dpop2/dpush2
# ...
# dsq dfq litq dpopq/dpushq
# cuv de verificat

with open('data.in') as fin:
    stari = fin.readline().strip().split()
    st_in = fin.readline().strip()
    st_fin = fin.readline().strip().split()
    empty_stack = fin.readline().strip()
    cuv = fin.readline().strip()
    tranzitii = {st: [] for st in stari}
    for line in fin:
        line = line.strip()
        s1, s2, lit, stack = line.split(' ', 3)
        stack_pop, stack_push_tmp = stack.split('/')
        stack_push = stack_push_tmp.split()
        tranzitii[s1].append((s2, lit, stack_pop, stack_push))
        # print(s1)
        # print(s2)
        # print(lit)
        # print(stack_pop)
        # print(stack_push)
        # print("---------------")

#print(tranzitii)
is_accepted = False
stari_curr = [(st_in, cuv, [empty_stack])]
while stari_curr:
    for stare in stari_curr:
        if stare[0] in st_fin and not stare[1] and stare[2][0] == empty_stack:
            is_accepted = True
            break

    stari_noi = []
    for stare in stari_curr:
        for tranzitie in tranzitii[stare[0]]:
            if stare[1] and tranzitie[1] == stare[1][0] and tranzitie[2] == stare[2][0]:
                new_stack = stare[2].copy()
                if tranzitie[3][0] != '#':
                    new_stack[0:1] = tranzitie[3]
                else:
                    new_stack = new_stack[1:];
                stari_noi.append((tranzitie[0], stare[1][1:], new_stack))
            elif tranzitie[1] == '#' and tranzitie[2] == stare[2][0]:
                new_stack = stare[2].copy()
                if tranzitie[3][0] != '#':
                    new_stack[0:1] = tranzitie[3]
                else:
                    new_stack = new_stack[1:]
                stari_noi.append((tranzitie[0], stare[1], new_stack))
                # print(tranzitie)
    stari_curr = stari_noi
    # print(stari_curr)
    # input()
print(is_accepted)