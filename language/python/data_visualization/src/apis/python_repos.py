'''
Created on Mar 30, 2021

@author:  Gabriel Dimitriu
'''

import requests

url = "https://api.github.com/search/repositories?q=language:python&sort=stars"
headers = {'Accept':'application/vnd.github.v3+json'}
r = requests.get(url,headers=headers)
print(f"Status code: {r.status_code}")
response_dict = r.json()
#print(response_dict.keys())
print(f"Total repositories: {response_dict['total_count']}")
repo_dicts = response_dict['items']
print(f"Repositories returned: {len(repo_dicts)}")
repo_dict = repo_dicts[0]
#expore data in repos
#print(f"\nKeys: {len(repo_dict)}")
#for key in sorted(repo_dict.keys()):
#    print(key)

print("\nSelcted information about first repository:")
print(f"Name: {repo_dict['name']}")
print(f"Owner {repo_dict['owner']['login']}")
print(f"Stars: {repo_dict['stargazers_count']}")
print(f"Respository: {repo_dict['html_url']}")
print(f"Description: {repo_dict['description']}")