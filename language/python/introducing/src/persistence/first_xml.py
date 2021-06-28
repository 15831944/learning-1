'''
Created on Jun 24, 2021

@author:  Gabriel Dimitriu
'''
import xml.etree.ElementTree as et
tree = et.ElementTree(file = 'menu.xml')
root = tree.getroot()
print(root.tag)
for child in root:
    print("tag:",child.tag,"attributes",child.attrib)
    for grandchild in child:
        print("\ttag:", grandchild.tag,"attributes",grandchild.attrib)

print(len(root))
print(len(root[0]))

#for security
# insecure:
from xml.etree.ElementTree import parse as insecure
et = insecure('menu.xml')
# protected:
from defusedxml.ElementTree import parse as secure
et = secure('menu.xml')