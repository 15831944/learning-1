'''
Created on Mar 10, 2021

@author:  Gabriel Dimitriu
'''
unprinted_designs = ['phone case', 'robot pedant', 'dodechdron']
completed_models = []

#simulate printing
while unprinted_designs:
    current_design = unprinted_designs.pop()
    print(f"Printing model : {current_design}")
    completed_models.append(current_design)

#dispaly all completed models
print("\nThe following models have been printed:")
for completed_model in completed_models:
    print(completed_model)