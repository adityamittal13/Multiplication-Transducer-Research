import networkx as nx

def Directed_Cycles(base, multiply, notneeded):
  total = 0

  G=nx.DiGraph()

  m = 0

  while m <= multiply - 1:
    G.add_node(m)
    m = m + 1
    

  i = 0
  j = 0
  x = 0

  while i <= (multiply - 1):
    j = 0
    while j <= base - 1:
      total = i + (j* multiply)
      if j not in notneeded and total%base not in notneeded:
        x = total//base
        G.add_edge(i,x)
      j = j + 1
    i = i + 1


  return list(nx.simple_cycles(G))
  #Problem with runtime at Simple _Cycles

def Quotient_Set(base, end_of_set, numbers_excluded):
  Set = []
  t = 1
  while t <= end_of_set:
    k = 0
    while len(Directed_Cycles(base, t, numbers_excluded)) > k:
      if 0 in Directed_Cycles(base, t, numbers_excluded)[k] and Directed_Cycles(base, t, numbers_excluded)[k] != [0]:
        quotient = True
        break
      else:
        quotient = False
      k = k + 1

    if quotient == True:
      Set.append(t)
    t = t + 1
    print(t)
  return Set

# numbers_excluded and notneeded is an array of numbers that you want to exclude

#print(Quotient_Set(13, 100, [1, 2, 3, 4]))



import networkx as nx

def pathways(base, multiply, notneeded):
  total = 0
  pathway_set = []
  i = 0
  j = 0
  x = 0

  while i <= (multiply - 1):
    j = 0
    while j <= base - 1:
      total = i + (j* multiply)
      if j not in notneeded and total%base not in notneeded:
        x = total//base
        pathway_set.append([i,x])
      j = j + 1
    i = i + 1
  return pathway_set

def Directed_Cycles(base, multiply, notneeded):
  total = 0

  G=nx.DiGraph()

  m = 0

  while m <= multiply - 1:
    G.add_node(m)
    m = m + 1
    

  i = 0
  j = 0
  x = 0

  while i <= (multiply - 1):
    j = 0
    while j <= base - 1:
      total = i + (j* multiply)
      if j not in notneeded and total%base not in notneeded:
        x = total//base
        G.add_edge(i,x)
      j = j + 1
    i = i + 1


  return list(nx.simple_cycles(G))

print(pathways(3, 10, [-1]))
