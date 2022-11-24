/*
n procesos hebras tipo T, duración sleep(random[a,b])
m hebras tipo E que procesaran las hebras tipo T
crear runqueue activa y expirada
0 maxima prioridad y 9 minima prioridad
n procesos se insertan en la runqueue activa según su prioridad 0,9
las hebras tipo E procesan cada hebra tipo T de la runqueua activa según su prioridad 0,9
cada hebra tipo E procesara a la hebra tipo T un quantum, si el proceso no termina dentro del quantum
se disminuye la prioridad y se le da un nuevo tiempo sleep(random[a,b])
la hebra tipo E manda a la hebra tipo T a la runqueu expirada
Cuando se procesan todos los procesos de la runqueue activa, se termina un periodo y se inicia otro
donde las hebras tipo E sacan de la runqueue expirada las hebras tipo T y las mandan de vuelta 
a la runqueue activada, cuando al runqueue expirada esta vacia, se termina otro periodo y se vuelve a 
trabajar sobre la runqueue activa.

Hebras tipo G que según condición o tiempo crean nuevas hebras tipo T y se agregan al runqueue

Pregunta: ¿que pasa cuando la prioridad ya es 9 y se debe bajar la prioridad?
*/

#include <bits/stdc++.h>
#include "Runqueue.h"
using namespace std;

int main(){
Runqueue *active = new Runqueue();
Runqueue *expired = new Runqueue();

}
