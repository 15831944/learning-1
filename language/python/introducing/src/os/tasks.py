'''
    Created on Jun 22, 2021
    
    @author:  Gabriel Dimitriu
    '''
from invoke import task

@task
def mytime(ctx):
    import time
    now = time.time()
    time_str = time.asctime(time.localtime(now))
    print("Local time is", time_str)