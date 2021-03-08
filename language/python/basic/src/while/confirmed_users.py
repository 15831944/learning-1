'''
Created on Mar 8, 2021

@author:  Gabriel Dimitriu
'''
#moving items from one list to another
#start a list with users that need to be verified
#and an empty list to hold confirmed users
unconfirmed_users = ['alice', 'brian', 'candace']
confirmed_users = []

#verify each user
while unconfirmed_users:
    current_user = unconfirmed_users.pop()
    print(f"Verifying use: {current_user.title()}")
    decision = input("Confirm it: ")
    if decision == 'yes':
        confirmed_users.append(current_user)

#display all confirmed users
print("\nThe following users has been confirmed:")
for user in confirmed_users:
    print(user.title())