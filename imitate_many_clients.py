import subprocess
import time
import random

args = ['Exec/KVEngine.exe', '-nodraw', '-auto', '-auto_connect', 'login=Guest']
processes = []
for x in range(0, 5):
    p = subprocess.Popen(args, cwd = './Exec')
    processes.append(p)
#p.kill ()

processes = processes[1:]

while 1:
    time.sleep(5)
    new_processes = []
    for p in processes:
        if random.randint(0, 10) == 0:
            p.kill()
            p.communicate()
            new_processes.append(subprocess.Popen(args, cwd = './Exec'))
        else:
            new_processes.append(p)
    processes = new_processes
    

    

    
    
            