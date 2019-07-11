## Instrucciones:
Son programas c, no c++. El link dinámico en c++ tiene otras complicaciones (sobrecarga, despacho dinamico, etc).
 
## Linkeo estático:
- Compilar con

`gcc -static main.c util_uno.c util_dos.c util_tres.c -o prgestat`

- Verificar el tamaño del archivo con

`size prgestat`

- Comprobar que es estatico con

`objdump -T prgestat`

## Linkeo dinamico
Correr el make

`make all`


Comparar el tamaño

`size prgestat prog`

Comprobar que es dinámico

`objdump -T prog`

Al correr da un error. Ver que biblioteca falta con

`ldd prog`

hacer accesible libutiles.so

`LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.`

(se le pone el directorio actual (.) en el path de busqueda )
Ahora corre bien
Carga dinamica en ejecucion:
esta en el directorio dyn_shared
construir con make y probarla
