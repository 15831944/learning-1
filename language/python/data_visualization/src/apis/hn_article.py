'''
Created on Mar 30, 2021

@author:  Gabriel Dimitriu
'''
import requests
import json
from operator import itemgetter

#make the api call
#url = 'https://hacker-news.firebaseio.com/v0/item/19155826.json'
url = 'https://hacker-news.firebaseio.com/v0/topstories.json'
r = requests.get(url)
print(f"Status code: {r.status_code}")

response_dict = r.json()
readable_file = 'hn_readable.json'
with open(readable_file,'w') as f:
    json.dump(response_dict,f, indent=4)
# for the second url    
submission_dicts = []
for submission_id in response_dict[:30]:
    #make a separate call for each submission id
    url = f"https://hacker-news.firebaseio.com/v0/item/{submission_id}.json"
    r = requests.get(url)
    print(f"id: {submission_id}\tstatus: {r.status_code}")
    response_dict_1 = r.json()
    readable_file = 'hn_readable.json'
    with open(readable_file,'w') as f:
        json.dump(response_dict_1,f, indent=4)
    try:
        submission_dict = {
            'title': response_dict_1['title'],
            'hn_link': f"https://news.ycombinator.com/item?id={submission_id}",
            'comments': response_dict_1['descendants'],
            }
    except KeyError:
        submission_dict = {
            'title': response_dict_1['title'],
            'hn_link': f"https://news.ycombinator.com/item?id={submission_id}",
            'comments': 0,
            }
    else:
        submission_dict = {
            'title': response_dict_1['title'],
            'hn_link': f"https://news.ycombinator.com/item?id={submission_id}",
            'comments': response_dict_1['descendants'],
            }
    submission_dicts.append(submission_dict)
submission_dicts = sorted(submission_dicts, key=itemgetter('comments'), reverse = True)

for submission_dict in submission_dicts:
    print("f\nTitle: {submission_dict['title']}")
    print(f"Discussion link: {submission_dict['hn_link']}")
    print(f"Comments: {submission_dict['comments']}")