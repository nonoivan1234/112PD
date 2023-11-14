articlePath = "." + input()
dictionaryPath = "." + input()

article = open(articlePath, 'r')
dictionary = open(dictionaryPath, 'r')

l = []
dictionary.readline()

for line in dictionary:
    l.append(line.lower().strip())

punk = ['.', ',', '!', '?', ':', ';', '"', "'"]
art = []

tmp = article.readline().lower()
for c in punk:
    tmp = tmp.replace(c, ' ')

art = tmp.split()

cnt = 0

for c in art:
    if c in l:
        cnt += 1

print(cnt)