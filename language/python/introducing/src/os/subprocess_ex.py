'''
Created on Jun 22, 2021

@author:  Gabriel Dimitriu
'''
import subprocess

ret = subprocess.check_output(['date', '-u'])
print(ret)

ret = subprocess.getoutput('date -u')
print(ret)

ret = subprocess.getstatusoutput('date')
print(ret)

ret = subprocess.call('date -u', shell=True)
print(ret)

