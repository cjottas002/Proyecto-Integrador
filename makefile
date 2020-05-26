all: proyectointegrador_v3.exe

auxiliar.o: auxiliar/auxiliar.c
	gcc -Wall -pedantic -ansi -c auxiliar/auxiliar.c

cesta.o: cestas/cesta.c
	gcc -Wall -pedantic -ansi -c cestas/cesta.c

podCesta.o: cestas/podCesta.c
	gcc -Wall -pedantic -ansi -c cestas/podCesta.c

clientes.o: clientes/clientes.c
	gcc -Wall -pedantic -ansi -c clientes/clientes.c

listaClientes.o: clientes/listaClientes.c
	gcc -Wall -pedantic -ansi -c clientes/listaClientes.c

listaUsuarios.o: clientes/listaUsuarios.c
	gcc -Wall -pedantic -ansi -c clientes/listaUsuarios.c

solicitud.o: clientes/solicitud.c
	gcc -Wall -pedantic -ansi -c clientes/solicitud.c

accesoSistema.o: main/accesoSistema.c
	gcc -Wall -pedantic -ansi -c main/accesoSistema.c

menus.o: main/menus.c
	gcc -Wall -pedantic -ansi -c main/menus.c

TV_main.o: main/TV_main.c
	gcc -Wall -pedantic -ansi -c main/TV_main.c

atributo.o: productos/atributo.c
	gcc -Wall -pedantic -ansi -c productos/atributo.c

catalogo.o: productos/catalogo.c
	gcc -Wall -pedantic -ansi -c productos/catalogo.c

listaAtributos.o: productos/listaAtributos.c
	gcc -Wall -pedantic -ansi -c productos/listaAtributos.c

listaProductos.o: productos/listaProductos.c
	gcc -Wall -pedantic -ansi -c productos/listaProductos.c

producto.o: productos/producto.c
	gcc -Wall -pedantic -ansi -c productos/producto.c

TVirtual.o: tiendavirtual/TVirtual.c
	gcc -Wall -pedantic -ansi -c tiendavirtual/TVirtual.c

fecha.o: ventas/fecha.c
	gcc -Wall -pedantic -ansi -c ventas/fecha.c

listaVentas.o: ventas/listaVentas.c
	gcc -Wall -pedantic -ansi -c ventas/listaVentas.c

venta.o: ventas/venta.c
	gcc -Wall -pedantic -ansi -c ventas/venta.c

proyectointegrador_v3.exe: auxiliar.o cesta.o podCesta.o clientes.o listaClientes.o listaUsuarios.o solicitud.o accesoSistema.o menus.o TV_main.o atributo.o catalogo.o listaAtributos.o listaProductos.o producto.o TVirtual.o fecha.o listaVentas.o venta.o
	gcc auxiliar.o cesta.o podCesta.o clientes.o listaClientes.o listaUsuarios.o solicitud.o accesoSistema.o menus.o TV_main.o atributo.o catalogo.o listaAtributos.o listaProductos.o producto.o TVirtual.o fecha.o listaVentas.o venta.o -o proyectointegrador_v3.exe

clean:
	del auxiliar.o cesta.o podCesta.o clientes.o listaClientes.o listaUsuarios.o solicitud.o accesoSistema.o menus.o TV_main.o atributo.o catalogo.o listaAtributos.o listaProductos.o producto.o TVirtual.o fecha.o listaVentas.o venta.o proyectointegrador_v3.exe
