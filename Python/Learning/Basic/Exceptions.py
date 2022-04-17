x = 5
if x < 0:
    raise Exception('x should be positive')

a = 5
assert(a>=0), 'x is not positive'  

try:
    b = 5 /0
except:
    print('An error ocurred')  

try:
    c = 5 / 0
except Exception as e:
    print(e)

try:
    d = 5 / 0
    e = d + '10'
except ZeroDivisionError as e:
    print(e)
except TypeError as e:
    print(e)
else: # Se nao tiver erro
    print('No error')
finally: # Sempre roda
    print('cleaning up...')  

class valueTooHighError(Exception):
    pass

class ValueTooSmallError(Exception):
    def __init__(self, message, value):
        self.message = message
        self.value = value

def test_value(x):
    if x > 100:
        raise valueTooHighError('value is too high' )
    if x < 5:
        raise ValueTooSmallError('value is too small: ', x) 

try:
    test_value(200)
except valueTooHighError as e:
    print(e) 
except ValueTooSmallError as e:
    print(e.message, e.value)              