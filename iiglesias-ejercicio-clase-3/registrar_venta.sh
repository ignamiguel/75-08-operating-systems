#!/bin/bash

echo "== INICIANDO =="
# Subject: E1 Clases3 SO7508@gmail.com
# sh registrar_venta.sh (12)(345678)9999 COD1 canal-1

# Número de teléfono origen 
# Código del cliente 
# Canal

numero_tel=$1
codigo_cliente=$2
canal=$3

echo "Número de teléfono origen: $numero_tel"
echo "Código del cliente: $codigo_cliente"
echo "Canal: $canal"

# Obtener el codigo de area del numero de tel
codigo_area=`echo $numero_tel | sed 's-^(\([0-9]\{2\}\))(\([0-9]\{6\}\))\([0-9]\{4\}\)-\2-g'`
echo "[1] codigo_area: $codigo_area"

# Armar la regex para buscar por codigo de area
regex="$codigo_area;[^;]*;[^;]*\$"
echo "[2] regex: $regex"

# Buscar en el archivo "Signals&Chanels.dat"
resultado_busqueda_x_codigo_area=`grep "$regex" "Signals&Chanels.dat"`
echo "Resultado busqueda por codigo de area: $resultado_busqueda_senal"

# Obtener la senal 
senal=`echo $resultado_busqueda_x_codigo_area | sed 's-\([^;]*\);\([^;]*\);\([^;]*\);\([^;]*\);\([^;]*\)$-\2-g'`
echo "Resultado busqueda por senal: $senal"

sh RegistrarVentaPPV.sh "$codigo_cliente" "$senal" 

