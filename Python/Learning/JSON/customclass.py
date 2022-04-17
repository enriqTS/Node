import json
from typing import Type
from json import JSONEncoder

class User:
    def __init__(self,name,age):
        self.name = name
        self.age = age

user = User('Max', 27)  

def encode_user(o):
    if isinstance(o, User):
        return{'name': o.name, 'age': o.age, o.__class__.__name__: True}
    else:
        raise TypeError('Object of type User is not JSON serializable')

class UserEncoder(JSONEncoder):
    def default(self, o):
        if isinstance(o, User):
            return{'name': o.name, 'age': o.age, o.__class__.__name__: True}
        return JSONEncoder.default(self, o)    

userJSON = json.dumps(user, default=encode_user)  
print(userJSON) 

userJSON = json.dumps(user, cls=UserEncoder)  
print(userJSON)

userJSON = UserEncoder().encode(user)
print(userJSON)

def decode_user(dct):
    if User.__name__ in dct:
        return User(name=dct['name'], age=dct['age'])
    return dct    

user = json.loads(userJSON, object_hook=decode_user)
print(type(user))
print(user.name)