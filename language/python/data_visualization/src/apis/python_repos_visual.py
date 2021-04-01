'''
Created on Mar 30, 2021

@author:  Gabriel Dimitriu
'''

import requests
from plotly.graph_objs import Bar
from plotly import offline

url = "https://api.github.com/search/repositories?q=language:python&sort=stars"
headers = {'Accept':'application/vnd.github.v3+json'}
r = requests.get(url,headers=headers)
print(f"Status code: {r.status_code}")
#process data
response_dict = r.json()
repo_dicts = response_dict['items']

repo_names, stars, labels = [],[], []
repo_links = []
for repo_dict in repo_dicts:
    repo_name = repo_dict['name']
    repo_names.append(repo_name)
    repo_url = repo_dict['html_url']    
    stars.append(repo_dict['stargazers_count'])
    repo_link = f"<a href='{repo_url}'>{repo_name}</a>"
    repo_links.append(repo_link)
    owner = repo_dict['owner']['login']
    description = repo_dict['description']
    label = f"{owner}<br />{description}"
    labels.append(label)
    
#make visualization
data = [ {
    'type': 'bar',
#    'x': repo_names,
    'x': repo_links,
    'y': stars,
    'hovertext': labels,
    'marker': {
        'color': 'rgb(60,100,150)',
        'line': {'width': 1.5, 'color': 'rgb(25,25,25)'},
        'opacity': 0.6,}
    }]
my_layout = {
    'title': 'Most-Starred Python Projects on GitHub',
    'xaxis': {'title': 'Repository',
              'titlefont': {'size' : 24},
              'tickfont': {'size': 14}},
    'yaxis': {'title': 'Stars',
              'titlefont': {'size' : 24},
              'tickfont': {'size': 14}},
    }
fig = {'data': data,'layout': my_layout}
offline.plot(fig,filename='repos.html')