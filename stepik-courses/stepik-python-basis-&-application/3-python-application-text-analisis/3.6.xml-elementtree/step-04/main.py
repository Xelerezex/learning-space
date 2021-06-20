from xml.etree import ElementTree

root = ElementTree.fromstring(input())
colors = {"red": 0, "green": 0, "blue": 0}


def getcubes(root, value):
    colors[root.attrib['color']] += value
    for child in root:
        getcubes(child, value + 1)


getcubes(root, 1)
print(colors["red"], colors["green"], colors["blue"])
