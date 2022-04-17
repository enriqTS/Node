from threading import Lock

with open('notes.txt', 'w') as file:
    file.write('something')

file = open('notes.txt', 'w')
try:
    file.write('something')
finally:
    file.close() 

lock = Lock()
lock.acquire()
# ...
lock.release()

with lock:
    pass

class ManageFile:
    def __init__(self, filename):
        self.filename = filename
    def __enter__(self):
        print('enter')
        self.file = open(self.filename, 'w')
        return self.file

    def __exit__(self, exc_type, exc_value, exc_traceback):
        if self.file:
            self.file.close()
        if exc_type is not None:
            print('exeption has been handled')    
        #print('exc', exc_type, exc_value)    
        print('exit') 
        return True

with ManageFile('notes.tx') as file:
    file.write('something')  
    file.sometihis()   
print('continuing')            

from contextlib import contextmanager

@contextmanager
def open_managed_file(filename):
    f = open(filename, 'w')
    try:
        yield f
    finally:
        f.close()  

with open_managed_file('notes.txt') as f:
    f.write('something')