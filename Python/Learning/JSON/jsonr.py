import json

person = {"name": "John", "age": 30, "city": "New York", "hasChildren": False, "titles": ["engineer", "programmer"]}

personJSON = json.dumps(person, indent=4) 
print(personJSON)

with open('person.json', 'w') as file:
    json.dump(person, file, indent=4)