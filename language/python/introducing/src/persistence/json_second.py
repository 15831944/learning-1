'''
Created on Jun 28, 2021

@author:  Gabriel Dimitriu
'''
import json
import datetime
import time

now = datetime.datetime.utcnow()
class DTEncoder(json.JSONEncoder):
    def default(self,obj):
        #isinstance() checks the type of obj
        if isinstance(obj, datetime.datetime):
            return int(time.mktime(obj.timetuple()))
        # else it's somethine the normal decoder knows:
        return json.JSONEncoder.default(self, obj)

now_json = json.dumps(now, cls=DTEncoder)
print(now_json)
print(json.dumps(now,default=str))