#Start from zero node and then try to find a cycle that returns back to zero. If one does not exist then it is not a quotient; if one does then break code 
#and add MultiplyBy to set. - Depth First Search

def pathways(base, multiplier, missing_numbers):
  # (carryFrom, carryTo) --> (read, write)
  pathways_list = []

  #print("(carryFrom, carryTo) --> (read, write)")

  for carryFrom in range (multiplier):
      for read in range (base):
          total = carryFrom + (multiplier*read)
          write = total % base
          carryTo = int((total - write) / base)
        
          if (not((read in missing_numbers) or (write in missing_numbers))):
              pathways_list.append((carryFrom, carryTo))
  return pathways_list

def create_adjacency_matrix(pathways, multiply):
  matrix = {}
  for i in range(multiply):
    matrix[i] = []
  for i in pathways:
    if (not (i[0] == 0 and i[1] ==0)):
      matrix[i[0]].append(i[1])
  return matrix

print(create_adjacency_matrix(pathways(3,4,[]), 4))


def dfs_recurse(graph, starting_point, path, start):
  if ((int(starting_point) == 0) and (int(len(path)) > 0)):
    print(path+[0])
    a = 1/0
    return True

  for index in graph[starting_point]:
    if (((not (index in path)) or (index == 0)) and (len(path) < 999)):
      if (time.time() <= (start+120)):
        dfs_recurse(graph, index, path+[starting_point], start)
      else:
        print("No quotient set")
        a = 1/0
        return False
    else:
      continue
  #print("No quotient set")
  return False

import time

def quotient_check(base, multiply, missing_numbers):
  for i in range(1, multiply+1):
    print(str(i) + " : ", end=" ")
    pathway = pathways(base, i, missing_numbers)
    adjacency = create_adjacency_matrix(pathway, i)
    try:
      recurse = dfs_recurse(adjacency, 0, [], time.time())
    except:
      pass
quotient_check(3, 500, [])

path = []
print(path +[1])
