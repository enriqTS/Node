def start_end_decorator(func):
    def wrapper():
        print('Start')
        func()
        print('End')
    return wrapper

@start_end_decorator  # Mesmo que:  print_name = start_end_decorator(print_name)   
def print_name():
    print('Alex')

print_name()


