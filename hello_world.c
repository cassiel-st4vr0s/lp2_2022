from asyncio.windows_events import NULL
from multiprocessing import Semaphore
import threading
import time

produto = []
sem1=threading.Semaphore()
sem2=threading.Semaphore()  

def Produtor():
    sem1.acquire()

    global produto, produção
    produção = True
    
       
    for i in range(10):
        produto.append(i) #aqui é realizado a produção
        print('\nProduziu : {}'.format(produto))
        time.sleep(1)
                
    sem1.release()


def Consumidor():
    sem2.acquire()
    global produto, produção
    

   
    while produção:
        if (len(produto)==0):
           break
        x = produto.pop(0)  #aqui é realizado o consumo
        print('\nConsumiu: {}'.format(x))
        time.sleep(2)
    sem2.release()
       
t1 = threading.Thread(target=Produtor)
t2 = threading.Thread(target=Consumidor)
t1.start()
t2.start()
