from threading import Thread

def square_numbers():
    for i in range(100):
        i * i

if __name__ == "__main__":
    threads = []
    num_threads = 10

    # Create threads
    for i in range(num_threads):
        thread = Thread(target=square_numbers)
        threads.append(thread)

    # Start threads
    for thread in threads:
        thread.start()

    # Join threads (Wait for them to complete)
    for thread in threads:
        thread.join()

    print('end main')              
