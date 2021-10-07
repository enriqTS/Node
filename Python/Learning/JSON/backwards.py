import json

person = {"name": "John", "age": 30, "city": "New York", "hasChildren": False, "titles": ["engineer", "programmer"]}

personJSON = json.dumps(person, indent=4) 

person = json.loads(personJSON)
print(person)

# Faz a mesma coisa que o do jsonr.py
with open('person.json', 'r') as file:
    person = json.load(file)
    print(person)