x = 10000
with open ("3.in", "w") as f:
    f.write(f"{x}\n")
    for i in range(500):
        f.write(f'C Show {i+1} show{i+1} 2020/12/01\n')
    for i in range (x-500):
        f.write(f'A show{int(i/100)+1} 2020/12/{i%30+1}\n')