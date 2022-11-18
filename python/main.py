import pandas as pan
import matplotlib as mpl
import matplotlib.pyplot as plt

entrada = input("Ingrese un pais > ")
info = pan.read_csv("fertility_rate.csv") 


#print (info["Country"][5:10]) # imprime de la linea 5 a la 10
print(info[info["Country"] == entrada]) #imprime de la columna Country, la fila del pais pedido
filapais = info[info["Country"] == entrada] 
filapais.plot(kind="bar")
plt.show()