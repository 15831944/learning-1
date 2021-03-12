'''
Created on Mar 12, 2021

@author:  Gabriel Dimitriu
'''
#using arbitrary keyword arguments
def build_profile(first,last, **user_info):
    """ build dictionary containing everything we know """
    user_info['first_name'] = first
    user_info['last_name'] = last
    return user_info

user_profile = build_profile('albert','einstein', location='princepton', field = 'physics')
print(user_profile)