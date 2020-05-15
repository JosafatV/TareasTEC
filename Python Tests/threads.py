import threading
import time

x = 0
my_lock = threading.Lock()

def foo (thread_id):
    for i in range (0, 5):
        global x
        global my_lock
        my_lock.acquire()
        x += 1
        print("x increased by thread " + str(thread_id) + "\n")
        my_lock.release()
        time.sleep(thread_id/10)

def main ():
    global x
    t1 = threading.Thread(target=foo, args=(1,))
    t2 = threading.Thread(target=foo, args=(2,))
    t3 = threading.Thread(target=foo, args=(3,))
    
    print("initial value of x is " + str(x))

    t1.start()
    t2.start()
    t3.start()

    t1.join()
    t2.join()
    t3.join()

    print(x)
