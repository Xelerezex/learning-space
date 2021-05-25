n = int(input())
scopes = {'global': {'funcs': [], 'vars': []}}


def add(scopes, current_namespace, what):
  if current_namespace not in scopes:
    scopes[current_namespace] = {}
    scopes[current_namespace]['vars'] = []
    scopes[current_namespace]['vars'].append(what)
  else:
    if 'vars' not in scopes[current_namespace]:
      scopes[current_namespace]['vars'] = []
      scopes[current_namespace]['vars'].append(what)
    else:
      scopes[current_namespace]['vars'].append(what)


def create(scopes, current_namespace, parent_namespace):
  if current_namespace not in scopes:
    scopes[current_namespace] = {}
    scopes[current_namespace]['funcs'] = []
    scopes[current_namespace]['vars'] = []
    scopes[parent_namespace]['funcs'].append(current_namespace)
    scopes[current_namespace]['parent'] = parent_namespace
  else:
    if 'funcs' not in scopes[current_namespace]:
      scopes[current_namespace]['funcs'] = []
      scopes[current_namespace]['parent'] = parent_namespace
      scopes[parent_namespace]['funcs'].append(current_namespace)
    else:
      scopes[current_namespace]['funcs'].append(current_namespace)
      scopes[parent_namespace]['funcs'].append(current_namespace)


def search(scopes, namespace, what):
  if what in scopes[namespace]['vars']:
    return namespace
  else:
    try:
      upper_namespace = scopes[namespace]['parent']
    except KeyError:
      return None
    return search(scopes, upper_namespace, what)


for i in range(n):
  command = input().split()
  if command[0] == 'add':
    add(scopes, command[1], command[2])
  elif command[0] == 'create':
    create(scopes, command[1], command[2])
  elif command[0] == 'get':
    print(search(scopes, command[1], command[2]))
