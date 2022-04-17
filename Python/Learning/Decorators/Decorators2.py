import functools

# Modelo de decorator
def start_end_decorator(func):

    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        # Faz alguma coisa
        result = func(*args, **kwargs) # Executa a funcao
        # Faz outra coisa
        return result
    return wrapper

@start_end_decorator     
def add5(x):
    return x + 5

print(add5(10))